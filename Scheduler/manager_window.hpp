#pragma once


#include <QMainWindow>
#include "ui_manager_window.h"
#include "addnewemployee.hpp"
#include "availability_window.hpp"
#include "view_schedule.hpp"
#include "calendar.hpp"


class manager_window : public QMainWindow {
	Q_OBJECT

public:
	manager_window(QWidget * parent = Q_NULLPTR);
	~manager_window();
protected:
	void changeEvent(QEvent *e);
private:
	Ui::manager_window *ui;
	AddNewEmployee *add_employeeW;
	Availability_Window *availanilityW;
	View_Schedule *scheduleW; 

private slots:
void on_availabilityBtn_clicked(); 
void on_newEmployeeBtn_clicked();
void on_scheduleBtn_clicked();


};
