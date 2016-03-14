#pragma once

#include "RandData.h"

class TWList
{
private:
	
public:
	struct data
	{
		int value;
		data *previous;
		data *next;
	};
	data *top;
	data *bot;
	data *current;
	data *currentOld;
	int counter;
	void addN(int value);
	void addP(int value);
	string addM(int value, int after);
	string addCount(int value, int after);
	string del(int a);
	TWList();
	void firstt(int value);
	void printall();
	void printlallall();
	TWList(int value);
	~TWList();
};

