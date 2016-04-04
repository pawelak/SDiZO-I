#include "stdafx.h"
#include "MENU.h"
#include "Table.h"
#include "RandData.h"
#include "TWList.h"
#include "Heap.h"
#include "RandData.h"


MENU::MENU()
{
}


void MENU::MENU1()
{
	co = 0;

	do
	{
		cout << " Wybierz strukture: (zostana one wywolane z danymi z wygenerowanego pliku)" << endl;
		cout << " 1. Tablica" << endl;
		cout << " 2. Lista " << endl;
		cout << " 3. Stos " << endl;
		cout << " 4. Generuj plik(wygeneruje co danych z pliku prop.txt" << endl;
		cin >> co;
		switch (co)
		{
		case 1:
		{
			MENUTab();
			break;
		}
		case 2:
		{
			MENUList();
			break;
		}
		case 3:
		{
			MENUHeap();
			break;
		}
		case 4:
		{
			MENURand();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			MENU1();
			break;
		}
	} while (co!=0);

	
}



void MENU::MENUTab()
{
	string adr;
	bool a = 0;
	do
	{
		cout << "Podaj nazwe pliku: (jesli widzisz to poraz kolejny to plik nie zostal znaleziony)";
		cin >> adr;
		std::ifstream file;
		file.open(adr);
		if (file.is_open())a = 1;
		file.close();
	} while (!a);
	
	Table table(adr);
	cout << endl;

	do
	{
		cout << endl;
		cout << " Wybierz opcje " << endl;
		cout << " 1. Dodaj element do tablicy" << endl;
		cout << " 2. Usun element" << endl;
		cout << " 3. Wyswietl" << endl;
		cout << " 4. Znajdz" << endl;

		cout << " 0. Exit " << endl;
		cin >> co;
		cout << endl;
		switch (co)
		{
		case 1:
		{
			int id, val;
			cout << "podaj pozycje a nastêpnie wartosc: " << endl;
			cin >> id >> val;
			table.add(val, id);
			table.printTab();
			break;
		}
		case 2:
		{
			int id;
			cout << "podaj pozycje do usuniecia: " << endl;
			cin >> id;
			table.del(id);
			table.printTab();
			break;
		}
		case 3:
		{
			table.printTab();
			break;
		}
		case 4:
		{
			int val;
			cout << "podaj szukana wartosc: " << endl;
			cin >> val;
			if (table.finde(val) != NULL)
			{
				cout << "wartosc znajduje sie na pozycji: " << table.finde(val) << endl;
			}
			else
			{
				cout << "brak takiej wartosci" << endl;
			}
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;

			break;
		}
	}while (co != 0);
	
	
}


void MENU::MENUHeap()
{

	string adr;
	bool a = 0;
	do
	{
		cout << "Podaj nazwe pliku: (jesli widzisz to poraz kolejny to plik nie zostal znaleziony)";
		cin >> adr;
		std::ifstream file;
		file.open(adr);
		if (file.is_open())a = 1;
		file.close();
	} while (!a);

	Heap myHeap(adr);	
	myHeap.fixHeap();				//u³o¿enie stosu dopalone manualnie po to ¿eby zobaczyæ w razie czego jak dzia³a
	cout << endl;

	do
	{
		cout << " Wybierz opcje " << endl;
		cout << " 1. Dodaj element do stosu" << endl;
		cout << " 2. Usun element" << endl;
		cout << " 3. Wyswietl" << endl;
		cout << " 4. Znajdz" << endl;

		cout << " 0. Exit " << endl;
		cin >> co;

		switch (co)
		{
		case 1:
		{
			int val;
			cout << "podaj wartosc: " << endl;
			cin >> val;
			myHeap.add(val);
			myHeap.print();
			break;
		}
		case 2:
		{
			
			if (myHeap.getl() == 1)
			{
				myHeap.del();
				MENU1();
				break;
			}
			else
			{
				myHeap.del();
				myHeap.print();
				break;
			}

			
		}
		case 3:
		{
			myHeap.print();
			break;
		}
		case 4:
		{
			int val;
			cout << "podaj wartosc szukana: " << endl;
			cin >> val;
			myHeap.heapCheak(val);
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;

			break;
		}
	} while (co != 0);


}

void MENU::MENUList()
{
	string adr;
	bool a = 0;
	
	{
		cout << "Podaj nazwe pliku: (jesli widzisz to poraz kolejny to plik nie zostal znaleziony)";
		cin >> adr;
		std::ifstream file;
		file.open(adr);
		if (file.is_open())a = 1;
		file.close();
	} while (!a);

	TWList tWList(adr);
	cout << endl;
	tWList.print();

	do
	{
		cout << "\n Wybierz opcje " << endl;
		cout << " 1. Dodaj element do listy" << endl;
		cout << " 2. Usun element" << endl;
		cout << " 3. Wyswietl" << endl;
		cout << " 4. Znajdz" << endl;

		cout << " 0. Exit " << endl;
		cin >> co;

		switch (co)
		{
		case 1:
		{
			int id, val;
			cout << "podaj pozycje a nastêpnie wartosc: " << endl;
			cin >> id >> val;
			if (id==0)
			{
				tWList.addP(val);
			}
			if (id==tWList.getc())
			{
				tWList.addE(val);
			}
			else
			{
				tWList.addCount(val, id);
			}
			tWList.print();
			break;
		}
		case 2:
		{
			int id;
			cout << "podaj id wartosci usunêcia: " << endl;
			cin >> id;
			tWList.del(id);
			tWList.print();
			break;
		}
		case 3:
		{
			tWList.print();
			break;
		}
		case 4:
		{
			int val;
			cout << "podaj szukan¹ wartosc: " << endl;
			cin >> val;
			tWList.check(val);
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			break;
		}
	}while (co != 0);


}


void MENU::MENURand()
{
	RandData randData;
	randData.odczytZm();
	randData.randPlik();
}

MENU::~MENU()
{
}
