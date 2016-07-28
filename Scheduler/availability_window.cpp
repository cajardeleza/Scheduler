#include "availability_window.hpp"
#include <vector>
#include <ctime>
#include<iostream>
#include<set>
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
#include <QtDebug>
#include <QMimeData>
#include <QDropEvent>


using namespace std; 
static vector<QString> available; 
static vector <QString> amList;
static vector <QString> pmList; 
static vector<QString> doubles;
static QString date;
Availability_Window::Availability_Window(QWidget * parent) :
QMainWindow(parent),
ui(new Ui::Availability_Window)
{
	ui->setupUi(this);
	setAcceptDrops(true); 
	
}

Availability_Window::~Availability_Window() {
	delete ui; 
}

void Availability_Window::changeEvent(QEvent *e)
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

void Availability_Window::on_calendarWidget_selectionChanged()
{
	ui->listWidget_3->clear(); 
	ui->listWidget_2->clear(); 
	ui->listWidget->clear(); 
	date = ui->calendarWidget->selectedDate().toString("MM/dd/yyyy"); 
	check_Available(date); 
	update_lists();
	
	

	
	
}

QString Availability_Window::get_month(QString date)
{
	if (date.at(0) == "0" && date.at(1) == "1")
	{
		return "January";
	}
	if (date.at(0) == "0" && date.at(1) == "2")
	{
		return "February";
	}
	if (date.at(0) == "0" && date.at(1) == "3")
	{
		return "March";
	}
	if (date.at(0) == "0" && date.at(1) == "4")
	{
		return "April";
	}
	if (date.at(0) == "0" && date.at(1) == "5")
	{
		return "May";
	}
	if (date.at(0) == "0" && date.at(1) == "6")
	{
		return "June";
	}
	if (date.at(0) == "0" && date.at(1) == "7")
	{
		return "July";
	}
	if (date.at(0) == "0" && date.at(1) == "8")
	{
		return "August";
	}
	if (date.at(0) == "0" && date.at(1) == "9")
	{
		return "September";
	}
	if (date.at(0) == "1" && date.at(1) == "0")
	{
		return "October";
	}
	if (date.at(0) == "1" && date.at(1) == "1")
	{
		return "November";
	}
	if (date.at(0) == "1" && date.at(1) == "2")
	{
		return "December";
	}
	else
		return "not valid";
}

QString Availability_Window::get_day(QString date)
{
	if (date.at(3) == "0" && date.at(4) == "1")
	{
		return "1";
	}
	if (date.at(3) == "0" && date.at(4) == "2")
	{
		return "2";
	}
	if (date.at(3) == "0" && date.at(4) == "3")
	{
		return "3";
	}
	if (date.at(3) == "0" && date.at(4) == "4")
	{
		return "4";
	}
	if (date.at(3) == "0" && date.at(4) == "5")
	{
		return "5";
	}
	if (date.at(3) == "0" && date.at(4) == "6")
	{
		return "6";
	}
	if (date.at(3) == "0" && date.at(4) == "7")
	{
		return "7";
	}
	if (date.at(3) == "0" && date.at(4) == "8")
	{
		return "8";
	}
	if (date.at(3) == "0" && date.at(4) == "")
	{
		return "9";
	}
	else
	{
		QString d = (QString)date.at(3) + "" + date.at(4);
		return d;
	}
}

void Availability_Window::check_Available(QString date)
{
	available.clear(); 
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	
	db.open();
	QSqlQuery q;
	QString sQuery = "select Day" + get_day(date) + ", EmployeeId from " + get_month(date);
	q.prepare(sQuery);
	q.exec();
	while (q.next())
	{

		available.push_back(q.value(0).toString());
		available.push_back(q.value(1).toString());
		
	}

	db.close(); 

	

	/*QString id = q.value(1).toString();
	if (q.value(0).toString() == "1")
	{
		
		q2.prepare(sQuery2);
		q2.bindValue(":Employee_first_name", q2.value(0).toString());
		q2.bindValue(":Emplyee_last_name", q2.value(1).toString());
		q2.exec();
		ui->listWidget->addItem(q2.value(0).toString() + q2.value(1).toString() + "close");
	}*/
}

