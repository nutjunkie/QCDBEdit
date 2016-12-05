/********************************************************************************
** Form generated from reading ui file 'EditOptionDialog.ui'
**
** Created: Thu Jul 4 14:21:54 2013
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EDITOPTIONDIALOG_H
#define UI_EDITOPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QLabel *label_4;
    QComboBox *dataTypeCombo;
    QComboBox *optionsCombo;
    QLabel *label_5;
    QComboBox *widgetCombo;
    QPushButton *editOptionsButton;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    QTextEdit *documentationText;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QString::fromUtf8("OptionDialog"));
        OptionDialog->resize(478, 540);
        verticalLayout = new QVBoxLayout(OptionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameLineEdit = new QLineEdit(OptionDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 2);

        label = new QLabel(OptionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(OptionDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dataTypeCombo = new QComboBox(OptionDialog);
        dataTypeCombo->setObjectName(QString::fromUtf8("dataTypeCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dataTypeCombo->sizePolicy().hasHeightForWidth());
        dataTypeCombo->setSizePolicy(sizePolicy1);
        dataTypeCombo->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(dataTypeCombo, 1, 1, 1, 1);

        optionsCombo = new QComboBox(OptionDialog);
        optionsCombo->setObjectName(QString::fromUtf8("optionsCombo"));
        sizePolicy1.setHeightForWidth(optionsCombo->sizePolicy().hasHeightForWidth());
        optionsCombo->setSizePolicy(sizePolicy1);
        optionsCombo->setMinimumSize(QSize(150, 0));
        optionsCombo->setEditable(false);

        gridLayout->addWidget(optionsCombo, 3, 1, 1, 1);

        label_5 = new QLabel(OptionDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        widgetCombo = new QComboBox(OptionDialog);
        widgetCombo->setObjectName(QString::fromUtf8("widgetCombo"));
        sizePolicy1.setHeightForWidth(widgetCombo->sizePolicy().hasHeightForWidth());
        widgetCombo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(widgetCombo, 2, 1, 1, 1);

        editOptionsButton = new QPushButton(OptionDialog);
        editOptionsButton->setObjectName(QString::fromUtf8("editOptionsButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editOptionsButton->sizePolicy().hasHeightForWidth());
        editOptionsButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(editOptionsButton, 3, 2, 1, 1);

        label_2 = new QLabel(OptionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox = new QGroupBox(OptionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(300, 250));
        vboxLayout = new QVBoxLayout(groupBox);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        documentationText = new QTextEdit(groupBox);
        documentationText->setObjectName(QString::fromUtf8("documentationText"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(documentationText->sizePolicy().hasHeightForWidth());
        documentationText->setSizePolicy(sizePolicy4);

        vboxLayout->addWidget(documentationText);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionDialog", "Data Type", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionDialog", "Default", 0, QApplication::UnicodeUTF8));
        dataTypeCombo->clear();
        dataTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("OptionDialog", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Logical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "String", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Array", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        optionsCombo->setToolTip(QApplication::translate("OptionDialog", "Note that for numerical values the numbers\n"
"are in the order minimim, maximum, default\n"
"and step size (how much the spin controller\n"
"increases for each step).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("OptionDialog", "Widget", 0, QApplication::UnicodeUTF8));
        widgetCombo->clear();
        widgetCombo->insertItems(0, QStringList()
         << QApplication::translate("OptionDialog", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Combo box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Check box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Line edit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Spin box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Double spin box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OptionDialog", "Radio button", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        widgetCombo->setToolTip(QApplication::translate("OptionDialog", "This is the control widget associated with the options.  \n"
"Note that changing the Data Type control will update \n"
"this to the most appropriate control.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editOptionsButton->setText(QApplication::translate("OptionDialog", "Edit Options", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionDialog", "Name", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OptionDialog", "Documentation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        documentationText->setToolTip(QApplication::translate("OptionDialog", "This text box supports the use of html tags\n"
"e.g. <b>bold text </b>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Q_UNUSED(OptionDialog);
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOPTIONDIALOG_H
