#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_addnewemployee.h"

class AddNewEmployee : public QMainWindow {
	Q_OBJECT

public:
	AddNewEmployee(QWidget * parent = Q_NULLPTR);
	~AddNewEmployee();
protected: 
	void changeEvent(QEvent *e);
	void fill_comboBox();
	void fill_list(); 

private:
	Ui::AddNewEmployee *ui;

private slots: 
 void on_submitBtn_clicked();
 void on_deleteBtn_clicked(); 
};
