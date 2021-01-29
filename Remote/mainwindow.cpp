#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

class AuthManager{
    bool connect_to_server(){
        return true;
    };
    void check_result(std::string result){
        if(result == "success"){

        }
        else{

        }
    }
    std::string send_code(){
        std::string result = "success";
        return result;
    };




};




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
    AuthManager auth_manager;

    
}




MainWindow::~MainWindow()
{
    delete ui;
}


