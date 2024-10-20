#ifndef READ_WRITE_H
#define READ_WRITE_H

#pragma once
#include <fstream>
#include <iostream>
#include <map>

using namespace std;


class ReadWrite {
public:
	void ReadFileData(string t_fileName, map<string, int>& t_productMap);
	void WriteFileData(string t_fileName, map<string, int> t_productMap);
	int PromptMenu();
	bool ExitPrompt(bool& t_running);
};
#endif