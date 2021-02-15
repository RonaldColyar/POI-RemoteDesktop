
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <json/json.h>
#include <vector>
#include "main_functionality.h"




std::string received_data(SOCKET sock){//for Reading person data
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

std::string received_response(SOCKET sock){//for simple status responses
    char buffer [1000];
    int response = recv(sock,buffer,1000,0);
    return std::string(buffer,0,response);

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
    std::string RequestManager::server_response(std::string json ){
        int size = json.length();
        //sending results
        bool size_result = socket_handler.send_message(std::to_string(size));
        bool data_result = socket_handler.send_message(json);
        if(size_result == false || data_result == false){
            return "SENDING_ERROR";
        }
        else{
            return received_response(socket_handler.sock);
        }

    }

    RequestManager::~RequestManager(){
        delete writer;
    }
    void RequestManager::create_person(PersonData person,std::string token){
        Json::Value root;
        append_person_keys(root);
        add_person_values(person,root,token,"PROFILE_CREATION");

    }
    void RequestManager::append_person_keys(Json::Value& root){
        append_person_modification_keys(root);
        root.append("location");
        root.append("race");
        root.append("entries");

    }
    //used for create/update
    void RequestManager::add_person_values(PersonData person,
                                           Json::Value& root,
                                           std::string token,
                                           std::string type){
        root["type"]  = type;
        root["token"] = token;
        root["first"] = person.first;
        root["last"] = person.last;
        root["location"] = person.location;
        root["race"] = person.race;
        //implement entries conversion!

    }
    void RequestManager::create_entry(PersonData person,
                                      std::string token,
                                      std::string desc,
                                      std::string label
                                      ){
        Json::Value root;
        root.append("data");
        root.append("label");
        append_person_modification_keys(root);
        root["first"] = person.first;
        root["last"] = person.last;
        root["type"] = "ENTRY_REQUEST";
        root["data"] = desc;
        root["label"] = label;
        root["token"] = token;
    }

    void RequestManager::create_contact(std::string email, std::string email_name,std::string token){
        Json::Value root;
        root.append("type");
        root.append("token");
        root.append("email");
        root.append("email_name");
        root["type"] = "EMAIL_RECIPIENT_ADD";
        root["token"] = token;
        root["email"] = email;
        root["email_name"] = email_name;


    }
    void::RequestManager::append_person_modification_keys(Json::Value &root){
        root.append("type");
        root.append("first");
        root.append("last");
        root.append("token");
    }
    void RequestManager::delete_person(PersonData person,std::string token){
        Json::Value root;
        append_person_modification_keys(root);
        root["type"] = "REQUEST_DELETION";
        root["first"] = person.first;
        root["last"] = person.last;
        root["token"] = token;


    }
    void RequestManager::delete_contact(std::string token, std::string nickname){
        Json::Value root;
        root.append("token");
        root.append("type");
        root.append("nickname");
        root["token"] = token;
        root["type"] = "REMOVE_EMAIL_RECIPIENT";
        root["nickname"] = nickname;

    }
    void RequestManager::delete_entry(std::string token, std::string label){
        Json::Value root;
        root.append("token");
        root.append("type");
        root.append("label");
        root["token"] = token;
        root["type"] = "DELETE_ENTRY";
        root["label"] = label;

    }
    void RequestManager::breach(std::string token , std::string code){
        Json::Value root;
        root.append("token");
        root.append("type");
        root.append("code");
        root["token"] = token;
        root["code"] = code;


    }
    void RequestManager::download_profile(){

    }
    void RequestManager::edit_person(PersonData person,std::string token){
        Json::Value root;
        append_person_keys(root);
        add_person_values(person,root,token,"PROFILE_CREATION");

    }

    void RequestManager::one_time_RUD_request(){//read update delete


    }


