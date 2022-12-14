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
    CustomForwardList<char> _cpass, _tpass;

    std::string cpass{};

    CustomForwardList<char> StrToCust(std::string str);

    unsigned long int counter_iter = 0;
    int time = 0;
    bool Status_lib;

};

#endif // BRUTE_FORCE_H
