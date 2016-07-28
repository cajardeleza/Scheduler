/********************************************************************************
** Form generated from reading UI file 'employee_calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_CALENDAR_H
#define UI_EMPLOYEE_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Employee_Calendar
{
public:
    QWidget *centralWidget;
    QCalendarWidget *calendarWidget;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *submitBtn;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Employee_Calendar)
    {
        if (Employee_Calendar->objectName().isEmpty())
            Employee_Calendar->setObjectName(QStringLiteral("Employee_Calendar"));
        Employee_Calendar->resize(930, 628);
        centralWidget = new QWidget(Employee_Calendar);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 100, 701, 471));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(750, 130, 151, 391));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(800, 100, 131, 20));
        submitBtn = new QPushButton(centralWidget);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        submitBtn->setGeometry(QRect(750, 530, 151, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 210, 321, 41));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(true);
        label_2->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(290, 250, 321, 61));
        QFont font1;
        font1.setPointSize(14);
        textEdit->setFont(font1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(290, 310, 321, 101));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 40, 511, 20));
        QFont font3;
        font3.setPointSize(17);
        label_3->setFont(font3);
        Employee_Calendar->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Employee_Calendar);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 21));
        Employee_Calendar->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Employee_Calendar);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Employee_Calendar->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Employee_Calendar);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Employee_Calendar->setStatusBar(statusBar);

        retranslateUi(Employee_Calendar);
        QObject::connect(calendarWidget, SIGNAL(selectionChanged()), Employee_Calendar, SLOT(update()));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), Employee_Calendar, SLOT(update()));
        QObject::connect(submitBtn, SIGNAL(clicked()), Employee_Calendar, SLOT(update()));
        QObject::connect(pushButton, SIGNAL(clicked()), Employee_Calendar, SLOT(update()));

        QMetaObject::connectSlotsByName(Employee_Calendar);
    } // setupUi

    void retranslateUi(QMainWindow *Employee_Calendar)
    {
        Employee_Calendar->setWindowTitle(QApplication::translate("Employee_Calendar", "Employee_Calendar", 0));
        label->setText(QApplication::translate("Employee_Calendar", "Off Days ", 0));
        submitBtn->setText(QApplication::translate("Employee_Calendar", "Submit Availablity", 0));
        label_2->setText(QApplication::translate("Employee_Calendar", "                          Enter ID", 0));
        pushButton->setText(QApplication::translate("Employee_Calendar", "Press to Continue", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Employee_Calendar: public Ui_Employee_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_CALENDAR_H
