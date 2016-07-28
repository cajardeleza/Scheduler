/********************************************************************************
** Form generated from reading UI file 'view_schedule.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_SCHEDULE_H
#define UI_VIEW_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View_Schedule
{
public:
    QAction *actionPrint;
    QAction *actionConvert_to_Excel;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QPushButton *viewScheduleBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *View_Schedule)
    {
        if (View_Schedule->objectName().isEmpty())
            View_Schedule->setObjectName(QStringLiteral("View_Schedule"));
        View_Schedule->resize(1147, 557);
        actionPrint = new QAction(View_Schedule);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionConvert_to_Excel = new QAction(View_Schedule);
        actionConvert_to_Excel->setObjectName(QStringLiteral("actionConvert_to_Excel"));
        centralWidget = new QWidget(View_Schedule);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(320, 10, 811, 491));
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(8);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 290, 271, 31));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 351, 271, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 270, 211, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 330, 211, 16));
        label_2->setFont(font);
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(10, 10, 291, 231));
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        viewScheduleBtn = new QPushButton(centralWidget);
        viewScheduleBtn->setObjectName(QStringLiteral("viewScheduleBtn"));
        viewScheduleBtn->setGeometry(QRect(20, 410, 271, 61));
        viewScheduleBtn->setFont(font);
        View_Schedule->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(View_Schedule);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1147, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        View_Schedule->setMenuBar(menuBar);
        mainToolBar = new QToolBar(View_Schedule);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        View_Schedule->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(View_Schedule);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        View_Schedule->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionConvert_to_Excel);

        retranslateUi(View_Schedule);
        QObject::connect(viewScheduleBtn, SIGNAL(clicked()), View_Schedule, SLOT(update()));
        QObject::connect(actionConvert_to_Excel, SIGNAL(triggered()), View_Schedule, SLOT(update()));

        QMetaObject::connectSlotsByName(View_Schedule);
    } // setupUi

    void retranslateUi(QMainWindow *View_Schedule)
    {
        View_Schedule->setWindowTitle(QApplication::translate("View_Schedule", "View_Schedule", 0));
        actionPrint->setText(QApplication::translate("View_Schedule", "Convert to Excel File", 0));
        actionConvert_to_Excel->setText(QApplication::translate("View_Schedule", "Convert to Excel", 0));
        label->setText(QApplication::translate("View_Schedule", "Select Month", 0));
        label_2->setText(QApplication::translate("View_Schedule", "Select Week ", 0));
        viewScheduleBtn->setText(QApplication::translate("View_Schedule", "View Schedule ", 0));
        menuFile->setTitle(QApplication::translate("View_Schedule", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class View_Schedule: public Ui_View_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_SCHEDULE_H
