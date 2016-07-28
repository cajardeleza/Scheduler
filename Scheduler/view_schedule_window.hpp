#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_view_schedule_window.h"

class View_Schedule_WIndow : public QMainWindow {
	Q_OBJECT

public:
	View_Schedule_WIndow(QWidget * parent = Q_NULLPTR);
	~View_Schedule_WIndow();
protected:
	void changeEvent(QEvent *e);
private:
	Ui::View_Schedule_WIndow *ui;
};
