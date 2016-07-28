#include "homewindow.h"
#include "manager_window.hpp"
#include <iostream>
#include <mysql.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include<QtSql\QSql>
#include<QtSql\QSqlDatabase>
#include <QSqlQuery>
#include<QtSql\qsqldriver.h>
using namespace std; 

HomeWindow::HomeWindow(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::HomeWindowClass )
{
	ui->setupUi(this);
}

HomeWindow::~HomeWindow()
{
	delete ui; 
}

void HomeWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type())
	{
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}

}

void HomeWindow::on_loginBtn_clicked()
{
	HomeWindow hw; 
	QString fname = ui->txtFirstName->toPlainText(); 
	QString lname = ui->txtLastName->toPlainText(); 
	QString user_id = ui->userPassword->toPlainText(); 
	
	QString check_name; 

	
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");


	if (fname != NULL && lname != NULL && user_id != NULL)
	{
		db.open();

		QString sQuery = "select Employee_first_name, Employee_last_name, Employee_id, Employee_Position from employee where Employee_id = '"+user_id+"'";
		QSqlQuery q;
		q.exec(sQuery);

		while (q.next())
		{
			QString fn = q.value(0).toString();
			QString ln = q.value(1).toString();
			QString id = q.value(2).toString();
			//pass = id; 
			QString position = q.value(3).toString();
			
			user_id = id;
			
			if (fname == fn && lname == ln && user_id == id && position == "Manager")
			{
				managerW = new manager_window(this);
				managerW->show();
				this->hide();
			}

			else if (fname == fn && lname == ln && user_id == id && position != "Manager")
			{
				employeeW = new Employee_Window(this);
				employeeW->show();
				this->hide();
			}

		}
		
		db.close();
	}
	
}
QString HomeWindow::get_Id()
{
	return 0; 
}