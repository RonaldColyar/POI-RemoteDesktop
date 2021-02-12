#ifndef CONFIRMBREACHPOPUP_H
#define CONFIRMBREACHPOPUP_H

#include <QDialog>
#include "main_functionality.h"
namespace Ui {
class ConfirmBreachPopup;
}

class ConfirmBreachPopup : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmBreachPopup(RequestManager RM,QWidget *parent = nullptr);
    ~ConfirmBreachPopup();

private:
    Ui::ConfirmBreachPopup *ui;
};

#endif // CONFIRMBREACHPOPUP_H
