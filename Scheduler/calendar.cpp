#include "calendar.hpp"
#include <QtWidgets/QMainWindow>
Calendar::Calendar(QWidget * parent) : 
	QMainWindow(parent),
	ui(new Ui::Calendar)
{
	ui->setupUi(this);
}

Calendar::~Calendar() {
	
}
