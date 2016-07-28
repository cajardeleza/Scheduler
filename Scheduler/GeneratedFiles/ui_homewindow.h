/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *loginBtn;
    QTextEdit *txtFirstName;
    QTextEdit *userPassword;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *txtLastName;
    QMenuBar *menuBar;
    QMenu *menuF_ile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HomeWindowClass)
    {
        if (HomeWindowClass->objectName().isEmpty())
            HomeWindowClass->setObjectName(QStringLiteral("HomeWindowClass"));
        HomeWindowClass->resize(388, 337);
        centralWidget = new QWidget(HomeWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(30, 220, 331, 41));
        txtFirstName = new QTextEdit(centralWidget);
        txtFirstName->setObjectName(QStringLiteral("txtFirstName"));
        txtFirstName->setGeometry(QRect(150, 20, 191, 31));
        userPassword = new QTextEdit(centralWidget);
        userPassword->setObjectName(QStringLiteral("userPassword"));
        userPassword->setGeometry(QRect(150, 160, 191, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 91, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 160, 91, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 100, 91, 20));
        txtLastName = new QTextEdit(centralWidget);
        txtLastName->setObjectName(QStringLiteral("txtLastName"));
        txtLastName->setGeometry(QRect(150, 90, 191, 31));
        HomeWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HomeWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 388, 21));
        menuF_ile = new QMenu(menuBar);
        menuF_ile->setObjectName(QStringLiteral("menuF_ile"));
        HomeWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HomeWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HomeWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HomeWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HomeWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuF_ile->menuAction());

        retranslateUi(HomeWindowClass);
        QObject::connect(loginBtn, SIGNAL(clicked()), HomeWindowClass, SLOT(update()));

        QMetaObject::connectSlotsByName(HomeWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindowClass)
    {
        HomeWindowClass->setWindowTitle(QApplication::translate("HomeWindowClass", "HomeWindow", 0));
        loginBtn->setText(QApplication::translate("HomeWindowClass", "Submit", 0));
        label->setText(QApplication::translate("HomeWindowClass", "First Name ", 0));
        label_2->setText(QApplication::translate("HomeWindowClass", "ID Number", 0));
        label_3->setText(QApplication::translate("HomeWindowClass", "Last Name", 0));
        menuF_ile->setTitle(QApplication::translate("HomeWindowClass", "F&ile", 0));
    } // retranslateUi

};

namespace Ui {
    class HomeWindowClass: public Ui_HomeWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