void Availability_Window::update_lists()
{
	ui->listWidget_3->clear();
	ui->listWidget_2->clear();
	ui->listWidget->clear(); 

	QString id; 
	QString name; 
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			if (available.at(i) == "0")
			{
				name = get_Employee_Name(id); 
				ui->listWidget_3->addItem(name); 
			}
			if (available.at(i) == "2")
			{
				name = get_Employee_Name(id);
				ui->listWidget_2->addItem(name);
			}
			if (available.at(i) == "3")
			{
				name = get_Employee_Name(id);
				ui->listWidget->addItem(name);
			}

			if (available.at(i) == "4")
			{
				name = get_Employee_Name(id);
				ui->listWidget_2->addItem(name);
				ui->listWidget->addItem(name);
			}
		}
	}
}

QString Availability_Window::get_Employee_Name(QString id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	QString name; 

	db.open(); 
	QSqlQuery q; 
	QString sQuery = "select Employee_first_name, Employee_last_name, Employee_id from employee where Employee_id='" + id + "'";
	q.exec(sQuery);

	while (q.next())
	{
		QString fname = q.value(0).toString();
		QString lname = q.value(1).toString();
		QString pass = q.value(2).toString();
		name = fname +" "+ lname+"         "+pass; 
	}
	db.close();

	return name;
}

QString Availability_Window::get_Employee_Position(QString id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	QString position;

	db.open();
	QSqlQuery q;
	QString sQuery = "select Employee_Position from employee where Employee_id='" + id + "'";
	q.exec(sQuery);

	while (q.next())
	{
		position = q.value(0).toString();
		
	}
	db.close();
	return position;
}

QString Availability_Window::get_id(QString name)
{
	QString id; 
	id = (QString)(name.at(name.length() - 4))+ (name.at(name.length() - 3)) + name.at(name.length() - 2) + name.at(name.length()-1);
	return id; 
}




void Availability_Window::on_RemoveAMBtn_clicked()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	bool pm=false; 

	if (ui->listWidget_2->currentItem() != NULL)
	{
		

			QString selected = ui->listWidget_2->currentItem()->text();
			QString employee;


			for (int j = 0; j < ui->listWidget->count(); j++)
			{
				if (selected == ui->listWidget->item(j)->text())
				{
					db.open();
					QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='3' where EmployeeId = '" + get_id(selected) + "'";
					QSqlQuery q;
					q.prepare(sQuery);
					q.exec();
					db.close();
				
				}

				else
				{
					db.open();
					QString sQuery1 = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(selected) + "'";
					QSqlQuery q1;
					q1.prepare(sQuery1);
					q1.exec();
					db.close();
					
				}
			}
	if (ui->listWidget->count() == 0)
		{

			db.open();
			QString sQuery1 = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(selected) + "'";
			QSqlQuery q1;
			q1.prepare(sQuery1);
			q1.exec();
			db.close();
		}

	}	ui->listWidget_2->takeItem(ui->listWidget_2->row(ui->listWidget_2->currentItem()));
	
	
	/*if (ui->listWidget_2->currentItem()!=NULL)
	{
		if (ui->listWidget_2->count() > 0)
			{
				amList.clear();
				QString selected = ui->listWidget_2->currentItem()->text(); 
				QString employee;
		
	
				int size = ui->listWidget_2->count(); 
				for (int i = 0; i < size; i++)
				{
					employee = ui->listWidget_2->item(i)->text();
					amList.push_back(employee);
					if (selected == employee)
					{
						if (ui->listWidget->count() != 0)
						{
							for (int x = 0; x < ui->listWidget->count(); x++)
								{
									if (selected == ui->listWidget->item(x)->text())
										{
											pm = true;
											db.open();
											QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='3' where EmployeeId = '" + get_id(amList.at(i)) + "'";
											QSqlQuery q;
											q.prepare(sQuery);
											q.exec();
											db.close();
										}
								}
						}
				

						if (pm == false)
						{
							db.open();
							QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(amList.at(i)) + "'";
							QSqlQuery q;
							q.prepare(sQuery);
							q.exec();
							db.close();

						}
				
						int x = amList.size(); 
						if (x > 1)
						{
							amList.erase(amList.begin() + i);
						}
						else
							amList.erase(amList.begin() + 0);
					}
				}
				ui->listWidget_2->clear();
				if (amList.empty() == false)
				{
			
					for (int j = 0; j < amList.size(); j++)
					{
						ui->listWidget_2->addItem(amList.at(j));
					}

				}
		

			}

			amList.clear(); 
	}
	
	*/
}

