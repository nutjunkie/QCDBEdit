/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Thu Jul 4 14:21:54 2013
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionNew_Option;
    QAction *actionDelete_Selection;
    QAction *actionQuit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTableWidget *remTableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *editOptionButton;
    QPushButton *addOptionButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteOptionButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(768, 581);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew_Option = new QAction(MainWindow);
        actionNew_Option->setObjectName(QString::fromUtf8("actionNew_Option"));
        actionDelete_Selection = new QAction(MainWindow);
        actionDelete_Selection->setObjectName(QString::fromUtf8("actionDelete_Selection"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        remTableWidget = new QTableWidget(groupBox);
        if (remTableWidget->columnCount() < 5)
            remTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        remTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        remTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        remTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        remTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        remTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        remTableWidget->setObjectName(QString::fromUtf8("remTableWidget"));
        remTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        remTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        remTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        remTableWidget->setShowGrid(false);
        remTableWidget->setSortingEnabled(true);
        remTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        remTableWidget->horizontalHeader()->setStretchLastSection(true);
        remTableWidget->verticalHeader()->setVisible(true);

        horizontalLayout->addWidget(remTableWidget);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        editOptionButton = new QPushButton(centralwidget);
        editOptionButton->setObjectName(QString::fromUtf8("editOptionButton"));

        horizontalLayout_2->addWidget(editOptionButton);

        addOptionButton = new QPushButton(centralwidget);
        addOptionButton->setObjectName(QString::fromUtf8("addOptionButton"));

        horizontalLayout_2->addWidget(addOptionButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        deleteOptionButton = new QPushButton(centralwidget);
        deleteOptionButton->setObjectName(QString::fromUtf8("deleteOptionButton"));

        horizontalLayout_2->addWidget(deleteOptionButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 768, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionNew_Option->setText(QApplication::translate("MainWindow", "New Option", 0, QApplication::UnicodeUTF8));
        actionDelete_Selection->setText(QApplication::translate("MainWindow", "Delete Option", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Option List", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = remTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = remTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = remTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Values", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = remTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Data Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = remTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Widget", 0, QApplication::UnicodeUTF8));
        editOptionButton->setText(QApplication::translate("MainWindow", "Edit Option", 0, QApplication::UnicodeUTF8));
        addOptionButton->setText(QApplication::translate("MainWindow", "Add Option", 0, QApplication::UnicodeUTF8));
        deleteOptionButton->setText(QApplication::translate("MainWindow", "Delete Option", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
