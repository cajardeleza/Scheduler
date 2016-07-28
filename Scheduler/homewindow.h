#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_homewindow.h"
#include "manager_window.hpp"
#include "employee_window.hpp"
namespace Ui {
	class TestApp;

}
class HomeWindow : public QMainWindow
{
	Q_OBJECT 

public:
	HomeWindow(QWidget *parent = 0);
	~HomeWindow();
	QString get_Id(); 

protected:
	void changeEvent(QEvent *e);
	
	
private:
	Ui::HomeWindowClass *ui;
	manager_window *managerW;
	Employee_Window *employeeW; 
	//QString pass; 
	 


private slots: 
void on_loginBtn_clicked();

};

#endif // HOMEWINDOW_H
