
#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <sstream>

bool SaveSystem::KeyExists(string key) {
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
bool SaveSystem::SaveExists(string key) {
    return KeyExists(key);
}
string SaveSystem::GetValue(string key) {
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
template <typename T>
T SaveSystem::Load(string key)
{
    if (KeyExists(key)) {
        string data = GetValue(key);
        T ret;
        istringstream iss(data);
        if (data.find("0x") != std::string::npos)
        {
            iss >> hex >> ret;
        }
        else
        {
            iss >> dec >> ret;
        }

        if (iss.fail())
        {
            std::cout << "Convert error: cannot convert string '" << data << "' to value" << std::endl;
            return T();
        }
        return ret;
    }
    return T();
}

template <typename T>
void SaveSystem::Save(T data, string key)
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