/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *editFrame;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *serverAddrLabel;
    QLineEdit *serverAddrEdit;
    QLabel *serverPortLabel;
    QLineEdit *serverPortEdit;
    QLabel *pwdLabel;
    QLineEdit *pwdEdit;
    QLabel *localAddrLabel;
    QLineEdit *localAddrEdit;
    QLabel *localPortLabel;
    QLineEdit *localPortEdit;
    QLabel *localServerTypeLabel;
    QHBoxLayout *localTypeHorizontalLayout;
    QRadioButton *socks5RadioButton;
    QRadioButton *httpRadioButton;
    QLabel *encryptLabel;
    QComboBox *encryptComboBox;
    QLabel *timeoutLabel;
    QSpinBox *timeoutSpinBox;
    QLabel *resetDateLabel;
    QDateEdit *resetDateEdit;
    QLabel *autoStartLabel;
    QCheckBox *autoStartCheckBox;
    QLabel *logLevelLabel;
    QCheckBox *debugCheckBox;
    QCheckBox *otaCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QStringLiteral("EditDialog"));
        EditDialog->resize(488, 510);
        verticalLayout = new QVBoxLayout(EditDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editFrame = new QFrame(EditDialog);
        editFrame->setObjectName(QStringLiteral("editFrame"));
        editFrame->setFrameShape(QFrame::StyledPanel);
        editFrame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(editFrame);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nameLabel = new QLabel(editFrame);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(editFrame);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        serverAddrLabel = new QLabel(editFrame);
        serverAddrLabel->setObjectName(QStringLiteral("serverAddrLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, serverAddrLabel);

        serverAddrEdit = new QLineEdit(editFrame);
        serverAddrEdit->setObjectName(QStringLiteral("serverAddrEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, serverAddrEdit);

        serverPortLabel = new QLabel(editFrame);
        serverPortLabel->setObjectName(QStringLiteral("serverPortLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, serverPortLabel);

        serverPortEdit = new QLineEdit(editFrame);
        serverPortEdit->setObjectName(QStringLiteral("serverPortEdit"));
        serverPortEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);

        formLayout->setWidget(2, QFormLayout::FieldRole, serverPortEdit);

        pwdLabel = new QLabel(editFrame);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, pwdLabel);

        pwdEdit = new QLineEdit(editFrame);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        //pwdEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, pwdEdit);

        localAddrLabel = new QLabel(editFrame);
        localAddrLabel->setObjectName(QStringLiteral("localAddrLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, localAddrLabel);

        localAddrEdit = new QLineEdit(editFrame);
        localAddrEdit->setObjectName(QStringLiteral("localAddrEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, localAddrEdit);

        localPortLabel = new QLabel(editFrame);
        localPortLabel->setObjectName(QStringLiteral("localPortLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, localPortLabel);

        localPortEdit = new QLineEdit(editFrame);
        localPortEdit->setObjectName(QStringLiteral("localPortEdit"));
        localPortEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);

        formLayout->setWidget(5, QFormLayout::FieldRole, localPortEdit);

        localServerTypeLabel = new QLabel(editFrame);
        localServerTypeLabel->setObjectName(QStringLiteral("localServerTypeLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, localServerTypeLabel);

        localTypeHorizontalLayout = new QHBoxLayout();
        localTypeHorizontalLayout->setObjectName(QStringLiteral("localTypeHorizontalLayout"));
        socks5RadioButton = new QRadioButton(editFrame);
        buttonGroup = new QButtonGroup(EditDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(socks5RadioButton);
        socks5RadioButton->setObjectName(QStringLiteral("socks5RadioButton"));
        socks5RadioButton->setText(QStringLiteral("SOCKS&5"));
        socks5RadioButton->setChecked(true);

        localTypeHorizontalLayout->addWidget(socks5RadioButton);

        httpRadioButton = new QRadioButton(editFrame);
        buttonGroup->addButton(httpRadioButton);
        httpRadioButton->setObjectName(QStringLiteral("httpRadioButton"));
        httpRadioButton->setText(QStringLiteral("HTTP(S)"));

        localTypeHorizontalLayout->addWidget(httpRadioButton);

        localTypeHorizontalLayout->setStretch(0, 1);
        localTypeHorizontalLayout->setStretch(1, 1);

        formLayout->setLayout(6, QFormLayout::FieldRole, localTypeHorizontalLayout);

        encryptLabel = new QLabel(editFrame);
        encryptLabel->setObjectName(QStringLiteral("encryptLabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, encryptLabel);

        encryptComboBox = new QComboBox(editFrame);
        encryptComboBox->setObjectName(QStringLiteral("encryptComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(encryptComboBox->sizePolicy().hasHeightForWidth());
        encryptComboBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(7, QFormLayout::FieldRole, encryptComboBox);

        timeoutLabel = new QLabel(editFrame);
        timeoutLabel->setObjectName(QStringLiteral("timeoutLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, timeoutLabel);

        timeoutSpinBox = new QSpinBox(editFrame);
        timeoutSpinBox->setObjectName(QStringLiteral("timeoutSpinBox"));
        sizePolicy.setHeightForWidth(timeoutSpinBox->sizePolicy().hasHeightForWidth());
        timeoutSpinBox->setSizePolicy(sizePolicy);
        timeoutSpinBox->setMinimum(10);
        timeoutSpinBox->setMaximum(3600);
        timeoutSpinBox->setSingleStep(10);
        timeoutSpinBox->setValue(60);

        formLayout->setWidget(9, QFormLayout::FieldRole, timeoutSpinBox);

        resetDateLabel = new QLabel(editFrame);
        resetDateLabel->setObjectName(QStringLiteral("resetDateLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, resetDateLabel);

        resetDateEdit = new QDateEdit(editFrame);
        resetDateEdit->setObjectName(QStringLiteral("resetDateEdit"));
        sizePolicy.setHeightForWidth(resetDateEdit->sizePolicy().hasHeightForWidth());
        resetDateEdit->setSizePolicy(sizePolicy);
        resetDateEdit->setCalendarPopup(true);

        formLayout->setWidget(10, QFormLayout::FieldRole, resetDateEdit);

        autoStartLabel = new QLabel(editFrame);
        autoStartLabel->setObjectName(QStringLiteral("autoStartLabel"));

        formLayout->setWidget(11, QFormLayout::LabelRole, autoStartLabel);

        autoStartCheckBox = new QCheckBox(editFrame);
        autoStartCheckBox->setObjectName(QStringLiteral("autoStartCheckBox"));
        sizePolicy.setHeightForWidth(autoStartCheckBox->sizePolicy().hasHeightForWidth());
        autoStartCheckBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(11, QFormLayout::FieldRole, autoStartCheckBox);

        logLevelLabel = new QLabel(editFrame);
        logLevelLabel->setObjectName(QStringLiteral("logLevelLabel"));

        formLayout->setWidget(12, QFormLayout::LabelRole, logLevelLabel);

        debugCheckBox = new QCheckBox(editFrame);
        debugCheckBox->setObjectName(QStringLiteral("debugCheckBox"));
        sizePolicy.setHeightForWidth(debugCheckBox->sizePolicy().hasHeightForWidth());
        debugCheckBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(12, QFormLayout::FieldRole, debugCheckBox);

        otaCheckBox = new QCheckBox(editFrame);
        otaCheckBox->setObjectName(QStringLiteral("otaCheckBox"));

        formLayout->setWidget(8, QFormLayout::FieldRole, otaCheckBox);


        verticalLayout->addWidget(editFrame);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(nameEdit, serverAddrEdit);
        QWidget::setTabOrder(serverAddrEdit, serverPortEdit);
        QWidget::setTabOrder(serverPortEdit, pwdEdit);
        QWidget::setTabOrder(pwdEdit, localAddrEdit);
        QWidget::setTabOrder(localAddrEdit, localPortEdit);
        QWidget::setTabOrder(localPortEdit, socks5RadioButton);
        QWidget::setTabOrder(socks5RadioButton, httpRadioButton);
        QWidget::setTabOrder(httpRadioButton, encryptComboBox);
        QWidget::setTabOrder(encryptComboBox, otaCheckBox);
        QWidget::setTabOrder(otaCheckBox, timeoutSpinBox);
        QWidget::setTabOrder(timeoutSpinBox, resetDateEdit);
        QWidget::setTabOrder(resetDateEdit, autoStartCheckBox);
        QWidget::setTabOrder(autoStartCheckBox, debugCheckBox);

        retranslateUi(EditDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), EditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Profile Editor", 0));
        nameLabel->setText(QApplication::translate("EditDialog", "Profile Name", 0));
        serverAddrLabel->setText(QApplication::translate("EditDialog", "Server Address", 0));
        serverPortLabel->setText(QApplication::translate("EditDialog", "Server Port", 0));
        pwdLabel->setText(QApplication::translate("EditDialog", "Password", 0));
        localAddrLabel->setText(QApplication::translate("EditDialog", "Local Address", 0));
        localPortLabel->setText(QApplication::translate("EditDialog", "Local Port", 0));
        localServerTypeLabel->setText(QApplication::translate("EditDialog", "Local Server Type", 0));
        encryptLabel->setText(QApplication::translate("EditDialog", "Encryption Method", 0));
        timeoutLabel->setText(QApplication::translate("EditDialog", "Timeout", 0));
        resetDateLabel->setText(QApplication::translate("EditDialog", "Reset Data Usage after", 0));
        autoStartLabel->setText(QApplication::translate("EditDialog", "Automation", 0));
        autoStartCheckBox->setText(QApplication::translate("EditDialog", "Auto connect on application start", 0));
        logLevelLabel->setText(QApplication::translate("EditDialog", "Log Level", 0));
        debugCheckBox->setText(QApplication::translate("EditDialog", "Debug", 0));
#ifndef QT_NO_TOOLTIP
        otaCheckBox->setToolTip(QApplication::translate("EditDialog", "Turn on one-time authentication and header verification (need server support)", 0));
#endif // QT_NO_TOOLTIP
        otaCheckBox->setText(QApplication::translate("EditDialog", "One-time authentication", 0));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
