/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QListWidget *listWidget_2;
    QPushButton *pushButton_7;
    QListWidget *listWidget;
    QListView *listView;

    void setupUi(QWidget *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QStringLiteral("Calendar"));
        Calendar->resize(812, 605);
        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 20, 531, 401));
        groupBox = new QGroupBox(Calendar);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(580, 20, 201, 141));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 30, 75, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 70, 75, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 70, 75, 23));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 110, 75, 23));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 110, 75, 23));
        label = new QLabel(Calendar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 470, 181, 31));
        listWidget_2 = new QListWidget(Calendar);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(20, 450, 251, 131));
        listWidget_2->setDragEnabled(true);
        listWidget_2->setDragDropOverwriteMode(true);
        listWidget_2->setDragDropMode(QAbstractItemView::DragDrop);
        pushButton_7 = new QPushButton(Calendar);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 510, 191, 41));
        listWidget = new QListWidget(Calendar);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(300, 450, 251, 131));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listView = new QListView(Calendar);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(580, 160, 201, 261));
        listView->setDragEnabled(true);
        listView->setDragDropOverwriteMode(true);
        listView->setDragDropMode(QAbstractItemView::DragDrop);

        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QWidget *Calendar)
    {
        Calendar->setWindowTitle(QApplication::translate("Calendar", "Calendar", 0));
        groupBox->setTitle(QApplication::translate("Calendar", "GroupBox", 0));
        pushButton->setText(QApplication::translate("Calendar", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Calendar", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Calendar", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Calendar", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Calendar", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("Calendar", "PushButton", 0));
        label->setText(QApplication::translate("Calendar", "TextLabel", 0));
        pushButton_7->setText(QApplication::translate("Calendar", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
