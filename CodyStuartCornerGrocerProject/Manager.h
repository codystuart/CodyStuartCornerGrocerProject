#pragma once

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Manager {
public:
	void DisplayQueriedItem(string t_product);
	void DisplayAllProducts();
	void DisplayHistogram();
	void SetMap(map<string, int> t_productMap);
	map<string,int> GetMap();
	bool ExitPrompt(bool& t_running);

private:
	map<string, int> m_productMap;
};

#endif
