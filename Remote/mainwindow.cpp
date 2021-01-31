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
    std::string access_code;
    int startup_result = WSAStartup(version,&data);



    void configure_hint(){
        hint.sin_family = AF_INET;
        hint.sin_port = port;

    };

    bool connect_to_server(){

       if(sock == INVALID_SOCKET || startup_result !=0 ){
           closesocket(sock);
           WSACleanup();
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
    //Result from 'send_code'
    //store server auth token locally
    void check_result(std::string result){
        if(result == "success"){
            int token_bytes = recv();
            //write token to local file

        }
        else{
            //update gui with error
        }
    }
    std::string send_code(){
        std::string result;
        int send_message_result = send();
        if(send_message_result == SOCKET_ERROR){
            result = "error";
        }
        else{
            int data_size = recv();
            int actual_data  = recv();
            if (actual_data > 0 ){
                result = std::string(); //convert actual data to
            }



        }
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


