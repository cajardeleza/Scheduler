/********************************************************************************
** Form generated from reading UI file 'manager_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_WINDOW_H
#define UI_MANAGER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manager_window
{
public:
    QWidget *centralWidget;
    QPushButton *newEmployeeBtn;
    QPushButton *scheduleBtn;
    QPushButton *availabilityBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *manager_window)
    {
        if (manager_window->objectName().isEmpty())
            manager_window->setObjectName(QStringLiteral("manager_window"));
        manager_window->resize(692, 244);
        centralWidget = new QWidget(manager_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        newEmployeeBtn = new QPushButton(centralWidget);
        newEmployeeBtn->setObjectName(QStringLiteral("newEmployeeBtn"));
        newEmployeeBtn->setGeometry(QRect(20, 30, 211, 151));
        scheduleBtn = new QPushButton(centralWidget);
        scheduleBtn->setObjectName(QStringLiteral("scheduleBtn"));
        scheduleBtn->setGeometry(QRect(460, 30, 211, 151));
        availabilityBtn = new QPushButton(centralWidget);
        availabilityBtn->setObjectName(QStringLiteral("availabilityBtn"));
        availabilityBtn->setGeometry(QRect(250, 30, 191, 151));
        manager_window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(manager_window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 692, 21));
        manager_window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(manager_window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        manager_window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(manager_window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        manager_window->setStatusBar(statusBar);

        retranslateUi(manager_window);
        QObject::connect(newEmployeeBtn, SIGNAL(clicked()), newEmployeeBtn, SLOT(show()));
        QObject::connect(scheduleBtn, SIGNAL(clicked()), scheduleBtn, SLOT(show()));
        QObject::connect(availabilityBtn, SIGNAL(clicked()), availabilityBtn, SLOT(show()));

        QMetaObject::connectSlotsByName(manager_window);
    } // setupUi

    void retranslateUi(QMainWindow *manager_window)
    {
        manager_window->setWindowTitle(QApplication::translate("manager_window", "manager_window", 0));
        newEmployeeBtn->setText(QApplication::translate("manager_window", "Add New Employee", 0));
        scheduleBtn->setText(QApplication::translate("manager_window", "View/Edit Schedule", 0));
        availabilityBtn->setText(QApplication::translate("manager_window", "Availabilty", 0));
    } // retranslateUi

};

namespace Ui {
    class manager_window: public Ui_manager_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_WINDOW_H
