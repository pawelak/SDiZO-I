#pragma once
class Table
{
public:
	int *tab;
	int tabSize;
	void printTab();
	void del(int a);
	void add(int co, int id);
	Table();
	Table(int a);
	~Table();
};

