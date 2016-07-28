/********************************************************************************
** Form generated from reading UI file 'availability_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVAILABILITY_WINDOW_H
#define UI_AVAILABILITY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Availability_Window
{
public:
    QAction *actionE_xit;
    QWidget *centralWidget;
    QCalendarWidget *calendarWidget;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QGroupBox *groupBox;
    QPushButton *bartenderBtn;
    QPushButton *serverBtn;
    QPushButton *expoBtn;
    QPushButton *hostBtn;
    QPushButton *busBtn;
    QPushButton *managerBtn;
    QPushButton *Submit;
    QListWidget *listWidget_3;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *RemoveAMBtn;
    QPushButton *RemovePMBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Availability_Window)
    {
        if (Availability_Window->objectName().isEmpty())
            Availability_Window->setObjectName(QStringLiteral("Availability_Window"));
        Availability_Window->resize(885, 687);
        actionE_xit = new QAction(Availability_Window);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        centralWidget = new QWidget(Availability_Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 20, 591, 421));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(340, 470, 231, 131));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(50, 470, 221, 131));
        listWidget_2->setDragEnabled(true);
        listWidget_2->setDragDropOverwriteMode(true);
        listWidget_2->setDragDropMode(QAbstractItemView::DragDrop);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(640, 20, 201, 141));
        bartenderBtn = new QPushButton(groupBox);
        bartenderBtn->setObjectName(QStringLiteral("bartenderBtn"));
        bartenderBtn->setGeometry(QRect(10, 30, 75, 23));
        serverBtn = new QPushButton(groupBox);
        serverBtn->setObjectName(QStringLiteral("serverBtn"));
        serverBtn->setGeometry(QRect(110, 30, 75, 23));
        expoBtn = new QPushButton(groupBox);
        expoBtn->setObjectName(QStringLiteral("expoBtn"));
        expoBtn->setGeometry(QRect(10, 70, 75, 23));
        hostBtn = new QPushButton(groupBox);
        hostBtn->setObjectName(QStringLiteral("hostBtn"));
        hostBtn->setGeometry(QRect(110, 70, 75, 23));
        busBtn = new QPushButton(groupBox);
        busBtn->setObjectName(QStringLiteral("busBtn"));
        busBtn->setGeometry(QRect(10, 110, 75, 23));
        managerBtn = new QPushButton(groupBox);
        managerBtn->setObjectName(QStringLiteral("managerBtn"));
        managerBtn->setGeometry(QRect(110, 110, 75, 23));
        Submit = new QPushButton(centralWidget);
        Submit->setObjectName(QStringLiteral("Submit"));
        Submit->setGeometry(QRect(650, 510, 191, 61));
        listWidget_3 = new QListWidget(centralWidget);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(640, 170, 201, 301));
        listWidget_3->setDragEnabled(true);
        listWidget_3->setDragDropOverwriteMode(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 440, 91, 31));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 440, 91, 31));
        label_3->setFont(font);
        RemoveAMBtn = new QPushButton(centralWidget);
        RemoveAMBtn->setObjectName(QStringLiteral("RemoveAMBtn"));
        RemoveAMBtn->setGeometry(QRect(70, 600, 181, 31));
        RemovePMBtn = new QPushButton(centralWidget);
        RemovePMBtn->setObjectName(QStringLiteral("RemovePMBtn"));
        RemovePMBtn->setGeometry(QRect(370, 600, 191, 31));
        Availability_Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Availability_Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        Availability_Window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Availability_Window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Availability_Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Availability_Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Availability_Window->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionE_xit);

        retranslateUi(Availability_Window);
        QObject::connect(actionE_xit, SIGNAL(triggered()), Availability_Window, SLOT(close()));
        QObject::connect(calendarWidget, SIGNAL(selectionChanged()), Availability_Window, SLOT(update()));
        QObject::connect(bartenderBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(busBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(hostBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(expoBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(serverBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(managerBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(RemovePMBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(RemoveAMBtn, SIGNAL(clicked()), Availability_Window, SLOT(update()));
        QObject::connect(Submit, SIGNAL(clicked()), Availability_Window, SLOT(update()));

        QMetaObject::connectSlotsByName(Availability_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Availability_Window)
    {
        Availability_Window->setWindowTitle(QApplication::translate("Availability_Window", "Availabilty_Window", 0));
        actionE_xit->setText(QApplication::translate("Availability_Window", "E&xit", 0));
        groupBox->setTitle(QApplication::translate("Availability_Window", "Filter Workers ", 0));
        bartenderBtn->setText(QApplication::translate("Availability_Window", "Bartenders", 0));
        serverBtn->setText(QApplication::translate("Availability_Window", "Servers", 0));
        expoBtn->setText(QApplication::translate("Availability_Window", "Expo", 0));
        hostBtn->setText(QApplication::translate("Availability_Window", "Host", 0));
        busBtn->setText(QApplication::translate("Availability_Window", "Bus", 0));
        managerBtn->setText(QApplication::translate("Availability_Window", "Manager", 0));
        Submit->setText(QApplication::translate("Availability_Window", "Submit AVailability ", 0));
        label_2->setText(QApplication::translate("Availability_Window", "AM Shift ", 0));
        label_3->setText(QApplication::translate("Availability_Window", "PM Shift", 0));
        RemoveAMBtn->setText(QApplication::translate("Availability_Window", "Remove AM Employee", 0));
        RemovePMBtn->setText(QApplication::translate("Availability_Window", "Remove PM Employee", 0));
        menuFile->setTitle(QApplication::translate("Availability_Window", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class Availability_Window: public Ui_Availability_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVAILABILITY_WINDOW_H
