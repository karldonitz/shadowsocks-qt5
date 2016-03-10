#include "connectiontablemodel.h"
#include <QMessageBox>
ConnectionTableModel::ConnectionTableModel(QObject *parent) :
    QAbstractTableModel(parent), latencyBest(1e6)
{}

ConnectionTableModel::~ConnectionTableModel()
{}

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
    for (int i = 0; i < rowCount(); ++i) {
        Connection *con = getItem(i)->getConnection();
        QString serverName = con->getName();
        int indexStart = msg.indexOf(serverName);
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
        con->updateProfile(password, (quint16)serverPort, method);
    }
    testAllLatency();
}

QString ConnectionTableModel::findFirstTagValue(QString msg, int indexStart, QString label)
{
    indexStart = msg.indexOf(label, indexStart)+label.length();
    int indexStop = msg.indexOf(tr("<"), indexStart);
    return msg.mid(indexStart, indexStop - indexStart);
}

void ConnectionTableModel::testAllLatency()
{
    latencyBest = 1e6;
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
    if (latency>0)
    {
        if(latency < latencyBest)
        {
            latencyBest = latency;
            if(!con->isRunning())
            {
                for(auto *item : items)
                {
                    if(item->getConnection()->isRunning())
                        item->getConnection()->stop();
                }
                con->start();
            }
        }
    }
    emit dataChanged(this->index(row, 3), this->index(row, 3));
}
