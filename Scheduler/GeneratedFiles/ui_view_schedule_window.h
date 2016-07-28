/********************************************************************************
** Form generated from reading UI file 'view_schedule_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_SCHEDULE_WINDOW_H
#define UI_VIEW_SCHEDULE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View_Schedule_WIndow
{
public:
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *View_Schedule_WIndow)
    {
        if (View_Schedule_WIndow->objectName().isEmpty())
            View_Schedule_WIndow->setObjectName(QStringLiteral("View_Schedule_WIndow"));
        View_Schedule_WIndow->resize(400, 300);
        textEdit = new QTextEdit(View_Schedule_WIndow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(60, 80, 261, 161));
        label = new QLabel(View_Schedule_WIndow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 47, 13));

        retranslateUi(View_Schedule_WIndow);

        QMetaObject::connectSlotsByName(View_Schedule_WIndow);
    } // setupUi

    void retranslateUi(QWidget *View_Schedule_WIndow)
    {
        View_Schedule_WIndow->setWindowTitle(QApplication::translate("View_Schedule_WIndow", "View_Schedule_WIndow", 0));
        label->setText(QApplication::translate("View_Schedule_WIndow", "balls", 0));
    } // retranslateUi

};

namespace Ui {
    class View_Schedule_WIndow: public Ui_View_Schedule_WIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_SCHEDULE_WINDOW_H
