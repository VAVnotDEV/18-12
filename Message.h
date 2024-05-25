#pragma once
#include <string>

using namespace std;

class Message
{
	private:
		string _text;
		string _sender;
		string _receiver;
	public:
		Message(string text, string sender, string receiver);

		string getText();
		string getSender();
		string getReceiver();

		friend fstream& operator>>(fstream& is, Message& obj);
		friend ostream& operator<<(ostream& os, const Message& obj);
};

