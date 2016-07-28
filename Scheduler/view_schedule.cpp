#include "view_schedule.hpp"
#include<vector>
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
#include <QtWidgets>
#include <QPrinter>
#include <QPrintDialog>

using namespace std; 

static vector<QString>organized_employees; 
static QStringList days; 
QString month;
QString week;
QStringList day;
View_Schedule::View_Schedule(QWidget * parent) : QMainWindow(parent),
ui(new Ui::View_Schedule){
	ui->setupUi(this);
	organized_employees.clear(); 
	organize_Employees(); 
	fill_combo_boxes(); 
	setRows();
}

View_Schedule::~View_Schedule() {
	delete ui; 
}



void View_Schedule::fill_combo_boxes()
{
	QStringList months;
	QStringList weeks; 
	months << "january" << "february" << "march" << "april" << "may" << "june" << "july" << "august" << "september" << "october" << "november" << "december";
	weeks << "First" << "Second" << "Third" << "Fourth" << "Fifth";

	for (int i = 0; i < months.size(); i++)
	{
		ui->comboBox->addItem(months.at(i));
	}
	for (int j = 0; j < weeks.size(); j++)
	{
		ui->comboBox_2->addItem(weeks.at(j));
	}

}

void View_Schedule :: setUp_Table()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	month = ui->comboBox->currentText(); 
	week = ui->comboBox_2->currentText(); 
	bool last_week = false; 
	QDate m; 

	if (month == "january")m = QDate(2016,1,1); 
	if (month == "february")m = QDate(2016, 2,1);
	if (month == "march")m = QDate(2016, 3,1);
	if (month == "april")m = QDate(2016, 4, 1);
	if (month == "may")m = QDate(2016, 5, 1);
	if (month == "june")m = QDate(2016, 6, 1);
	if (month == "july")m = QDate(2016, 7, 1);
	if (month == "august")m = QDate(2016, 8, 1);
	if (month == "september")m = QDate(2016, 9, 1);
	if (month == "october")m = QDate(2016, 10, 1);
	if (month == "november")m = QDate(2016, 11, 1);
	if (month == "decemeber") m = QDate(2016, 12, 1);

	if (month != NULL && week != NULL)
	{
			
				day.clear();
				days.clear(); 
				day <<"Employee"<<month + " 1" <<month+ " 2" << month + " 3" << month+" 4" << month+" 5" << month+" 6" << month+" 7";
				days << "1"<< "2" << "3" <<"4" << "5" <<"6" << "7";
			
				
			
			
			
			if (week == "Second")
			{
				day.clear(); 
				days.clear(); 
				day << "Employee" << month + " 8" << month + " 9" << month + " 10" << month + " 11" << month + " 12" << month + " 13" << month + " 14";
				days << "8" << "9" << "10" << "11" << "12" << "13" << "14";
			}
			if (week == "Third")
			{
				days.clear();
				day.clear();
				day << "Employee" << month + " 15" << month + " 16" << month + " 17" << month + "18" << month + " 19" << month + " 20" << month + " 21";
				days << "15" << "16" << "17" << "18" << "19" << "20" << "21";
			}

			if (week == "Fourth")
			{
				day.clear();
				days.clear(); 
				day << "Employee" << month + " 22" << month + " 23" << month + " 24" << month + "25" << month + " 26" << month + " 27" << month + " 28";
				days << "22" << "23" << "24" << "25" << "26" << "27" << "28";
			}

			if (week == "Fifth")
			{
				last_week = true; 
				day.clear();
				days.clear();
				day << "Employee" << month + " 29" << month + " 30" << month + " 31" << " " << " " << " " << " ";
				days << "29" << "30" << "31" << "32";
			}

			
			QTableWidgetItem *workday, *workday1; 
			QTableWidgetItem *test; 
			ui->tableWidget->setHorizontalHeaderLabels(day);
			
			QString d1;

			db.open();
			QSqlQuery q;

			for (int i = 0; i < organized_employees.size(); i++)
			{
				
					for (int j = 0; j < days.size(); j++)
					{	
						QString sQuery = "select Day"+days.at(j) + " from " + month + " where EmployeeId ='" + organized_employees.at(i) + "'";
						q.exec(sQuery);
						while (q.next())
						{
							
								d1 = convert_days_off(q.value(0).toString());
							
						}
							workday = new QTableWidgetItem(QString(d1));
							ui->tableWidget->setItem(i,j+1,workday);
						
						}
						
					}
					 
			}


			db.close();

			ui->calendarWidget->setSelectedDate(m);

	

}
void View_Schedule:: organize_Employees()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");

	vector<QString> managers; 
	vector<QString> bar; 
	vector<QString>server; 
	vector<QString>host; 
	vector<QString>expo; 
	vector<QString>bus; 
	
	db.open(); 
	QString sQuery = "select Employee_Position, Employee_id from employee";
	QSqlQuery q;
	q.prepare(sQuery);
	q.exec(); 
	while (q.next())
	{
		if (q.value(0) == "Manager")
		managers.push_back(q.value(1).toString()); 
		if (q.value(0) == "Bartender")
			bar.push_back(q.value(1).toString());
		if (q.value(0) == "Server")
			server.push_back(q.value(1).toString());
		if (q.value(0) == "Host")
			host.push_back(q.value(1).toString());
		if (q.value(0) == "Expo")
			expo.push_back(q.value(1).toString());
		if (q.value(0) == "Bus")
			bus.push_back(q.value(1).toString());
		
	}
	db.close(); 
	organized_employees.reserve(managers.size() + bar.size() + server.size() + host.size() + expo.size() + bus.size());
	organized_employees.insert(organized_employees.end(), managers.begin(), managers.end());
	organized_employees.insert(organized_employees.end(), bar.begin(),bar.end());
	organized_employees.insert(organized_employees.end(), server.begin(), server.end());
	organized_employees.insert(organized_employees.end(), host.begin(), host.end());
	organized_employees.insert(organized_employees.end(), expo.begin(), expo.end());
	organized_employees.insert(organized_employees.end(), bus.begin(), bus.end());




}

