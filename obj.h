#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class User
{
public:
    User() = default;
    User(std::string name, std::string login, std::string pass);

    friend std::fstream& operator>>(std::fstream& is, User& obj);
    friend std::ostream& operator << (std::ostream& os, const User& obj);

private:
    std::string _name;
    std::string _login;
    std::string _pass;
};

class Message
{
public:
    Message() = default;
    Message(std::string text, std::string sender, std::string receiver);

    friend std::fstream& operator>> (std::fstream& is, Message& obj);
    friend std::ostream& operator << (std::ostream& os, const Message& obj);

private:
    std::string _text;
    std::string _sender;
    std::string _receiver;
};

template <class T>
bool readFile(std::fstream& file, T& obj)
{
    if(!file.is_open())
    {
        
        std::cout << "Could not open file for read!\n";
        return false;
    }

    
    file >> obj;    
    return true;    
}

template <class T>
bool writeFile(std::fstream& file, T& obj)
{
    if(!file.is_open())
    {
        std::cout << "Could not open file for write!\n";
        return false;
    }

        file << obj << std::endl;
        return true;    
}