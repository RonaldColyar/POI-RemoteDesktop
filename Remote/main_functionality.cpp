
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <json/json.h>
#include <vector>
#include "main_functionality.h"




std::string received_data(SOCKET sock){
   //recv size of data first
   char buffer[1000];
   int BytesSize = recv(sock,buffer,1000,0);
   std::string stringified_size = std::string(buffer,0,BytesSize);
   //recv actual data
   char jsonBuffer[std::stoi(stringified_size)];
   int json_data = recv(sock,jsonBuffer,std::stoi(stringified_size),0);
   std::string stringifed_json = std::string(jsonBuffer,0,json_data);
  //final result
   return stringifed_json;




}
Json::Value converted_json_data(std::string data){
        Json::Value json;
        Json::CharReaderBuilder builder;
        Json::CharReader* reader = builder.newCharReader();
        std::string errors;
        reader ->parse(data.c_str(),data.c_str()+data.size(),&json,&errors);
        delete reader;
        return json;


}


   PersonData::PersonData(std::string first_param ,
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
   std::string PersonData::json_obj (){



   }





   SocketHandler::SocketHandler(){
            ip = "127.0.0.1" ;//local host
            port = 54000;
            sock = socket(AF_INET,SOCK_STREAM,0);
            version = MAKEWORD(2,2);
            startup_result = WSAStartup(version,&data);
   }



        void SocketHandler::configure_hint(){
            hint.sin_family = AF_INET;
            hint.sin_port = htons(port);
            hint.sin_addr.s_addr = inet_addr("127.0.0.1");

        }

        bool SocketHandler::send_message(std::string message){
            //size +1 due to the nature of c strings
            int send_message_result = send(sock,message.c_str(),message.size()+1,0);
            if(send_message_result == SOCKET_ERROR){
                return false;
            }
            else{
                return true;
            }

        }
        bool SocketHandler::connect_to_server(){
           SocketHandler::configure_hint();
           if(SocketHandler::sock == INVALID_SOCKET || SocketHandler::startup_result !=0 ){
               closesocket(SocketHandler::sock);
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
        bool SocketHandler::close_server_connection(){
            //send close request
            //recv status result
            //close socket connection
            return true;
        }





        void AuthManager::create_token_file(){

        };

        AuthManager::AuthManager(SocketHandler handler){
              socket_handler = handler;
        };

        std::string AuthManager::check_code_response(std::string code_input){






        };








    void ResponseManger::check_person_creation(std::string response,PersonData data){
        if(response == "ACCEPTED_CREATION"){
            //add to persosn to list
        }
        else{
            //issue
        }
    }
    void ResponseManger::check_person_deletion (std::string response , std::string first,std::string last){
        if(response == "DELETION_ACCEPTED"){
            //remove person from list
        }
        else{
            //issue
        }
    }
    void ResponseManger::check_contact_creation(std::string response , std::string email){
        if(response == "EMAIL_RECIPIENT_ADDED"){
            //add contact to list
        }
        else{
             //issue
        }
    }
    void ResponseManger::check_contact_deletion (std::string response , std::string email){

        if(response == "EMAIL_RECIPIENT_REMOVED"){


        }
        else{

        }
    }
    void ResponseManger::check_entry_creation(std::string response , std::string first , std::string last){

    }





    RequestManager::RequestManager(){
      writer = writer_builder.newStreamWriter();

    }
    RequestManager::~RequestManager(){
        delete writer;
    }
    void RequestManager::create_person(){

    }
    void RequestManager::create_entry(){

    }
    void RequestManager::create_contact(){

    }
    void RequestManager::delete_person(){

    }
    void RequestManager::delete_contact(){

    }
    void RequestManager::delete_entry(){

    }
    void RequestManager::breach(){

    }
    void RequestManager::download_profile(){

    }
    void RequestManager::edit_person(){

    }

    bool RequestManager::is_authed(std::string token){

        //send token
        //check for 'success'

    }
    void RequestManager::one_time_RUD_request(){//read update delete


    }


