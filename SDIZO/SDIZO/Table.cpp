#include "stdafx.h"
#include "Table.h"
#include "RandData.h"

int Table::tabSizeget()
{
	return tabSize;
}

void Table::tabSizeSet(int a)
{
	tabSize=a;
}

void Table::printTab()			// wypisuje tablice
{
	for (int i = 0; i < tabSize; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}

void Table::del(int id)			//usuwa dowolny element tablicy ale z malloc i free (mo¿e warto zmieniæ na new delete)
{
	int counter = 0;
	tabSize = tabSize - 1;
	//int *tabhelp = (int*)malloc(tabSize*sizeof(int));
	int *tabhelp = new int[tabSize];
	for (int i = 0; i < tabSize+1; i++)
	{
		if (id == i) counter = 1;
		tabhelp[i] = tab[i + counter];
	}
	//free(tab);
	delete[]tab;
	tab = tabhelp;
	
}

void Table::add(int value, int id)			//dodaje element do tablicy i ja relokuje ale w praktyce to wywala i robi now¹ (na malcach)
{
	int counter = 0;
	tabSize = tabSize + 1;
	//int *tabhelp = (int*)malloc(tabSize*sizeof(int));
	int *tabhelp = new int[tabSize];
	for (int i = 0; i < tabSize; i++)
	{
		if (id == i)
		{
			tabhelp[i] = value;
			i++;
			counter = 1;
		}
		tabhelp[i] = tab[i-counter];
	}
	//free(tab);
	delete[]tab;
	tab = tabhelp;
}


int Table::finde(int a)
{
	for (int i = 0; i < tabSize; i++)
	{
		if (a == tab[i])return i;
	}
	return NULL;
}



Table::Table()
{
	tab = new int[0];
	tabSize=0;
}

Table::Table(string source)				//robi obiekt w którym jest losowanie ustalonej wielkoœci i zapisywanie do pliku a potem zapisuje do tablicy
{
	std::ifstream file;
	file.open(source);
	int val;
	if (file.is_open())
	{
		file >> tabSize;
		tab = new int[tabSize];
		if (file.fail()) cout << "File error - READ SIZE" << endl;
		else
			for (int i = 0; i < tabSize; i++)
			{
				file >> val;
				if (file.fail())
				{
					cout << "File error - READ DATA" << endl;
					break;
				}
				else
					tab[i] = val;
			}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

Table::Table( int ile)				//kopiuje z tabliczy 
{
	tabSize = ile;
	tab = new int[ile];
	int zmienna;
	RandData randData;
	int *tabhelp = randData.randTab(ile);
	for (int i = 0; i < ile; i++)
	{
		tab[i] = tabhelp[i];
	}
}


Table::~Table()
{
	delete []tab;
}
