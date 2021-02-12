#ifndef SENDEMAILPOPUP_H
#define SENDEMAILPOPUP_H
#include "main_functionality.h"
#include <QDialog>

namespace Ui {
class SendEmailPopup;
}

class SendEmailPopup : public QDialog
{
    Q_OBJECT

public:
    explicit SendEmailPopup(RequestManager RM,QWidget *parent = nullptr);
    ~SendEmailPopup();

private:
    Ui::SendEmailPopup *ui;
};

#endif // SENDEMAILPOPUP_H
