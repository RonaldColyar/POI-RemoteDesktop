#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "main_functionality.cpp"






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


