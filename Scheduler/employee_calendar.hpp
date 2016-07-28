#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_employee_calendar.h"




class Employee_Calendar : public QMainWindow {
	Q_OBJECT

public:
	Employee_Calendar(QWidget * parent = Q_NULLPTR);
	~Employee_Calendar();
	
protected : 
	void changeEvent(QEvent *e);
	void fill_list();
private:
	
	Ui::Employee_Calendar *ui;
		
	QString get_month(QString date); 
	QString get_day(QString date);
	//HomeWindow hw; 
	void convert_db_String(int x);
	void update_list(); 
	QDate convert_date(QString date);
	void color_dates(); 
	void check_list(); 
	bool check_dates(QString day);//goes through list to check if the day is in the list
private slots: 
	void on_calendarWidget_selectionChanged();
	void on_submitBtn_clicked(); 
	void on_pushButton_clicked(); 

};
