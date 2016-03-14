#include "stdafx.h"
#include "Table.h"
#include "RandData.h"

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
	int *tabhelp = (int*)malloc(tabSize*sizeof(int));
	for (int i = 0; i < tabSize+1; i++)
	{
		if (id == i) counter = 1;
		tabhelp[i] = tab[i + counter];
	}
	free(tab);
	tab = tabhelp;
	
}

void Table::add(int value, int id)			//dodaje element do tablicy i ja relokuje ale w praktyce to wywala i robi now¹ (na malcach)
{
	int counter = 0;
	tabSize = tabSize + 1;
	int *tabhelp = (int*)malloc(tabSize*sizeof(int));

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
	free(tab);
	tab = tabhelp;
}






Table::Table()
{
}

Table::Table(int a)				//robi obiekt w którym jest losowanie ustalonej wielkoœci i zapisywanie do pliku a potem zapisuje do tablicy
{
	tabSize = a;
	tab = (int*)malloc(tabSize*sizeof(int));
	RandData randData;
	randData.zapis(tabSize);
	std::ifstream plik;
	plik.open("dane.txt");
	int zmienna;
	for (int i = 0; i < tabSize; i++)
	{
		plik >> zmienna;
		tab[i] = zmienna;
	}
	
}


Table::~Table()
{
}
