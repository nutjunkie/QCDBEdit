/********************************************************************************
** Form generated from reading ui file 'OptionListEditor.ui'
**
** Created: Thu Jul 4 14:21:54 2013
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPTIONLISTEDITOR_H
#define UI_OPTIONLISTEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionListEditor
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *optionList;
    QVBoxLayout *verticalLayout;
    QToolButton *addButton;
    QToolButton *upButton;
    QToolButton *downButton;
    QToolButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionListEditor)
    {
        if (OptionListEditor->objectName().isEmpty())
            OptionListEditor->setObjectName(QString::fromUtf8("OptionListEditor"));
        OptionListEditor->resize(271, 340);
        verticalLayout_3 = new QVBoxLayout(OptionListEditor);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(OptionListEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        optionList = new QListWidget(groupBox);
        optionList->setObjectName(QString::fromUtf8("optionList"));

        verticalLayout_2->addWidget(optionList);


        horizontalLayout->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addButton = new QToolButton(OptionListEditor);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/resources/icons/Add.png")), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(28, 28));

        verticalLayout->addWidget(addButton);

        upButton = new QToolButton(OptionListEditor);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/resources/icons/Up.png")), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon1);
        upButton->setIconSize(QSize(28, 28));

        verticalLayout->addWidget(upButton);

        downButton = new QToolButton(OptionListEditor);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/resources/icons/Down.png")), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon2);
        downButton->setIconSize(QSize(28, 28));

        verticalLayout->addWidget(downButton);

        deleteButton = new QToolButton(OptionListEditor);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/resources/icons/Delete.png")), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setIconSize(QSize(28, 28));

        verticalLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(OptionListEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(OptionListEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionListEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionListEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionListEditor);
    } // setupUi

    void retranslateUi(QDialog *OptionListEditor)
    {
        OptionListEditor->setWindowTitle(QApplication::translate("OptionListEditor", "Dialog", 0, QApplication::UnicodeUTF8));
        OptionListEditor->setStyleSheet(QApplication::translate("OptionListEditor", "QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 34px;\n"
"   max-width: 34px;\n"
"   min-height: 34px;\n"
"   max-height: 34px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
""
                        "          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   padding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 10px;\n"
"}", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OptionListEditor", "Options", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("OptionListEditor", "Add new value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        upButton->setToolTip(QApplication::translate("OptionListEditor", "Move value up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        upButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        downButton->setToolTip(QApplication::translate("OptionListEditor", "Move value down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        downButton->setText(QApplication::translate("OptionListEditor", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("OptionListEditor", "Delete selectd value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        Q_UNUSED(OptionListEditor);
    } // retranslateUi

};

namespace Ui {
    class OptionListEditor: public Ui_OptionListEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONLISTEDITOR_H
