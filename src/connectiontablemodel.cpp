#include "connectiontablemodel.h"
#include <QMessageBox>
#include <QtNetwork>
#include <QChar>

#if defined(WIN32)
   QString parameter = "-n 1";
#else
   QString parameter = "-c 1";
#endif

ConnectionTableModel::ConnectionTableModel(QObject *parent) :
    QAbstractTableModel(parent), latencyBest(1e9),
    isValidServer(false)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(keepOnline()));
    timer->start(1000*60*5);
#ifndef QT_NO_SSL
    connect(&qnam, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(sslErrors(QNetworkReply*,QList<QSslError>)));
#endif
}

ConnectionTableModel::~ConnectionTableModel()
{
    if(timer->isActive())
        timer->stop();
}

ConnectionItem *ConnectionTableModel::getItem(const int &row) const
{
    return items.at(row);
}

int ConnectionTableModel::rowCount(const QModelIndex &) const
{
    return items.count();
}

int ConnectionTableModel::columnCount(const QModelIndex &) const
{
    return ConnectionItem::columnCount();
}

QVariant ConnectionTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    ConnectionItem *item = getItem(index.row());
    return item->data(index.column(), role);
}

QVariant ConnectionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical || role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return QVariant(tr("Name"));
    case 1:
        return QVariant(tr("Server"));
    case 2:
        return QVariant(tr("Status"));
    case 3:
        return QVariant(tr("Latency"));
    case 4:
        return QVariant(tr("Local Port"));
    case 5:
        return QVariant(tr("Term Usage"));
    case 6:
        return QVariant(tr("Total Usage"));
    case 7:
        return QVariant(tr("Reset Date"));
    case 8:
        return QVariant(tr("Last Used"));
    default:
        return QVariant();
    }
}

QModelIndex ConnectionTableModel::index(int row, int column, const QModelIndex &) const
{
    if (row < 0 || row >= items.size()) {
        return QModelIndex();
    } else {
        ConnectionItem* item = items.at(row);
        return createIndex(row, column, item);//column is ignored (all columns have the same effect)
    }
}

bool ConnectionTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || count <= 0 || count + row > items.count()) {
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    items.erase(items.begin() + row, items.begin() + row + count);
    endRemoveRows();
    return true;
}

bool ConnectionTableModel::move(int row, int target, const QModelIndex &parent)
{
    if (row < 0 || row >= rowCount() || target < 0 || target >= rowCount() || row == target) {
        return false;
    }

    //http://doc.qt.io/qt-5/qabstractitemmodel.html#beginMoveRows
    int movTarget = target;
    if (target - row > 0) {
        movTarget++;
    }
    beginMoveRows(parent, row, row, parent, movTarget);
    items.move(row, target);
    endMoveRows();
    return true;
}

bool ConnectionTableModel::appendConnection(Connection *con, const QModelIndex &parent)
{
    ConnectionItem* newItem = new ConnectionItem(con, this);
    connect(newItem, &ConnectionItem::message, this, &ConnectionTableModel::message);
    connect(newItem, &ConnectionItem::stateChanged, this, &ConnectionTableModel::onConnectionStateChanged);
    connect(newItem, &ConnectionItem::latencyChanged, this, &ConnectionTableModel::onConnectionLatencyChanged);
    beginInsertRows(parent, items.count(), items.count() + 1);
    items.append(newItem);
    endInsertRows();
    return true;
}

void ConnectionTableModel::disconnectConnectionsAt(const QString &addr, quint16 port)
{
    bool anyAddr = (addr.compare("0.0.0.0") == 0);
    for (auto &i : items) {
        Connection *con = i->getConnection();
        if (con->isRunning() && con->getProfile().localPort == port) {
            if ((con->getProfile().localAddress == addr) ||
                (con->getProfile().localAddress.compare("0.0.0.0") == 0) ||
                anyAddr) {
                con->stop();
            }
        }
    }
}

void ConnectionTableModel::updateItems(QString msg)
{
    msg = msg.toLower();
    for (int i = 0; i < rowCount(); ++i) {
        Connection *con = getItem(i)->getConnection();
        QString serverName = con->getName();
        int indexStart = msg.indexOf(serverName);
        QString serverAddr = findFirstTagValue(msg, indexStart, serverName);
        QString label = tr("密码:");
        QString password = findFirstTagValue(msg, indexStart, label);
        //QMessageBox::information(, label, password);
        label = tr("端口:");
        QString port = findFirstTagValue(msg, indexStart, label);
        bool ok = false;
        uint serverPort = port.toUInt(&ok);
        if (!ok)
            return;
        //QMessageBox::information(this, label, port);
        label = tr("加密方式:");
        QString method = findFirstTagValue(msg, indexStart, label);
        //QMessageBox::information(this, label, method);
        con->updateProfile(serverAddr, password, (quint16)serverPort, method);
    }
    isValidServer = true;
    emit message(tr("Server information updated."));
}

