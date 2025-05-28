#include "obj.h"

User::User(std::string name, std::string login, std::string pass) : _name(name), _login(login), _pass(pass) {}

Message::Message(std::string text, std::string sender, std::string receiver) : _text(text), _sender(sender), _receiver(receiver) {}

std::fstream& operator>>(std::fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;

    return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;

    return os;
}

std::fstream& operator>>(std::fstream& is, Message& obj)
{
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;

    return os;
}