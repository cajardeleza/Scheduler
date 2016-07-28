#include <QtWidgets/QMainWindow>
#include "employee_window.hpp"
#include "employee_calendar.hpp"


Employee_Window::Employee_Window(QWidget * parent) : 
	QMainWindow(parent),
ui(new Ui::Employee_Window)
{
	ui->setupUi(this);
}

Employee_Window::~Employee_Window() {
	delete ui; 
}
void Employee_Window::changeEvent(QEvent *e)
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

void Employee_Window::on_availabilityBtn_clicked()
{
	employee_cal = new Employee_Calendar(this); 
	employee_cal->show(); 
	
}