QString ConnectionTableModel::findFirstTagValue(QString msg, int indexStart, QString label)
{
    indexStart = msg.indexOf(label, indexStart)+label.length();
    int indexStop = msg.indexOf(tr("<"), indexStart);
    QString value = msg.mid(indexStart, indexStop - indexStart);
    for(int i=0; i<value.size(); i++){
        QChar charNow = value.at(i);
        if(!charNow.isLetterOrNumber() && charNow!=QChar('-') && charNow!=QChar('.'))
        {
            value.remove(charNow);
        }
    }
    return value;
}

void ConnectionTableModel::testAllLatency()
{
    for (auto &i : items) {
        i->testLatency();
    }
}

void ConnectionTableModel::onConnectionStateChanged(bool running)
{
    ConnectionItem *item = qobject_cast<ConnectionItem*>(sender());
    int row = items.indexOf(item);
    emit dataChanged(this->index(row, 0),
                     this->index(row, ConnectionItem::columnCount() - 1));
    emit rowStatusChanged(row, running);
}

void ConnectionTableModel::onConnectionLatencyChanged()
{
    ConnectionItem *item = qobject_cast<ConnectionItem*>(sender());
    int row = items.indexOf(item);
    Connection *con = item->getConnection();
    int latency = con->getLatency();
    qDebug()<<con->getName()<<"latency test value:"<<latency;
    if (latency>0)
    {
        latencyBest = latency;
        if(!con->isRunning() && latency < latencyBest)
        {
            for(auto *item : items)
                if(item->getConnection()->isRunning())
                    item->getConnection()->stop();
            con->start();
        }
    }
    emit dataChanged(this->index(row, 3), this->index(row, 3));
}

void ConnectionTableModel::keepOnline()
{
    /*QString hostName = "8.8.8.8";
    int exitCode = QProcess::execute("ping", QStringList() << parameter << hostName);
    if (exitCode==0) {
        isValidServer = true;
    } else {
        isValidServer = false;
        emit message("ping 8.8.8.8 failed!");
    }*/
    QTime now = QTime::currentTime();
    if (((now.hour()/6))==0 && now.minute()<10)
        isValidServer = false;
    if (!isValidServer){
        getIShadowSocksServers();
    }
    bool isAllDisconnect = true;
    for (auto &item : items) {
        Connection *con = item->getConnection();
        if (con->isRunning()) {
            isAllDisconnect = false;
            break;
        }
    }
    qDebug()<<now<<": "<<"All disconnect? "<<isAllDisconnect;
    if (isAllDisconnect)
        testAllLatency();
}


void ConnectionTableModel::getIShadowSocksServers()
{
    QUrl url = freeSite;
    QByteArray postData;
    postData.append("");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "'User-Agent':'Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)'");
    request.setUrl(url);
    reply = qnam.get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(onHttpFinished()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(onHttpReadyRead()));
    emit message(tr("Tring to connect ")+freeSite);
    //qnam.post(request, postData);
}

void ConnectionTableModel::onHttpFinished()
{
    QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (reply->error() || !redirectionTarget.isNull()) {
        emit message(tr("Can't touch ")+freeSite);
    }

    reply->deleteLater();
    reply = 0;
}

void ConnectionTableModel::onHttpReadyRead()
{
    QString strResponse;
    strResponse.prepend(reply->readAll());
    if (strResponse.isNull())
        return;
    //取出section with id=free
    int indexSessionStart = strResponse.indexOf(tr("id=\"free\""));
    if (indexSessionStart < 0)
        return;
    strResponse = strResponse.mid(indexSessionStart);
    int indexSessionStop = strResponse.indexOf(tr("id=\"purchase\""));
    if (indexSessionStop < 0)
        return;
    strResponse = strResponse.mid(0, indexSessionStop);
    if (strResponse.isNull())
        return;
    updateItems(strResponse);
}

void ConnectionTableModel::setFreeSite(const QString freeSite)
{
    this->freeSite = freeSite;
}


#ifndef QT_NO_SSL
void ConnectionTableModel::sslErrors(QNetworkReply*,const QList<QSslError> &errors)
{
    QString errorString;
    foreach (const QSslError &error, errors) {
        if (!errorString.isEmpty())
            errorString += ", ";
        errorString += error.errorString();
    }

    reply->ignoreSslErrors();
}
#endif
