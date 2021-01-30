#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>


class AuthManager{
public:
    std::string ip = "127.0.0.1" ;//local host
    int port = 54000;
    SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
    WSAData data;
    sockaddr_in hint;
    WORD version = MAKEWORD(2,2);
    int startup_result = WSAStartup(version,&data);



    void configure_hint(){
        hint.sin_family = AF_INET;
        hint.sin_port = port;

    };

    bool connect_to_server(){

       if(sock == INVALID_SOCKET || startup_result !=0){
           return false;
       }
       else{
          int  connection_result = connect(sock,(sockaddr*)&hint,sizeof(hint));
          if(connection_result == SOCKET_ERROR){
              return false;
          }
          else{
              return true;
          }
       }
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


