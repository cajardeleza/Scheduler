#include "homewindow.h"
#include "employee_calendar.hpp"
#include "employee_window.hpp"
#include "addnewemployee.hpp"
#include "manager_window.hpp"
#include "availability_window.hpp"

#include <QtWidgets/QApplication>
#include <QSql>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HomeWindow w;

	w.show();


	

	return a.exec();
}
