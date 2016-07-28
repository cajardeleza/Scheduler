/********************************************************************************
** Form generated from reading UI file 'addnewemployee.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWEMPLOYEE_H
#define UI_ADDNEWEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewEmployee
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *txtFirstName;
    QTextEdit *txtLastName;
    QTextEdit *txtIdNum;
    QLabel *label_4;
    QComboBox *position_comboBox;
    QPushButton *submitBtn;
    QListWidget *listWidget;
    QPushButton *deleteBtn;

    void setupUi(QWidget *AddNewEmployee)
    {
        if (AddNewEmployee->objectName().isEmpty())
            AddNewEmployee->setObjectName(QStringLiteral("AddNewEmployee"));
        AddNewEmployee->resize(629, 378);
        label = new QLabel(AddNewEmployee);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 91, 21));
        label_2 = new QLabel(AddNewEmployee);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 91, 21));
        label_3 = new QLabel(AddNewEmployee);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 91, 21));
        txtFirstName = new QTextEdit(AddNewEmployee);
        txtFirstName->setObjectName(QStringLiteral("txtFirstName"));
        txtFirstName->setGeometry(QRect(90, 50, 191, 31));
        txtLastName = new QTextEdit(AddNewEmployee);
        txtLastName->setObjectName(QStringLiteral("txtLastName"));
        txtLastName->setGeometry(QRect(90, 90, 191, 31));
        txtIdNum = new QTextEdit(AddNewEmployee);
        txtIdNum->setObjectName(QStringLiteral("txtIdNum"));
        txtIdNum->setGeometry(QRect(90, 130, 191, 31));
        label_4 = new QLabel(AddNewEmployee);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 91, 21));
        position_comboBox = new QComboBox(AddNewEmployee);
        position_comboBox->setObjectName(QStringLiteral("position_comboBox"));
        position_comboBox->setGeometry(QRect(90, 170, 191, 22));
        submitBtn = new QPushButton(AddNewEmployee);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        submitBtn->setGeometry(QRect(90, 220, 191, 23));
        listWidget = new QListWidget(AddNewEmployee);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(320, 50, 256, 261));
        deleteBtn = new QPushButton(AddNewEmployee);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setGeometry(QRect(90, 260, 191, 23));

        retranslateUi(AddNewEmployee);
        QObject::connect(submitBtn, SIGNAL(clicked()), AddNewEmployee, SLOT(update()));
        QObject::connect(position_comboBox, SIGNAL(currentIndexChanged(QString)), AddNewEmployee, SLOT(update()));
        QObject::connect(deleteBtn, SIGNAL(clicked()), AddNewEmployee, SLOT(update()));
        QObject::connect(listWidget, SIGNAL(itemSelectionChanged()), AddNewEmployee, SLOT(update()));

        QMetaObject::connectSlotsByName(AddNewEmployee);
    } // setupUi

    void retranslateUi(QWidget *AddNewEmployee)
    {
        AddNewEmployee->setWindowTitle(QApplication::translate("AddNewEmployee", "AddNewEmployee", 0));
        label->setText(QApplication::translate("AddNewEmployee", "First Name:", 0));
        label_2->setText(QApplication::translate("AddNewEmployee", "Last Name:", 0));
        label_3->setText(QApplication::translate("AddNewEmployee", "ID number:", 0));
        label_4->setText(QApplication::translate("AddNewEmployee", "Position: ", 0));
        submitBtn->setText(QApplication::translate("AddNewEmployee", "Submit", 0));
        deleteBtn->setText(QApplication::translate("AddNewEmployee", "Delete Employee", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNewEmployee: public Ui_AddNewEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWEMPLOYEE_H
