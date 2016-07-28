#include "view_schedule_window.hpp"

View_Schedule_WIndow::View_Schedule_WIndow(QWidget * parent) :
	QMainWindow(parent),
	ui(new Ui::View_Schedule_WIndow)
	{
	ui->setupUi(this);
}

View_Schedule_WIndow::~View_Schedule_WIndow() {
	delete ui; 
}
void View_Schedule_WIndow::changeEvent(QEvent *e)
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