void Availability_Window::on_RemovePMBtn_clicked()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	
	

	if (ui->listWidget->currentItem() != NULL)
	{
		

			QString selected = ui->listWidget->currentItem()->text();
			QString employee;


			for (int j = 0; j < ui->listWidget_2->count(); j++)
			{
				if (selected == ui->listWidget_2->item(j)->text())
				{
					db.open();
					QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(selected) + "'";
					QSqlQuery q;
					q.prepare(sQuery);
					q.exec();
					db.close();
				}
				else
				{
					db.open();
					QString sQuery1 = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(selected) + "'";
					QSqlQuery q1;
					q1.prepare(sQuery1);
					q1.exec();
					db.close();
				}
				
			}

			if (ui->listWidget_2->count() == 0)
			{

				db.open();
				QString sQuery1 = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(selected) + "'";
				QSqlQuery q1;
				q1.prepare(sQuery1);
				q1.exec();
				db.close();
			}
		
		}
	
	ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
	}

	/*if (ui->listWidget->currentItem() != NULL)
	{
			if (ui->listWidget->count() > 0)
				{
					pmList.clear();
					QString selected = ui->listWidget->currentItem()->text();
					QString employee;

					int size = ui->listWidget->count();
					for (int i = 0; i < size; i++)
					{
						employee = ui->listWidget->item(i)->text();
						pmList.push_back(employee);
						if (selected == employee)
						{
							if (ui->listWidget_2->count()>0)
							{
								for (int x = 0; x < ui->listWidget_2->count(); x++)
								{
									if (selected == ui->listWidget_2->item(x)->text())
									{
										am = true;
										db.open();
										QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(pmList.at(i)) + "'";
										QSqlQuery q;
										q.prepare(sQuery);
										q.exec();
										db.close();
									}
								}

							}
				

							if (am == false)
							{
								db.open();
								QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='0' where EmployeeId = '" + get_id(pmList.at(i)) + "'";
								QSqlQuery q;
								q.prepare(sQuery);
								q.exec();
								db.close();

							}
							int x = pmList.size();
							if (x > 1)
							{
								pmList.erase(pmList.begin() + i);
							}
							else
								pmList.erase(pmList.begin() + 0);
						}
					}
	
				ui->listWidget->clear();
					if (pmList.empty() == false)
					{
						for (int j = 0; j < pmList.size(); j++)
						{
							ui->listWidget->addItem(pmList.at(j));
						}
					}
		

				}
				pmList.clear();
	}
	
	*/


