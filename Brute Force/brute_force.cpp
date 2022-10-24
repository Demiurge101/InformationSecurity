#include "brute_force.h"

Brute_Force::Brute_Force(std::string password)
{
    Status_lib = false;
    cpass = password;
}

Brute_Force::~Brute_Force()
{
    cpass.clear();
    dict.clear_all();
}

CustomForwardList<char> Brute_Force::StrToCust(std::string str)
{
    CustomForwardList<char> temp;
    int size = str.size();
    for(int i = 0; i < size; i++)
        temp.push_back(str[i]);
    return temp;
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

    dict.push_back();
    Status_lib = true;
    return true;
    }
    else
        return false;
}

void Brute_Force::Try_pass(int *result, int time_seconds)
{
    _cpass = StrToCust(cpass);
    if(!Status_lib)
        *result = -1;
    else{
    _tpass.push_back();
    auto begin = std::chrono::high_resolution_clock::now();

    for(counter_iter = 0; _tpass != _cpass; counter_iter++){
        _tpass.first->Value = (++dict).temp->Value;
            for(int j = 0; j < _tpass._size; j++){
                if(_tpass[j]->Value == dict.last->Value){
                    if(_tpass[j + 1] == nullptr){
                        _tpass.push_back();
                        for(int k = 0; k < _tpass._size; k++)
                            _tpass[k]->Value = dict.first->Value;
                    }
                    else{
                        _tpass[j+1]->Value = dict.find(_tpass[j+1]->Value)->next->Value;
                        _tpass[j]->Value = dict.first->Value;
                    }
                    }
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
