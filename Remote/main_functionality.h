#ifndef MAIN_FUNCTIONALITY_H
#define MAIN_FUNCTIONALITY_H

#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <json/json.h>
#include <vector>


class PersonData{ //creation/update


public:
    std::string first;
    std::string last;
    std::string location;
    std::string height;
    std::string race;
    std::vector<std::vector<std::string>> entries;
   PersonData(std::string first_param ,
              std::string last_param,
              std::string location_param,
              std::string height_param,
              std::string race_param,
              std::vector<std::vector<std::string>> entry_data);




};


class SocketHandler {

  private:
        std::string ip;
        int port ;

        WSAData data;
        sockaddr_in hint;
        WORD version ;
        std::string access_code;
        int startup_result;
        void configure_hint();
  public:
        SOCKET sock ;
        bool connect_to_server();
        bool close_server_connection();
        SocketHandler();
        bool send_message(std::string message);

};



class AuthManager{
  private:

        void create_token_file();




  public:
        SocketHandler socket_handler;
        AuthManager(SocketHandler handler);
        std::string check_code_response(std::string code_input);
};

class InterfaceUpdater{




};

class ResponseManger{


 public:
    InterfaceUpdater interface_updater;

    void check_person_creation(std::string response,PersonData data);
    void check_person_deletion (std::string response , std::string first,std::string last);
    void check_contact_creation(std::string response , std::string email);
    void check_contact_deletion (std::string response , std::string email);
    void check_entry_creation(std::string response , std::string first , std::string last);
    void check_entry_deletion(std::string response,std::string label);
    void check_breach_status (std::string response);


};
class RequestManager{

public:
    RequestManager();
    ~RequestManager();
    SocketHandler socket_handler;
    AuthManager auth_manager = AuthManager(socket_handler);
    ResponseManger response_manager;
    Json::StreamWriterBuilder writer_builder;
    Json::StreamWriter * writer;
    void create_person(PersonData person,std::string token);
    void append_person_keys(Json::Value &root);
    void add_person_values(PersonData person,Json::Value& root,std::string token,std::string type);
    void create_entry(PersonData person,std::string token,std::string desc,std::string label);
    void append_person_modification_keys(Json::Value &root);
    void create_contact(std::string email, std::string email_name,std::string token);
    void delete_person(PersonData person,std::string token);
    void delete_contact(std::string token, std::string nickname);
    void delete_entry(std::string token, std::string label);
    void breach(std::string token , std::string code);
    std::string server_response(std::string json);
    void download_profile();

    void edit_person(PersonData person,std::string token);
    void send_data_size();
    void one_time_RUD_request();

  };

#endif // MAIN_FUNCTIONALITY_H
