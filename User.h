#pragma once
#include <string>

using namespace std;

class User
{
private:
	string _name;
	string _login;
	string _pass;
public:
	User(string name, string login, string pass);
	
	string getName();
	string getLogin();
	string getPass();


	friend fstream& operator>>(fstream& is, User& obj);
	friend ostream& operator<<(ostream& os, const User& obj);
};
