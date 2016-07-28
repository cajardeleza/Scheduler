#include "addnewemployee.hpp"
#include "qstringlistmodel.h"
#include <stdlib.h>
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

AddNewEmployee::AddNewEmployee(QWidget * parent) :
QMainWindow(parent),
ui(new Ui::AddNewEmployee)
{
	ui->setupUi(this);
	fill_comboBox();	
	fill_list(); 

}
AddNewEmployee::~AddNewEmployee() {
	delete ui; 
}

void AddNewEmployee::changeEvent(QEvent *e)
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

void AddNewEmployee::on_submitBtn_clicked()
{
	QString fn = ui->txtFirstName->toPlainText();
	QString ln = ui->txtLastName->toPlainText(); 
	QString id = ui->txtIdNum->toPlainText();
	QString pos = ui->position_comboBox->currentText(); 
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	QString off = "0"; 

	if (fn != NULL && ln != NULL && id != NULL)
	{
		ui->listWidget->addItem(fn + "    " + ln + "    " + id);
		
		db.setConnectOptions();
		db.setHostName("localhost");
		db.setDatabaseName("scheduler");
		db.setUserName("root");
		db.setPassword("Inception2194");

		db.open();
		
		
		QString sQuery = "insert into employee(Employee_id, Employee_first_name,Employee_last_name, Employee_Position) Values('" + id + "', '" + fn + "', '" + ln + "', '" + pos + "')";
			QSqlQuery q; 
			q.prepare(sQuery);
			q.bindValue(":Employee_id", id);
			q.bindValue("Employee_first_name", fn);
			q.bindValue("Employee_last_name", ln);
			q.bindValue("Employee_Position", pos);
			q.exec();
			
		
			QString mQuery = "insert into april(EmployeeId) Values('" + id + "')";
			QSqlQuery q2;
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery= "insert into january(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into february(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into march(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into may(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into june(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into july(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into august(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into september(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into october(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into november(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();

			mQuery = "insert into december(EmployeeId) Values('" + id + "')";
			q2.prepare(mQuery);
			q2.bindValue(":EmployeeId", id);
			q2.exec();
		
		db.close();

	}
	/*finished with all of the display of the GUI side of window
		-need to connect with database and update and display through 
		-the DB for the submit, add, and delete. 
	*/


	//MySQL implementation
	

	
}

void AddNewEmployee::fill_comboBox()
{

	QStringList positions; 
	positions << "Bartender" << "Server" << "Bus" << "Host" << "Expo"<<"Manager"; 
	QStringListModel *model = new QStringListModel();
	model->setStringList(positions);
	ui->position_comboBox->setModel(model); 


}


void AddNewEmployee::fill_list()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	db.open();
	QString sQuery = "select Employee_first_name, Employee_last_name, Employee_id from employee";
	QSqlQuery q; 
	q.exec(sQuery); 

	while (q.next())
	{
		QString fname = q.value(0).toString(); 
		QString lname = q.value(1).toString(); 
		QString id = q.value(2).toString();

		ui->listWidget->addItem(fname + "    " + lname + "    " + id);
	}

	db.close(); 
}

void AddNewEmployee::on_deleteBtn_clicked()
{

	/*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	db.open();
	QString sQuery = "delete from employee where Employee_id = '";
	QSqlQuery q;
	q.exec(sQuery);
	*/
}
