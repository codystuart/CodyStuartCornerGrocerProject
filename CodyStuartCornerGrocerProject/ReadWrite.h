#ifndef READ_WRITE_H
#define READ_WRITE_H

#pragma once
#include <fstream>
#include <iostream>
#include <map>

using namespace std;


class ReadWrite {
public:
	void ReadFileData(string fileName, map<string, int>& productMap);
	void WriteFileData(string fileName, map<string, int> productMap);
};
#endif