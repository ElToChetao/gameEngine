#pragma once
#include "SaveSystem.h"

bool KeyExists(string key) {
    string data;
    ifstream file(folderPath);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, data);
            if (data.find(key) == 0) 
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
}
bool SaveExists(string key) {
    return KeyExists(key);
}
string GetValue(string key) {
    string data;
    ifstream file(folderPath);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, data);
            if (data.substr(0, data.find(':'))._Equal(key)) {
                file.close();
                data.erase(0, data.find(':') + 1);
                return data;
            }
        }
        file.close();
        return "";
    }
}

string Load(string key)
{
    if (KeyExists(key)) {
        return GetValue(key);
    }
    return "";
}

template <typename T>
void Save(T data, string key)
{
    if (!KeyExists(key)) {
        ofstream file;
        file.open(folderPath, ios_base::app);
        file << key + ':';
        file << data;
        file << '\n';
        file.close();
    }
}