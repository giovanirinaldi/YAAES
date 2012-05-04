#include "dialogkeyschedule.h"
#include "ui_dialogkeyschedule.h"

DialogKeySchedule::DialogKeySchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogKeySchedule)
{
    ui->setupUi(this);
}

DialogKeySchedule::~DialogKeySchedule()
{
    delete ui;
}
