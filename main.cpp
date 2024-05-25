#include "User.h"
#include "Message.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int main()
{
	User u1("VAV", "VAV86", "qwer");
	User u2("Alex", "Alex32", "123qwe");
	
	Message m1 ("Hi, VAV", "Alex", "VAV");
	Message m2 ("Bye, Alex", "VAV", "Alex");

	fstream user_file = fstream("user.txt", ios::in | ios::out);
	fstream message_file = fstream("message.txt", ios::in | ios::out);
	
	if(!user_file)	
	user_file = fstream("user.txt", ios::in | ios::out | ios::trunc);
	
	if(!message_file)
	message_file = fstream("message.txt", ios::in | ios::out | ios::trunc);

	fs::permissions("user.txt",
			fs::perms::group_all | fs::perms::others_all,
			fs::perm_options::remove);

	fs::permissions("message.txt",
			fs::perms::group_all | fs::perms::others_all,
			fs::perm_options::remove);
	char op;
	cout << "Select command r-read or w-write\n";
	cout << "Enter w/r: "; cin >> op;
	
	switch (op)
	{
		case 'w':
			user_file << u1 << u2 << std::endl;
			message_file << m1 << m2 << std::endl;
		break;
		case 'r':
	user_file >> u1;
	user_file >> u2;
	message_file >> m1 >> m2;
	std::cout << "User 1: " << u1 << '\n' << "User 2: " << u2 << std::endl;
	std::cout << "Message 1: " << m1 << '\n' << "Message 2: " << m2 << std::endl;
	       	break;
		default:
		cout << "No command selected\n";
	}

	return 0;
}
