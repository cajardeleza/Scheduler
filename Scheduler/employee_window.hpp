#pragma once
#include  <QMainWindow>
#include "ui_employee_window.h"
#include "employee_calendar.hpp"



class Employee_Window : public QMainWindow {
	Q_OBJECT

public:
	Employee_Window(QWidget * parent = Q_NULLPTR);
	~Employee_Window();
	
protected: 
	void changeEvent(QEvent *e);
private:
	Ui::Employee_Window *ui;
    Employee_Calendar *employee_cal;
	
	
private slots: 
void on_availabilityBtn_clicked();

};
