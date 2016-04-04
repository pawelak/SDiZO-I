#pragma once

#include "RandData.h"

class TWList
{
private:
	struct data
	{
		int value;
		data *previous;
		data *next;
	};
	data *top;
	data *bot;
	int counter;
public:
	

	
	~TWList();
	TWList();
	TWList(string source);
	void setc(int a);
	int getc();
	void printall();
	void print();
	void addE(int value);
	void addP(int value);
	void addCount(int value, int id);
	void del(int id);
	bool check(int val);
};

