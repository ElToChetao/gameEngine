#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <sstream>

bool SaveSystem::KeyExists(std::string key) {
    std::string data;
    std::ifstream file("savedData.txt");
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
bool SaveSystem::SaveExists(std::string key) {
    return KeyExists(key);
}
std::string SaveSystem::GetValue(std::string key) {
    std::string data;
    std::ifstream file("savedData.txt");
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
T SaveSystem::Load(std::string key)
{
    if (KeyExists(key)) {
        std::string data = GetValue(key);
        T ret;
        istd::stringstream iss(data);
        if (data.find("0x") != std::std::string::npos)
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
void SaveSystem::Save(T data, std::string key)
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