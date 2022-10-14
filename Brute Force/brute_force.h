#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H
#include <customforwardlist.h>

#include <string>
#include <chrono>

enum Dictory{Numbers, UpperLit, LowerLit, All};

class Brute_Force
{
public:
    Brute_Force(std::string password);
    ~Brute_Force();

    bool SetLib(Dictory d);
    void Try_pass(int* result, int time_seconds = 0);

    unsigned long long int getCounter(){ return counter_iter;}
    int getTime(){ return time;}

private:
    CustomForwardList<char> dict;
    bool Status_lib;

    std::string cpass{};
    std::string tpass{ };

    unsigned long int counter_iter = 0;
    int time = 0;
};

#endif // BRUTE_FORCE_H
