#include "employee_calendar.hpp"
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
#include <sstream>
using namespace std;

static vector<QString> days;
static vector<int> availability;
static vector<QDate> db_dates;
static QStringList removed; 
static QString date;
static QString id;
static bool updated = false; 
static QString prev_month;
Employee_Calendar::Employee_Calendar(QWidget * parent) :
	QMainWindow(parent),
	ui(new Ui::Employee_Calendar)
{
	
	ui->setupUi(this);
	ui->calendarWidget->hide();
	ui->submitBtn->hide();
	ui->listWidget->hide();
	ui->label->hide(); 
	date = ui->calendarWidget->selectedDate().toString("MM/dd/yyyy");
	days.clear();

}

Employee_Calendar::~Employee_Calendar() {

	delete ui;
}
void Employee_Calendar::changeEvent(QEvent *e)
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

void Employee_Calendar::on_calendarWidget_selectionChanged()
{
	ui->listWidget->clear();
	
    date = ui->calendarWidget->selectedDate().toString("MM/dd/yyyy");
	QDate d = ui->calendarWidget->selectedDate(); 
	QBrush brush; 
	brush.setColor(Qt::darkGreen); 
	QTextCharFormat cf = ui->calendarWidget->dateTextFormat(d); 
	cf.setBackground(brush); 
	ui->calendarWidget->setDateTextFormat(d, cf); 
	
	//need to go through, check month and display only the days where the month equals the current month. 
	//which means I need to update fill list to do this 

	if (days.empty())
	{
		days.push_back(date); 
	}
	else
	{
		days.push_back(date);
		for (unsigned int i = 0; i < days.size() - 1; i++)//go through and check for doubles 
		{
			if (date == days.at(i))
			{

				if (days.size() > 2)
				{
					
					
					d = convert_date(days.at(i));
					brush.setColor(Qt::white);
					cf= ui->calendarWidget->dateTextFormat(d);
					cf.setBackground(brush);
					ui->calendarWidget->setDateTextFormat(d, cf);
					days.erase(days.begin() + i);
					
					
					d = convert_date(days.at(days.size() - 1)); 
					brush.setColor(Qt::white);
					cf = ui->calendarWidget->dateTextFormat(d);
					cf.setBackground(brush);
					ui->calendarWidget->setDateTextFormat(d, cf);
					days.erase(days.begin() + days.size()-1);

				}

				else
				{
					d = convert_date(days.at(0));
					brush.setColor(Qt::white);
					cf = ui->calendarWidget->dateTextFormat(d);
					cf.setBackground(brush);
					ui->calendarWidget->setDateTextFormat(d, cf);
					days.erase(days.begin());

				}
			}
			
		}
	}
	
	
	if (get_month(days.at(days.size() - 1)) != get_month(days.at(days.size() - 2)))
		update_list(); 
	fill_list();
	
	color_dates(); 
}

void Employee_Calendar::fill_list()
{
	ui->listWidget->clear(); 
	QString this_month = date.at(0) +QString( date.at(1));
	QString month_check; 

	for (unsigned int i = 0; i < days.size(); i++)
	{
		month_check = days.at(i).at(0) + QString(days.at(i).at(1));
		

		if (this_month == month_check)
		{
			
			ui->listWidget->addItem(days.at(i));
			ui->listWidget->sortItems();
		}
		
		
	}
	
	color_dates(); 

}


