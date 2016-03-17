/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionManually;
    QAction *actionQRCode;
    QAction *actionQRCodeFromFile;
    QAction *actionURI;
    QAction *actionDelete;
    QAction *actionEdit;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConnectISS;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionGeneralSettings;
    QAction *actionShare;
    QAction *actionReportBug;
    QAction *actionViewLog;
    QAction *actionTestLatency;
    QAction *actionTestAllLatency;
    QAction *actionImportGUIJson;
    QAction *actionFromConfigJson;
    QAction *actionSaveManually;
    QAction *actionMoveUp;
    QAction *actionMoveDown;
    QAction *actionShowFilterBar;
    QAction *actionExportGUIJson;
    QAction *actionScanQRCodeCapturer;
    QAction *actionForceConnect;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *filterLineEdit;
    QTableView *connectionView;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuAdd;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 480);
        MainWindow->setMinimumSize(QSize(400, 400));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/shadowsocks-qt5.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        actionManually = new QAction(MainWindow);
        actionManually->setObjectName(QStringLiteral("actionManually"));
        actionQRCode = new QAction(MainWindow);
        actionQRCode->setObjectName(QStringLiteral("actionQRCode"));
        actionQRCodeFromFile = new QAction(MainWindow);
        actionQRCodeFromFile->setObjectName(QStringLiteral("actionQRCodeFromFile"));
        QIcon icon1;
        QString iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQRCodeFromFile->setIcon(icon1);
        actionURI = new QAction(MainWindow);
        actionURI->setObjectName(QStringLiteral("actionURI"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon2;
        iconThemeName = QStringLiteral("list-remove");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionDelete->setIcon(icon2);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionConnectISS = new QAction(MainWindow);
        actionConnectISS->setObjectName(QStringLiteral("actionConnectISS"));
        QIcon iconSite;
        iconThemeName = QStringLiteral("ishadowsocks");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            iconSite = QIcon::fromTheme(iconThemeName);
        } else {
            iconSite.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::On);
        }
        actionConnectISS->setIcon(iconSite);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon3;
        iconThemeName = QStringLiteral("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQuit->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        iconThemeName = QStringLiteral("help-about");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAbout->setIcon(icon4);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionGeneralSettings = new QAction(MainWindow);
        actionGeneralSettings->setObjectName(QStringLiteral("actionGeneralSettings"));
        actionShare = new QAction(MainWindow);
        actionShare->setObjectName(QStringLiteral("actionShare"));
        actionReportBug = new QAction(MainWindow);
        actionReportBug->setObjectName(QStringLiteral("actionReportBug"));
        actionViewLog = new QAction(MainWindow);
        actionViewLog->setObjectName(QStringLiteral("actionViewLog"));
        actionTestLatency = new QAction(MainWindow);
        actionTestLatency->setObjectName(QStringLiteral("actionTestLatency"));
        actionTestAllLatency = new QAction(MainWindow);
        actionTestAllLatency->setObjectName(QStringLiteral("actionTestAllLatency"));
        actionImportGUIJson = new QAction(MainWindow);
        actionImportGUIJson->setObjectName(QStringLiteral("actionImportGUIJson"));
        actionFromConfigJson = new QAction(MainWindow);
        actionFromConfigJson->setObjectName(QStringLiteral("actionFromConfigJson"));
        actionFromConfigJson->setIcon(icon1);
        actionSaveManually = new QAction(MainWindow);
        actionSaveManually->setObjectName(QStringLiteral("actionSaveManually"));
        QIcon icon5;
        iconThemeName = QStringLiteral("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSaveManually->setIcon(icon5);
        actionMoveUp = new QAction(MainWindow);
        actionMoveUp->setObjectName(QStringLiteral("actionMoveUp"));
        QIcon icon6;
        iconThemeName = QStringLiteral("go-up");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionMoveUp->setIcon(icon6);
        actionMoveDown = new QAction(MainWindow);
        actionMoveDown->setObjectName(QStringLiteral("actionMoveDown"));
        QIcon icon7;
        iconThemeName = QStringLiteral("go-down");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionMoveDown->setIcon(icon7);
        actionShowFilterBar = new QAction(MainWindow);
        actionShowFilterBar->setObjectName(QStringLiteral("actionShowFilterBar"));
        actionShowFilterBar->setCheckable(true);
        actionShowFilterBar->setChecked(true);
        actionExportGUIJson = new QAction(MainWindow);
        actionExportGUIJson->setObjectName(QStringLiteral("actionExportGUIJson"));
        actionScanQRCodeCapturer = new QAction(MainWindow);
        actionScanQRCodeCapturer->setObjectName(QStringLiteral("actionScanQRCodeCapturer"));
        actionForceConnect = new QAction(MainWindow);
        actionForceConnect->setObjectName(QStringLiteral("actionForceConnect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filterLineEdit = new QLineEdit(centralWidget);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));
        filterLineEdit->setClearButtonEnabled(true);

        verticalLayout->addWidget(filterLineEdit);

        connectionView = new QTableView(centralWidget);
        connectionView->setObjectName(QStringLiteral("connectionView"));
        connectionView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        connectionView->setTabKeyNavigation(false);
        connectionView->setSelectionMode(QAbstractItemView::SingleSelection);
        connectionView->setSelectionBehavior(QAbstractItemView::SelectRows);
        connectionView->setShowGrid(false);
        connectionView->setSortingEnabled(true);
        connectionView->setWordWrap(false);
        connectionView->setCornerButtonEnabled(false);
        connectionView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(connectionView);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 30));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QStringLiteral("menuConnection"));
        menuAdd = new QMenu(menuConnection);
        menuAdd->setObjectName(QStringLiteral("menuAdd"));
        QIcon icon8;
        iconThemeName = QStringLiteral("list-add");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        menuAdd->setIcon(icon8);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionConnect);
        toolBar->addAction(actionDisconnect);
        toolBar->addAction(actionTestLatency);
        toolBar->addAction(actionConnectISS);
        toolBar->addSeparator();
        toolBar->addAction(actionEdit);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionShare);
        toolBar->addSeparator();
        toolBar->addAction(actionMoveUp);
        toolBar->addAction(actionMoveDown);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuConnection->addAction(menuAdd->menuAction());
        menuConnection->addAction(actionEdit);
        menuConnection->addAction(actionShare);
        menuConnection->addAction(actionDelete);
        menuConnection->addSeparator();
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionForceConnect);
        menuConnection->addAction(actionDisconnect);
        menuConnection->addAction(actionConnectISS);
        menuConnection->addAction(actionTestLatency);
        menuConnection->addAction(actionTestAllLatency);
        menuConnection->addSeparator();
        menuConnection->addAction(actionViewLog);
        menuConnection->addSeparator();
        menuConnection->addAction(actionMoveUp);
        menuConnection->addAction(actionMoveDown);
        menuAdd->addAction(actionManually);
        menuAdd->addAction(actionURI);
        menuAdd->addAction(actionQRCodeFromFile);
        menuAdd->addAction(actionQRCode);
        menuAdd->addAction(actionScanQRCodeCapturer);
        menuAdd->addAction(actionFromConfigJson);
        menuFile->addAction(actionImportGUIJson);
        menuFile->addAction(actionExportGUIJson);
        menuFile->addAction(actionSaveManually);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuSettings->addAction(actionGeneralSettings);
        menuSettings->addSeparator();
        menuSettings->addAction(actionShowFilterBar);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        menuHelp->addSeparator();
        menuHelp->addAction(actionReportBug);

        retranslateUi(MainWindow);
        QObject::connect(actionShowFilterBar, SIGNAL(toggled(bool)), filterLineEdit, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Connection Manager", 0));
        actionManually->setText(QApplication::translate("MainWindow", "&Manually", 0));
#ifndef QT_NO_TOOLTIP
        actionManually->setToolTip(QApplication::translate("MainWindow", "Add connection manually", 0));
#endif // QT_NO_TOOLTIP
        actionQRCode->setText(QApplication::translate("MainWindow", "&Scan QR Code on Screen", 0));
        actionQRCodeFromFile->setText(QApplication::translate("MainWindow", "&From QR Code Image File", 0));
#ifndef QT_NO_TOOLTIP
        actionQRCodeFromFile->setToolTip(QApplication::translate("MainWindow", "From QR code image file", 0));
#endif // QT_NO_TOOLTIP
        actionURI->setText(QApplication::translate("MainWindow", "&URI", 0));
#ifndef QT_NO_TOOLTIP
        actionURI->setToolTip(QApplication::translate("MainWindow", "Add connection from URI", 0));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindow", "&Delete", 0));
        actionEdit->setText(QApplication::translate("MainWindow", "&Edit", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "&Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "D&isconnect", 0));
        actionConnectISS->setText(QApplication::translate("MainWindow", "C&onnect ishadowsocks.net", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About &Qt", 0));
        actionGeneralSettings->setText(QApplication::translate("MainWindow", "&General Settings", 0));
        actionShare->setText(QApplication::translate("MainWindow", "&Share", 0));
        actionReportBug->setText(QApplication::translate("MainWindow", "&Report Bug", 0));
        actionViewLog->setText(QApplication::translate("MainWindow", "View &Log", 0));
        actionTestLatency->setText(QApplication::translate("MainWindow", "&Test Latency", 0));
#ifndef QT_NO_TOOLTIP
        actionTestLatency->setToolTip(QApplication::translate("MainWindow", "Test the latency of selected connection", 0));
#endif // QT_NO_TOOLTIP
        actionTestAllLatency->setText(QApplication::translate("MainWindow", "Test All C&onnections Latency", 0));
        actionImportGUIJson->setText(QApplication::translate("MainWindow", "&Import Connections from gui-config.json", 0));
#ifndef QT_NO_TOOLTIP
        actionImportGUIJson->setToolTip(QApplication::translate("MainWindow", "Import connections from old version configuration file", 0));
#endif // QT_NO_TOOLTIP
        actionFromConfigJson->setText(QApplication::translate("MainWindow", "From &config.json", 0));
        actionSaveManually->setText(QApplication::translate("MainWindow", "&Save Manually", 0));
        actionSaveManually->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionMoveUp->setText(QApplication::translate("MainWindow", "&Move Up", 0));
        actionMoveDown->setText(QApplication::translate("MainWindow", "Mo&ve Down", 0));
        actionShowFilterBar->setText(QApplication::translate("MainWindow", "&Show Filter Bar", 0));
        actionShowFilterBar->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        actionExportGUIJson->setText(QApplication::translate("MainWindow", "&Export as gui-config.json", 0));
        actionScanQRCodeCapturer->setText(QApplication::translate("MainWindow", "Scan &QR Code using Capturer", 0));
#ifndef QT_NO_TOOLTIP
        actionScanQRCodeCapturer->setToolTip(QApplication::translate("MainWindow", "Scan QR Code using Capturer", 0));
#endif // QT_NO_TOOLTIP
        actionForceConnect->setText(QApplication::translate("MainWindow", "Force Connect", 0));
#ifndef QT_NO_TOOLTIP
        actionForceConnect->setToolTip(QApplication::translate("MainWindow", "Connect to this connection and disconnect any connections currently using  the same local port", 0));
#endif // QT_NO_TOOLTIP
        filterLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Input to filter", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "Show Toolbar", 0));
        menuConnection->setTitle(QApplication::translate("MainWindow", "&Connection", 0));
        menuAdd->setTitle(QApplication::translate("MainWindow", "&Add", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settin&gs", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
