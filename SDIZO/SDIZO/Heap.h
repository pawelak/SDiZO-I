#pragma once
#include <conio.h>
#include <iomanip>

class Heap
{
private:
	int lenght;
public:
	void setl(int a);
	int getl();
	int *myHeap;
	Heap(int a);
	Heap(string str);
	void fixHeap();
	void down(int id);
	int findeChild(int a);
	void print();
	void fixUp(int a);
	void del();
	void delMiddle(int id);
	bool heapCheak(int a);
	void add(int a);
	Heap();
	~Heap();
};

