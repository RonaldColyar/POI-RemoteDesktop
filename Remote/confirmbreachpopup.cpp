#include "confirmbreachpopup.h"
#include "ui_confirmbreachpopup.h"

ConfirmBreachPopup::ConfirmBreachPopup(RequestManager RM,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmBreachPopup)
{
    ui->setupUi(this);
}

ConfirmBreachPopup::~ConfirmBreachPopup()
{
    delete ui;
}
