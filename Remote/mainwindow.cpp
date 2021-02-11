#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "main_functionality.cpp"
#include "newentrypopup.cpp"
#include "newpersonpopup.cpp"
#include "confirmbreachpopup.cpp"
#include "sendemailpopup.cpp"


RequestManager request_manager;
//dialogs
NewPersonPopup new_person_popup(request_manager);
ConfirmBreachPopup breach_popup(request_manager);
NewEntryPopup create_entry_popup(request_manager);
SendEmailPopup send_profile_popup(request_manager);


/*
 MainWindow Holds Data on the persons/profiles
   and maps button clicks to the correct dialog.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/ronald/Git/Git Repos/POI-RemoteDesktop/Images/backgroundimage.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setStyleSheet("background-color: black;");
    setWindowTitle("??????");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BreachButton_clicked()
{
    breach_popup.setModal(true);
    breach_popup.exec();
}

void MainWindow::on_NewEntry_clicked()
{
    create_entry_popup.setModal(true);
    create_entry_popup.exec();
}


void MainWindow::on_NewPerson_clicked()
{
    new_person_popup.setModal(true);
    new_person_popup.exec();
}

void MainWindow::on_SendProfileButton_clicked()
{
    send_profile_popup.setModal(true);
    send_profile_popup.exec();
}


