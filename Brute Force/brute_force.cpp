#include "brute_force.h"

Brute_Force::Brute_Force(std::string password)
{
    Status_lib = false;
    cpass = password;
}

Brute_Force::~Brute_Force()
{
    cpass.clear();
    tpass.clear();
    dict.clear();
}

bool Brute_Force::SetLib(Dictory d)
{
    if(!Status_lib){
    switch(d){
    case Numbers:
        for(char l = 48; l < 48 + 10; l++)
            dict.push_back(l);
        break;
    case UpperLit:
        for(char l = 65; l < 65 + 26; l++)
            dict.push_back(l);
        break;
    case LowerLit:
        for(char l = 97; l < 97 + 26; l++)
            dict.push_back(l);
        break;
    case All:
        for(char l = 48; l < 48 + 10; l++)
            dict.push_back(l);
        for(char l = 65; l < 65 + 26; l++)
            dict.push_back(l);
        for(char l = 97; l < 97 + 26; l++)
            dict.push_back(l);
        break;
    default:
        return false;
    }
    dict.push_back('\0');
    Status_lib = true;
    return true;
    }
    else
        return false;
}

void Brute_Force::Try_pass(int *result, int time_seconds)
{
    if(!Status_lib)
        *result = -1;
    else{
    int counter_dep = 1;
    std::string last_res{};
    last_res.resize(counter_dep);
    auto begin = std::chrono::high_resolution_clock::now();

    for(counter_iter = 0; tpass != cpass; counter_iter++){
        tpass.clear();
        tpass.resize(counter_dep);
        tpass = last_res;
        tpass[0] = dict[counter_iter%dict.size()];
            for(int j = 0; j < tpass.size(); j++){
                if(tpass[j] == dict.last()){
                    if(tpass[j + 1] == NULL){
                        counter_dep++;
                        tpass.resize(counter_dep);
                        for(int k = 0; k < tpass.size(); k++)
                            tpass[k] = dict.first();
                    }
                    else{
                        tpass[j+1] = dict[dict.indexOf(tpass[j+1])+1];
                        tpass[j] = dict.first();
                    }
                    }
                last_res.resize(counter_dep);
                last_res = tpass;
                }
         if(time_seconds){
         auto temp = std::chrono::high_resolution_clock::now();
         if(std::chrono::duration_cast<std::chrono::seconds>(temp-begin).count() >= time_seconds)
             *result = 0;
         }
    }
    if(!time_seconds){
        auto end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration_cast<std::chrono::seconds>(end-begin).count();
        *result = 1;
        }
    }
}
