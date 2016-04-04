#pragma once
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>

using namespace std;

class RandData
{
private:
	int  zD, zG, ilosc;
	
public:
	void setzD(int a);
	int getzD();
	void setzG(int a);
	int getzG();
	void setilosc(int a);
	int getilosc();
	string dest, source;
	int *tab;
	void randPlik();
	RandData();
	void zapis(int a);
	int* zapisTab(int a);
	int * randTab(int a);
	void odczytZm();
	void zapis();
	~RandData();
};
