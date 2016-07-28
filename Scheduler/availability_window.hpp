#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_availability_window.h"
#include <vector>


class Availability_Window : public QMainWindow {
	Q_OBJECT

public:
	Availability_Window(QWidget * parent = Q_NULLPTR);
	
	~Availability_Window();
	
protected: 
	void changeEvent(QEvent *e);
	 
	QString get_month(QString date);
	QString get_day(QString date);
	void check_Available(QString date);
	void update_lists();
	QString get_Employee_Name(QString id);
	QString get_Employee_Position(QString id); 
	QString get_id(QString name); 
	
	
	
private:
	Ui::Availability_Window *ui;
	
private slots: 
	void on_calendarWidget_selectionChanged(); 
	void on_serverBtn_clicked(); 
	void on_managerBtn_clicked(); 
	void on_hostBtn_clicked(); 
	void on_expoBtn_clicked(); 
	void on_busBtn_clicked();
	void on_bartenderBtn_clicked(); 
	void on_RemoveAMBtn_clicked(); 
	void on_RemovePMBtn_clicked(); 
	void on_Submit_clicked(); 
	
	

};
