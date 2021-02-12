#include "sendemailpopup.h"
#include "ui_sendemailpopup.h"

SendEmailPopup::SendEmailPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendEmailPopup)
{
    ui->setupUi(this);
}

SendEmailPopup::~SendEmailPopup()
{
    delete ui;
}
