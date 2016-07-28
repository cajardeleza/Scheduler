#include "manager_window.hpp"
#include "addnewemployee.hpp"
#include "availability_window.hpp"
#include "view_schedule.hpp"
#include "calendar.hpp"

manager_window::manager_window(QWidget * parent) :
	QMainWindow(parent),
	ui(new Ui::manager_window)
{
	ui->setupUi(this);
	
	
}

manager_window::~manager_window() {
	delete ui; 
	
}
void manager_window::changeEvent(QEvent *e)
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



void manager_window::on_availabilityBtn_clicked()
{
	availanilityW = new Availability_Window(this);
	availanilityW->show(); 
	
}
void manager_window::on_newEmployeeBtn_clicked()
{
	
	add_employeeW = new AddNewEmployee(this);
	add_employeeW->show();
}

void manager_window::on_scheduleBtn_clicked()
{
	scheduleW = new View_Schedule(this);
	scheduleW->show(); 

	
}