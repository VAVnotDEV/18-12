#include <fstream>
#include <iostream>
#include "Message.h"

using namespace std;

Message::Message(string text, string sender, string receiver) : _text(text), _sender(sender), _receiver(receiver) {}

string Message::getText() {return _text;}
string Message::getSender() {return _sender;}
string Message::getReceiver() {return _receiver;}

fstream& operator>>(fstream& is, Message& obj)
{
	is >> obj._text;
	is >> obj._sender;
	is >> obj._receiver;
	return is;
}

ostream& operator<<(ostream& os, const Message& obj)
{
	os << obj._text;
	os << ' ';
	os << obj._sender;
	os << ' ';
	os << obj._receiver;
	os << ' ';
	return os;

}

