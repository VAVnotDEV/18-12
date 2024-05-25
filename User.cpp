#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

User::User(string name, string login, string pass) : _name(name), _login(login), _pass(pass) {}

string User::getName() {return _name;}
string User::getLogin() {return _login;}
string User::getPass() {return _pass;}

fstream& operator>>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}

ostream& operator<<(ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}
