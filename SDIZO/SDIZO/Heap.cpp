#include "stdafx.h"
#include "Heap.h"
#include "RandData.h"



void Heap::setl(int a)
{
	lenght = a;
}

int Heap::getl()
{
	return lenght;
}

Heap::Heap(int a)
{
	myHeap = new int[a];
	RandData radnData;
	radnData.randTab(a);
	std::ifstream plik;
	plik.open("dane.txt");
	for (int i = 0; i < a; i++)
	{
		plik >> myHeap[i]; // tu coœ ze sprawdzaniem zgodnoœci sterna mówi³ if(pobieranie.fail) chyba ze strumienia std:: 
	}
	lenght = a;
}

Heap::Heap(string source)
{
	std::ifstream file;
	file.open(source);
	int val;
	if (file.is_open())
	{
		file >> lenght;
		myHeap = new int[lenght];
		if (file.fail()) cout << "File error - READ SIZE" << endl;
		else
			for (int i = 0; i < lenght; i++)
			{
				file >> val;
				if (file.fail())
				{
					cout << "File error - READ DATA" << endl;
					break;
				}
				else
				{
					myHeap[i] = val;
				}
					
			}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}


void Heap::fixHeap()
{
	int right, left, tmp;
	for (int i = (lenght ) / 2; i >= 0; --i)
	{
		left = ((i * 2) + 1);
		right = ((i * 2) + 2);
		tmp = 0;

		if ((myHeap[i] < myHeap[left] || myHeap[i] < myHeap[right]) && right<lenght)
		{

			if (myHeap[right] < myHeap[left])
			{

				swap(myHeap[left], myHeap[i]);
				down(left);
			}
			else
			{
				swap(myHeap[right], myHeap[i]);
				down(right);
			}
		}
		else if (left==lenght-1)
		{
			if (myHeap[left] > myHeap[i])
			{
				swap(myHeap[left], myHeap[i]);	
			}
		}
	}
}


void Heap::down(int id)
{
	int left = ((id * 2) + 1);
	int right = ((id * 2) + 2);
	int tmp;

	while (right <= lenght-1)
	{
		if (myHeap[left] >= myHeap[right])tmp = left;
		else if (myHeap[left] < myHeap[right])tmp = right;
		swap(myHeap[id], myHeap[tmp]);
		id = tmp;
		left = ((id * 2) + 1);
		right = ((id * 2) + 2);
	}

	if (left == lenght - 1)
		if ((myHeap[id] < myHeap[left]))
		{
			swap(myHeap[left], myHeap[id]);
		}

}
	
	
int Heap::findeChild(int a)
{
	if (2 * a + 2 <= lenght)return 2 * a + 1;
	else if (2 * a + 1 <= lenght)return 2 * a + 1;
	else return NULL;
}

void Heap::print()
{
	int border = 4;
	int ile = 23;
	int count =0 ;
	if (lenght>=0)	cout << setw(58) << myHeap[0] << endl;
	for (int i = 0; i < 2; i++)
	{
		if (1+ i < lenght)cout << setw(38) << myHeap[i + 1];
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (3 + i < lenght)cout << setw(23) << myHeap[3 + i];	
	}
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		if (8 + i < lenght)cout << setw(13) << myHeap[8 + i];
	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (17 + i < lenght)cout << setw(7) << myHeap[17 + i];
		
	}
	cout << endl;
	for (int i = 0; i < 32; i++)
	{
		if (33 + i < lenght)cout << setw(4) << myHeap[33 + i];
	}
	cout << endl;
}

void Heap::fixUp(int a)
{
	int tmp;
	do
	{
		tmp = (a - 1) / 2;
		if (myHeap[tmp] < myHeap[a])
		{
			swap(myHeap[tmp], myHeap[a]);
		}
		a = tmp;
	} while (tmp != 0);
}

void Heap::add(int value)
{
	lenght++;
	int *tab = new int[lenght];
	
	for (int i = 0; i < lenght-1; i++)
	{
		tab[i] = myHeap[i];
	}
	tab[lenght-1] = value;
	swap(tab, myHeap);
	delete[]tab;
	fixUp(lenght-1);
}

void Heap::del()
{
	
	if (lenght == 1)
	{
		cout << endl << "usunoles tablice" << endl;
		delete[]myHeap;
	}
	else
	{
		lenght--;
		int *tab = new int[lenght];
		for (int i = 0; i < lenght; i++)
		{
			tab[i] = myHeap[i];
		}
		swap(tab, myHeap);
		delete[]tab;
	}
	
}

void Heap::delMiddle(int id)
{
	if (id < lenght)
	{
		swap(myHeap[id], myHeap[lenght]);
	}
	del();
	down(id);
	fixUp(id);

	
}

bool Heap::heapCheak(int a)
{
	for (int i = 0; i < lenght; i++)
	{
		if (myHeap[i] == a)
		{
			//cout << "w kopcu jest taki element" << endl;
			return true;
		}
	}
	//cout << "w niema kopcu jest taki element" << endl;
	return false;
}




Heap::Heap()
{
}



Heap::~Heap()
{
	delete[]myHeap;
}	