QString View_Schedule::convert_days_off(QString off)
{
	if (off == "0")
		return "x           x";
	if (off == "1")
		return "********";
	if (off == "2")
		return "10          x"; 
	if (off == "3")
		return "x           4"; 
	if (off == "4")
		return "10          4"; 

}

void View_Schedule::on_viewScheduleBtn_clicked()
{
	
	set_name_column();
	setUp_Table();
}

void View_Schedule::setRows() 
{
	for (int i = 0; i < organized_employees.size(); i++)
	{
		ui->tableWidget->insertRow(0);
	}

}

void View_Schedule::set_name_column()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setConnectOptions();
	db.setHostName("localhost");
	db.setDatabaseName("scheduler");
	db.setUserName("root");
	db.setPassword("Inception2194");
	
	QTableWidgetItem *ptw;
	
	QString position;

	db.open();
	QSqlQuery q;

	for (int i= 0; i < organized_employees.size(); i++)
	{
		QString sQuery = "select Employee_first_name, Employee_last_name from employee where Employee_id='" + organized_employees.at(i) + "'";
		q.exec(sQuery);

		while (q.next())
		{
			position = q.value(0).toString()+" " + q.value(1).toString();

		}
		ptw = new QTableWidgetItem(QString(position));
		ui->tableWidget->setItem(i, 0, ptw);
	 

	}
	

	db.close();

}

void View_Schedule::on_actionConvert_to_Excel_triggered()
{
	QFile f(month + "_" + week + "_week_Schedule.csv");

	if (f.open(QIODevice::WriteOnly))
	{
		QTextStream ts(&f); 
		QStringList strList; 

		for (int c = 0; c < ui->tableWidget->columnCount(); c++)
		{
			strList << "\"" + ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() + "\"";
			
		}ts << strList.join(";") << "\n";
		for (int r = 0; r < ui->tableWidget->rowCount(); r++)
		{
			strList.clear(); 
			for (int co = 0; co < ui->tableWidget->columnCount(); co++)
			{
				
				strList << """" + ui->tableWidget->item(r, co)->text() + """"; 
			}
			
			ts << strList.join(",") + "\n"; 
		}
	}
	f.close(); 
}