void Availability_Window::on_Submit_clicked()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	QString am_name;
		QString pm_name;
	//checks for doubles 

	for (int i = 0; i < ui->listWidget_2->count(); i++)
	{
		am_name = ui->listWidget_2->item(i)->text();
		for (int j = 0; j < ui->listWidget->count(); j++)
		{
			pm_name = ui->listWidget->item(j)->text(); 
			if (am_name == pm_name)
			{
				doubles.push_back(am_name);
			}

		else if (am_name != pm_name)
			{
				db.open();
				QString Query = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(am_name) + "'";
				QSqlQuery q3;
				q3.prepare(Query);
				q3.exec();
				db.close();
			}

		}

		if (ui->listWidget->count() == 0)
		{
			db.open();
			QString Query = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(am_name) + "'";
			QSqlQuery q3;
			q3.prepare(Query);
			q3.exec();
			db.close();
		}

	}


	for (int x = 0; x < ui->listWidget->count(); x++)
	{
		pm_name = ui->listWidget->item(x)->text();
		for (int y = 0; y < ui->listWidget_2->count(); y++)
		{
			am_name = ui->listWidget_2->item(y)->text();
			
			if (pm_name != am_name)
			{
				db.open();
				QString Q = "update " + get_month(date) + " set Day" + get_day(date) + "='3' where EmployeeId = '" + get_id(pm_name) + "'";
				QSqlQuery q4;
				q4.prepare(Q);
				q4.exec();
				db.close();
			}

		}

		if (ui->listWidget_2->count() == 0)
		{
			db.open();
			QString Query = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(pm_name) + "'";
			QSqlQuery q3;
			q3.prepare(Query);
			q3.exec();
			db.close();
		}
	}

	if (doubles.empty() == false)
	{
		for (int l = 0; l < doubles.size(); l++)
		{
			
			db.open();
			QString sQuery = "update " + get_month(date) + " set Day" + get_day(date) + "='4' where EmployeeId = '" + get_id(doubles.at(l)) + "'";
			QSqlQuery q;
			q.prepare(sQuery);
			q.exec();
			db.close();

		}
	}

	/*
	
	QString m_name;
	//checks for working AM 
	for (int i = 0; i < ui->listWidget_2->count(); i++)
	{
		m_name = ui->listWidget_2->item(i)->text();
		if(doubles.empty())
		{
			db.open();
			QString Query = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(m_name) + "'";
			QSqlQuery q3;
			q3.prepare(Query);
			q3.exec();
			db.close();
		}
		for (int j = 0; j < doubles.size(); j++)
		{
			if (m_name != doubles.at(j)||doubles.empty())
			{
				db.open();
				QString sQuery5 = "update " + get_month(date) + " set Day" + get_day(date) + "='2' where EmployeeId = '" + get_id(m_name) + "'";
				QSqlQuery q5;
				q5.prepare(sQuery5);
				q5.exec();
				db.close();
			}

		}
	}
	QString n_name;
	for (int k = 0; k < ui->listWidget->count(); k++)
	{
		n_name= ui->listWidget->item(k)->text();
		if (doubles.empty())
		{
			db.open();
			QString Q= "update " + get_month(date) + " set Day" + get_day(date) + "='3' where EmployeeId = '" + get_id(n_name) + "'";
			QSqlQuery q4;
			q4.prepare(Q);
			q4.exec();
			db.close();
		}
		
		for (int h = 0; h < doubles.size(); h++)
		{
			if (n_name != doubles.at(h) || doubles.empty())
			{
				db.open();
				QString sQuery1 = "update " + get_month(date) + " set Day" + get_day(date) + "='3' where EmployeeId = '" + get_id(n_name) + "'";
				QSqlQuery q1;
				q1.prepare(sQuery1);
				q1.exec();
				db.close();
			}

		}
	}
	*/
	doubles.clear(); 
	check_Available(date); 
	update_lists();

}


void Availability_Window::on_serverBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position;
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id);
			if (available.at(i) == "0" && position == "Server")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}

		}
	}
}

void Availability_Window::on_managerBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position;
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id);
			if (available.at(i) == "0" && position == "Manager")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}

		}
	}
}

void Availability_Window::on_hostBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position;
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id);
			if (available.at(i) == "0" && position == "Host")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}

		}
	}
}

void Availability_Window::on_expoBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position;
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id);
			if (available.at(i) == "0" && position == "Expo")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}

		}
	}
}

void Availability_Window::on_busBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position;
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id);
			if (available.at(i) == "0" && position == "Bus")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}

		}
	}
}

void Availability_Window::on_bartenderBtn_clicked()
{
	ui->listWidget_3->clear();
	QString id;
	QString name;
	QString position; 
	for (int i = 0; i < available.size(); i++)
	{
		if (i % 2 == 0)
		{
			id = available.at(i + 1);
			position = get_Employee_Position(id); 
			if (available.at(i) == "0" && position=="Bartender")
			{
				name = get_Employee_Name(id);
				ui->listWidget_3->addItem(name);
			}
			
		}
	}

}







