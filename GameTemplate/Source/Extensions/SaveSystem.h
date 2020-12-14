#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string folderPath = "savedData.txt";

bool KeyExists(string key);
bool SaveExists(string key);
string GetValue(string key);
string Load(string key);

template <typename T>
void Save(T data, string key);