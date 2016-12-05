/********************************************************************************
** Form generated from reading ui file 'OptionNumberEditor.ui'
**
** Created: Thu Jul 4 14:21:54 2013
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPTIONNUMBEREDITOR_H
#define UI_OPTIONNUMBEREDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionNumberEditor
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *minimumLineEdit;
    QLabel *label_2;
    QLineEdit *maximumLineEdit;
    QLabel *label_3;
    QLineEdit *defaultLineEdit;
    QLabel *label_4;
    QLineEdit *stepSizeLineEdit;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionNumberEditor)
    {
        if (OptionNumberEditor->objectName().isEmpty())
            OptionNumberEditor->setObjectName(QString::fromUtf8("OptionNumberEditor"));
        OptionNumberEditor->resize(193, 222);
        verticalLayout = new QVBoxLayout(OptionNumberEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(OptionNumberEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        minimumLineEdit = new QLineEdit(OptionNumberEditor);
        minimumLineEdit->setObjectName(QString::fromUtf8("minimumLineEdit"));

        gridLayout->addWidget(minimumLineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(OptionNumberEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        maximumLineEdit = new QLineEdit(OptionNumberEditor);
        maximumLineEdit->setObjectName(QString::fromUtf8("maximumLineEdit"));

        gridLayout->addWidget(maximumLineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(OptionNumberEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        defaultLineEdit = new QLineEdit(OptionNumberEditor);
        defaultLineEdit->setObjectName(QString::fromUtf8("defaultLineEdit"));

        gridLayout->addWidget(defaultLineEdit, 3, 1, 1, 1);

        label_4 = new QLabel(OptionNumberEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        stepSizeLineEdit = new QLineEdit(OptionNumberEditor);
        stepSizeLineEdit->setObjectName(QString::fromUtf8("stepSizeLineEdit"));

        gridLayout->addWidget(stepSizeLineEdit, 4, 1, 1, 1);

        label_5 = new QLabel(OptionNumberEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(OptionNumberEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OptionNumberEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionNumberEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionNumberEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionNumberEditor);
    } // setupUi

    void retranslateUi(QDialog *OptionNumberEditor)
    {
        OptionNumberEditor->setWindowTitle(QApplication::translate("OptionNumberEditor", "Edit Numerical Limits", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionNumberEditor", "Minimum", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OptionNumberEditor", "Maximum", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OptionNumberEditor", "Default", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OptionNumberEditor", "Step Size", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OptionNumberEditor", "Variable Parameters:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OptionNumberEditor);
    } // retranslateUi

};

namespace Ui {
    class OptionNumberEditor: public Ui_OptionNumberEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONNUMBEREDITOR_H
