#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

class Password{
public:
    Password(int lenpass = 8);
    ~Password();
    std::string GetPass();
private:
    int lenpass;
    int temp[3];
    std::string pass;
};

int main(int argc, char *argv[])
{
    int lenpass;
    while(true){
    std::cout << "Enter legth password \n";
    std::cin >> lenpass;
    Password pw(lenpass);
    std::cout << pw.GetPass() << "\n";
    }
    system("pause");
    return 0;
}

Password::Password(int lenpass)
{
    srand(time(NULL));
    this->lenpass = lenpass;
}

Password::~Password()
{
    pass.clear();
}

std::string Password::GetPass()
{
    for(int i = 0; i < lenpass; i++){
        temp[0] = rand() % 9 + 48;
        temp[1] = rand() % 26 + 65;
        temp[2] = rand() % 26 + 97;
        pass.push_back(temp[rand() % 3]);
    }
    return pass;
}
