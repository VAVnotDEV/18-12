#include "obj.h"

int main()
{
    std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    std::fstream messages_file = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);

    fs::permissions("users.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
    fs::permissions("messages.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);

    User u1("Vasya", "VAS", "qwerty");
    User u2("Petya", "Pit", "1q2w3e4r");
    User u3;
    User u4;

    Message m1("Privet", "Vasya", "Petya");
    Message m2("Zdorova", "Petya", "Vasya");
    Message m3;
    Message m4;

    writeFile(user_file, u1);
    writeFile(user_file, u2);
    writeFile(messages_file, m1);
    writeFile(messages_file, m2);
    
    user_file.seekg(0,std::ios_base::beg);
    messages_file.seekg(0, std::ios_base::beg);

    readFile(user_file, u3);
    readFile(user_file, u4);
    readFile(messages_file, m3);
    readFile(messages_file, m4);    
    
    std::cout << "Users:\n" << u3 << "\n" << u4 << std::endl;
    std::cout << "Messages:\n"<< m3 << "\n" << m4 << std::endl;

    user_file.close();
    messages_file.close();

    return 0;
}