#pragma once
#include <map>
#include <iostream>
using std::map;

class MetricRegister
{
private:
	MetricRegister* instance = NULL;
	map<int, std::pair<int, int>> metrics;

public:
	MetricRegister* getInstance() 
	{
		if (!this->instance)
		{
			this->instance = new MetricRegister();
			
		}
		return this->instance;

	}
	bool add_metr(int resp_t, int wait_t, int key)
	{
		std::pair<int, int> newPair{ resp_t, wait_t };
		this->metrics[key] = newPair;

		return true;
	}

	bool show_metr() 
	{
		for (const auto& entry : this->metrics) 
		{
			std::cout << "{" << entry.first << ", " << entry.second.first << ", " << entry.second.second << "}" << std::endl;
		}
		return true;
	}

	int count_cometr(int key)
	{
		if (this->metrics.find(key) != this->metrics.end())
		{
			return this->metrics.at(key).first + this->metrics.at(key).second;
		}
		return 0;
	}
};

