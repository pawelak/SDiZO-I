#include "stdafx.h"
#include "RandData.h"



void RandData::setzD(int a)
{
	zD = a;
}

int RandData::getzD()
{
	return zD;
}

void RandData::setzG(int a)
{
	zG = a;
}

int RandData::getzG()
{
	return zG;
}

void RandData::setilosc(int a)
{
	ilosc = a;
}

int RandData::getilosc()
{
	return ilosc;
}

void RandData::randPlik()
{
	string linia;
	fstream plik;
	srand(time(NULL));

	plik.open(source, ios::out | ios::trunc);
	if (plik.good() == true)
	{
		std::string str = std::to_string(ilosc);
		plik << str + " ";
		int liczba;
		for (int i = 0; i < ilosc; i++)
		{
			liczba = ((rand() % zG) + zD);
			std::string str = std::to_string(liczba);
			plik << str + " ";
		}
		plik.close();
	}
}


int* RandData::randTab(int a)
{
	srand(time(NULL));
	int liczba;

	for (int i = 0; i < a; i++)
	{
		liczba = ((rand() % zG) + zD);
		tab[i] = liczba;
	}
	return tab;
		
}

void RandData::odczytZm()
{
	std::ifstream file;
	file.open("prop.txt");
	if (file.is_open())
	{
		file >> dest;
		if (file.fail()) cout << "wystapi³ b³ad zwiazany z danymi w pliku prop.txt 1" << endl;
		file >> source;
		if (file.fail()) cout << "wystapi³ b³ad zwiazany z danymi w pliku prop.txt 2" << endl;
		file >> ilosc;
		if (file.fail()) cout << "wystapi³ b³ad zwiazany z danymi w pliku prop.txt 3" << endl;
		file >> zD;
		if (file.fail()) cout << "wystapi³ b³ad zwiazany z danymi w pliku prop.txt 4" << endl;
		file >> zG;
		if (file.fail()) cout << "wystapi³ b³ad zwiazany z danymi w pliku prop.txt 5" << endl;

		//cout << dest << " " << source << " " << ilosc << " " << zD << " " << zG << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
	
}




RandData::RandData()
{
}

RandData::~RandData()
{
}
