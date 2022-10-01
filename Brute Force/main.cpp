#include <QCoreApplication>
#include <brute_force.h>
#include <iostream>
#include <vector>
#include <thread>

int main(int argc, char *argv[])
{
    std::string password;
    int seconds;
    int* result = new int();

    std::cout << "Enter your password \n";
    std::cin >> password;

    Brute_Force hack(password);
    if(hack.SetLib(All))
        std::cout << "Library installed \n";
    else
        std::cout << "Library not installed \n";

    std::cout << "Set time to try at seconds.Zero if without time\n";
    std::cin >> seconds;

    std::cout << "Please stand by...\n";
    std::thread t;
    t = std::thread(&Brute_Force::Try_pass, std::ref(hack), result, seconds);
    t.join();

    if(*result == -1)
        std::cout << "Error. Library not installed\n";
    else if(!*result)
        std::cout << "Password not fouded\n";
    else{
        std::cout << "Password fouded!\n";
        std::cout << "Time " << hack.getTime() << " seconds\n";
        std::cout << "Iteration counter " << hack.getCounter() << "\n";
    }

    std::system("pause");
    return 0;
}
