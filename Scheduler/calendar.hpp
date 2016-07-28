#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_calendar.h"

class Calendar : public QMainWindow {
	Q_OBJECT

public:
	Calendar(QWidget * parent = Q_NULLPTR);
	~Calendar();

private:
	Ui::Calendar *ui;
};