QString Employee_Calendar::get_month(QString date)
{
	if (date.at(0)=="0" && date.at(1)=="1")
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

QString Employee_Calendar::get_day(QString date)
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

void Employee_Calendar::convert_db_String(int x)
{
	QString newdate; 
	
	QString d = x;
	string s; 
	stringstream out; 
	out << x; 
	s = out.str(); 
	

	if (x < 10)
	{
		for (int i = 0; i < date.size(); i++)
		{
			if (i == 3)
				newdate.append("0"); 
			else if (i == 4)
				newdate.append(s.at(0));
			else
				newdate.append(date.at(i)); 
			
		}
	
	}
	else {
		for (int j = 0; j < date.size(); j++)
		{
			if (j == 3)newdate.append(s.at(0));
			else if (j == 4)newdate.append(s.at(1));
			else
				newdate.append(date.at(j));
			
		}
	
	}

	days.push_back(newdate);//this is where the bug is for the repeated dates. 

}

void Employee_Calendar::update_list()
{
	updated = true;
	ui->listWidget->clear(); 
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");


	QString num;
	QString num1;
	QString sQuery1;
	QSqlQuery q1;
	db.open();
	int count = 0; 
	for (int i = 1; i < 32; i++)
	{
		string s;
		stringstream out;

		out << i;
		s = out.str();

		if (i < 10)
			num = s.at(0);
		else
		{
			num = s.at(0);
			num1 = s.at(1); 

			num = num + num1;
		}
			

		sQuery1 = "select Day" + num + " from " + get_month(date) + " where EmployeeId = '" + id + "'";
		q1.prepare(sQuery1);
		q1.exec();

		while (q1.next())
		{
			if (q1.value(0) == "1")
			{
				 
				//days.push_back("07/05/2016");
				convert_db_String(i);
				
				
				//ui->listWidget->addItem(days.at(count));
				count++;

			}

		}

		s.clear();
	}

	db.close();
}

QDate Employee_Calendar::convert_date(QString date)
{
	QString y, m, d; 
	int year, month, day; 
	QDate convertedDate; 
	y.append(date.at(6)); 
	y.append(date.at(7));  
	y.append(date.at(8)); 	
	y.append(date.at(9));	
	

	d.append(date.at(3)); 
	d.append(date.at(4)); 

	m.append(date.at(0)); 
	m.append(date.at(1)); 

	year = y.toInt(); 
	month = m.toInt(); 
	day = d.toInt(); 

	convertedDate = QDate(year, month, day); 
	return convertedDate; 
}



void Employee_Calendar::color_dates()
{

	for (int i = 0; i < ui->listWidget->count(); i++)
	{
		QString check = ui->listWidget->item(i)->text();
		QDate d = convert_date(check);
		QBrush brush;
		brush.setColor(Qt::darkGreen);
		QTextCharFormat cf = ui->calendarWidget->dateTextFormat(d);
		cf.setBackground(brush);
		ui->calendarWidget->setDateTextFormat(d, cf);
	}
	
	
}

void Employee_Calendar::check_list()
{

}

bool Employee_Calendar::check_dates(QString day)
{
	bool valid =false;
	for (int x = 0; x < ui->listWidget->count(); x++)
	{
		if (day == get_day(ui->listWidget->item(x)->text()))
			valid = true;
		
	}
	return valid; 
}

void Employee_Calendar::on_submitBtn_clicked()
{

	
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	vector <QString> off; 
	vector <QString> working; 
	QString m; 
	QString list_date; 
	QString num, num1, day; 
	int count = 0;
	int lim = ui->listWidget->count()-1; 
	db.open();
	
	for (int j = 0; j < ui->listWidget->count(); j++)
	{	
		list_date = ui->listWidget->item(j)->text();
		day = get_day(list_date); //this will give you the day number of the first element in list
		m = get_month(list_date);
		for (int i = 1; i < 32; i++)
			{
				
		
		
		
				
				string s;
				stringstream out;
				out << i;

				s = out.str();
				if (i < 10)
					num = s.at(0);//<- num is used to check each day in database. 
				else
				{
					num = s.at(0);
					num1 = s.at(1);
					num = num + num1;
				}
	
				QString sQuery = "select Day" + num + " from " + m + " where EmployeeId ='" + id + "'";
				QSqlQuery q;
				q.exec(sQuery);
				while (q.next())
				{
					if (q.value(0) == "1")
					{
						if (num == day)
						{	
							QString sQuery1 = "update " + get_month(list_date) + " set Day" + num + "='1' where EmployeeId = '" + id + "'";
							QSqlQuery q1;
							q1.prepare(sQuery1);
							q1.exec();
							if(count<lim)
							count++; 

						}
						if (num != day && check_dates(num)==false)
						{
							QString sQuery2 = "update " + get_month(list_date) + " set Day" + num + "='0' where EmployeeId = '" + id + "'";
							QSqlQuery q2;
							q2.prepare(sQuery2);
							q2.exec();
						}
				
					}
					else if (q.value(0) == "0"&& num==day)
					{
						QString sQuery3 = "update " + get_month(list_date) + " set Day" + num + "='1' where EmployeeId = '" + id + "'";
						QSqlQuery q3;
						q3.prepare(sQuery3);
						q3.exec();
						//if(count<lim)
						//count++;
					}
				}

			}
		
	}
			
		

db.close(); 



}

void Employee_Calendar::on_pushButton_clicked()
{
	

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	QString temp; 
	id = ui->textEdit->toPlainText();
	
	db.open();
	QString sQuery = "select Employee_id, Employee_first_name, Employee_last_name from employee where Employee_id= '"+id+"'";
	QSqlQuery q;
	QString name;
	q.prepare(sQuery);
	q.exec();
		
		while (q.next())
		{
			 name = "Availability for " + q.value(1).toString() + " " + q.value(2).toString();
			 temp = q.value(0).toString();
		}

		if (temp == id)
		{
			ui->calendarWidget->show();
			ui->submitBtn->show();
			ui->listWidget->show();
			ui->label->show();
			ui->label_3->setText(name); 
			ui->textEdit->hide();
			ui->label_2->hide();
			ui->pushButton->hide();
		}
	
		update_list(); 
		color_dates(); 
	db.close();
}


