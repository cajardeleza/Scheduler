/********************************************************************************
** Form generated from reading UI file 'employee_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_WINDOW_H
#define UI_EMPLOYEE_WINDOW_H

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

class Ui_Employee_Window
{
public:
    QWidget *centralWidget;
    QPushButton *availabilityBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Employee_Window)
    {
        if (Employee_Window->objectName().isEmpty())
            Employee_Window->setObjectName(QStringLiteral("Employee_Window"));
        Employee_Window->resize(549, 251);
        centralWidget = new QWidget(Employee_Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        availabilityBtn = new QPushButton(centralWidget);
        availabilityBtn->setObjectName(QStringLiteral("availabilityBtn"));
        availabilityBtn->setGeometry(QRect(170, 40, 201, 121));
        Employee_Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Employee_Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 549, 21));
        Employee_Window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Employee_Window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Employee_Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Employee_Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Employee_Window->setStatusBar(statusBar);

        retranslateUi(Employee_Window);
        QObject::connect(availabilityBtn, SIGNAL(clicked()), Employee_Window, SLOT(update()));

        QMetaObject::connectSlotsByName(Employee_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Employee_Window)
    {
        Employee_Window->setWindowTitle(QApplication::translate("Employee_Window", "Employee_Window", 0));
        availabilityBtn->setText(QApplication::translate("Employee_Window", "Update Availability", 0));
    } // retranslateUi

};

namespace Ui {
    class Employee_Window: public Ui_Employee_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_WINDOW_H
