#pragma once
class Table
{
private:
	int tabSize;
public:
	int *tab;
	int tabSizeget();
	void tabSizeSet(int a);
	void printTab();
	void del(int a);
	void add(int co, int id);
	int finde(int a);

	Table();
	Table(int a);
	Table(string source);



	~Table();
};

