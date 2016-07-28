#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_view_schedule.h"

class View_Schedule : public QMainWindow {
	Q_OBJECT

public:
	View_Schedule(QWidget * parent = Q_NULLPTR);
	~View_Schedule();

	void fill_combo_boxes(); 
	void setUp_Table(); 
	void organize_Employees(); 
	QString convert_days_off(QString off); 
	void setRows();
	void set_name_column(); 
private:
	Ui::View_Schedule *ui;
private slots:
void on_viewScheduleBtn_clicked(); 
void on_actionConvert_to_Excel_triggered(); 



};
