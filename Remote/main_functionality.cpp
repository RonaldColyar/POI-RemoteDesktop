
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <json/json.h>
#include <vector>





class PersonData{ //creation/update
    std::string first;
    std::string last;
    std::string location;
    std::string height;
    std::string race;
    std::vector<std::vector<std::string>> entries;

public:
   PersonData(std::string first_param ,
              std::string last_param,
              std::string location_param,
              std::string height_param,
              std::string race_param,
              std::vector<std::vector<std::string>> entry_data)

   {
     first = first_param;
     last = last_param;
     location = location_param;
     height = height_param;
     race = race_param;
     entries = entry_data;
   }
   //for person modification/creation
   std::string json_obj (){




   }



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





  public:
        SocketHandler socket_handler;
        AuthManager(SocketHandler handler){
              socket_handler = handler;
        };

        //Result from 'send_code'
        //store server auth token locally
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


};

class InterfaceUpdater{




};

class ResponseManger{


 public:
    InterfaceUpdater interface_updater;

    void check_person_creation(std::string response,DataForUserCreation data){
        if(response == "ACCEPTED_CREATION"){
            //add to persosn to list
        }
        else{
            //issue
        }
    }
    void check_person_deletion (std::string response , std::string first,std::string last){
        if(response == "DELETION_ACCEPTED"){
            //remove person from list
        }
        else{
            //issue
        }
    }
    void check_contact_creation(std::string response , std::string email){
        if(response == "EMAIL_RECIPIENT_ADDED"){
            //add contact to list
        }
        else{
             //issue
        }
    }
    void check_contact_deletion (std::string response , std::string email){

        if(response == "EMAIL_RECIPIENT_REMOVED"){


        }
        else{

        }
    }
    void check_entry_creation(std::string response , std::string first , std::string last){

    }



};
class RequestManager{

public:
    SocketHandler socket_handler;
    AuthManager auth_manager = AuthManager(socket_handler);
    ResponseManger response_manager;

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
