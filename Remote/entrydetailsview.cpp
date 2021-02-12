#include "entrydetailsview.h"
#include "ui_entrydetailsview.h"

EntryDetailsView::EntryDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryDetailsView)
{
    ui->setupUi(this);
}

EntryDetailsView::~EntryDetailsView()
{
    delete ui;
}
