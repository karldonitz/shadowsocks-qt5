/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QLabel *toolbarStyleLabel;
    QComboBox *toolbarStyleComboBox;
    QCheckBox *oneInstanceCheckBox;
    QCheckBox *hideCheckBox;
    QCheckBox *nativeMenuBarCheckBox;
    QLabel *labelFreeSite;
    QLineEdit *editFreeSite;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(340, 217);
        formLayout = new QFormLayout(SettingsDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(7, QFormLayout::SpanningRole, buttonBox);

        toolbarStyleLabel = new QLabel(SettingsDialog);
        toolbarStyleLabel->setObjectName(QStringLiteral("toolbarStyleLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toolbarStyleLabel);

        toolbarStyleComboBox = new QComboBox(SettingsDialog);
        toolbarStyleComboBox->setObjectName(QStringLiteral("toolbarStyleComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolbarStyleComboBox->sizePolicy().hasHeightForWidth());
        toolbarStyleComboBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, toolbarStyleComboBox);

        oneInstanceCheckBox = new QCheckBox(SettingsDialog);
        oneInstanceCheckBox->setObjectName(QStringLiteral("oneInstanceCheckBox"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, oneInstanceCheckBox);

        hideCheckBox = new QCheckBox(SettingsDialog);
        hideCheckBox->setObjectName(QStringLiteral("hideCheckBox"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, hideCheckBox);

        nativeMenuBarCheckBox = new QCheckBox(SettingsDialog);
        nativeMenuBarCheckBox->setObjectName(QStringLiteral("nativeMenuBarCheckBox"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, nativeMenuBarCheckBox);

        labelFreeSite = new QLabel(SettingsDialog);
        labelFreeSite->setObjectName(QStringLiteral("labelFreeSite"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelFreeSite);

        editFreeSite = new QLineEdit(SettingsDialog);
        editFreeSite->setObjectName(QStringLiteral("editFreeSite"));

        formLayout->setWidget(6, QFormLayout::FieldRole, editFreeSite);

        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "General Settings", 0));
        toolbarStyleLabel->setText(QApplication::translate("SettingsDialog", "Toolbar Style", 0));
        labelFreeSite->setText(QApplication::translate("SettingDialog", "Free Site", 0));
        toolbarStyleComboBox->clear();
        toolbarStyleComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "Icons Only", 0)
         << QApplication::translate("SettingsDialog", "Text Only", 0)
         << QApplication::translate("SettingsDialog", "Text Alongside Icons", 0)
         << QApplication::translate("SettingsDialog", "Text Under Icons", 0)
         << QApplication::translate("SettingsDialog", "System Style", 0)
        );
        oneInstanceCheckBox->setText(QApplication::translate("SettingsDialog", "Allow only one instance running", 0));
        hideCheckBox->setText(QApplication::translate("SettingsDialog", "Hide window on startup", 0));
#ifndef QT_NO_TOOLTIP
        nativeMenuBarCheckBox->setToolTip(QApplication::translate("SettingsDialog", "Need to restart the application for this change to take effect", 0));
#endif // QT_NO_TOOLTIP
        nativeMenuBarCheckBox->setText(QApplication::translate("SettingsDialog", "Use native menu bar", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
