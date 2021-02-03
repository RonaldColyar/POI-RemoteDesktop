
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

/*

Socket Handler handles the creation
of a socket

*/


class PersonData{

public:
    std::string first;
    std::string last;
    std::string location;
    std::string height;
    std::string race;

};
class SocketHandler {

  private:
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
  public:

        bool connect_to_server(){
           configure_hint();
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

        //terminates session and  removes session
        bool close_server_connection(){
            //send close request
            //recv status result
            //close socket connection
            return true;
        }

};



class AuthManager{
  private:

        void create_token_file(){

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


        std::string send_code(std::string){
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
    public:
        AuthManager(SocketHandler handler){
            SocketHandler socket_handler  = handler;
        };
        void send_and_check(std::string code){
            check_result(send_code(code));
        }




};
class RequestManager{

public:

    RequestManager(){
        SocketHandler socket_handler;
        AuthManager auth_manager = AuthManager(socket_handler);
    }
    void create_person(){

    }
    void create_entry(){

    }
    void create_contact(){

    }
    void delete_person(){

    }
    void delete_contact(){

    }
    void delete_entry(){

    }
    void breach(){

    }
    void download_profile(){

    }
    void edit_person(){

    }

    void send_data_size(){
        //send stringified int of bytes
    }

    bool is_authed(std::string token){

        //send token
        //check for 'success'

    }
    void one_time_RUD_request(){//read update delete


    }

  };
