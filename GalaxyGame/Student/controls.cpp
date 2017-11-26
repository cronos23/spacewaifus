#include "controls.hh"
#include "ui_controls.h"

controls::controls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controls)
{
    ui->setupUi(this);
}

controls::~controls()
{
    delete ui;
}
