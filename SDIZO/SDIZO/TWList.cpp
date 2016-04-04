#include "stdafx.h"
#include "TWList.h"


TWList::TWList()
{
	data *current = new data;
	counter = 0;
	current->value = NULL;
	current->next = NULL;
	current->previous = NULL;
	bot = current;
	top = current;
}

TWList::TWList(string source)				//robi obiekt w kt�rym jest losowanie ustalonej wielko�ci i zapisywanie do pliku a potem zapisuje do tablicy
{
	std::ifstream file;
	file.open(source);
	int val;
	if (file.is_open())						//w zasadzie nie potrzebne bo mam ju� kontrol� na tym 
	{
		file >> counter;
		if (file.fail()) cout << "File error - READ SIZE" << endl;
		else
		{
			file >> val;
			data *tmp = new data;
			tmp->value = val;
			tmp->previous = NULL;
			tmp->next = NULL;
			bot = tmp;
			top = tmp;

			while (file >> val)
			{
				data *added = new data;
				tmp->next = added;
				added->previous = tmp;
				added->value = val;
				added->next = NULL;
				tmp = added;

			}
			top = tmp;
			file.close();
		}
	}
	else
		cout << "File error - OPEN" << endl;
}

void TWList::setc(int a)
{
	counter = a;
}

int TWList::getc()
{
	return counter;
}

void TWList::print()					//wypisuje wszytkie pozycje na li�cie
{
	cout << endl;
	data *tmp = bot;

	while (tmp != NULL)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
	delete tmp;
}

void TWList::printall()					//wypisuje wszytkie pozycje na li�cie
{
	cout << endl;
	data *tmp = bot;

	while (tmp != NULL)
	{
		cout << tmp->value << " " << tmp->previous << " " << tmp << " " << tmp->next << " " << counter <<  endl;
		tmp = tmp->next;
	}
	cout << endl;
	delete tmp;
}


void TWList::addE(int value)		//dodje do listy nako�cu
{	
	if (counter == 0)
	{
		
		top->value = value;
		counter++;
	}
	else
	{
		data *tmp = new data;
		counter++;
		tmp->previous = top;
		tmp->value = value;
		tmp->next = NULL;
		top->next = tmp;
		top = tmp;
	}
}

void TWList::addP(int value)		//dodaje do listy na pocz�tku 
{
	if (counter == 0)
	{
		bot->value = value;
		counter++;
	}
	else
	{
		data *tmp = new data;
		counter++;
		tmp->previous = NULL;
		tmp->value = value;
		tmp->next = bot;
		bot->previous = tmp;
		bot = tmp;
	}

}



void TWList::addCount(int value, int id)	//wstawia co� za kt�r�� liczb� (odlicza) nie dzia�a do pozycji 1 wi�c w MENU za-ifowa� i urzy� addP
{
	if (id < counter)
	{		
		data *tmp = new data;
		tmp = bot;
		for (int i = 0; i < counter; i++)
		{
			if (i==id)
			{
				
				data *added = new data;
				tmp->previous->next = added;
				added->previous = tmp->previous;
				added->next = tmp;
				added->value = value;
				tmp->previous = added;
				counter++;
				break;
			}
			tmp = tmp->next;
		}
	}
}



void TWList::del(int id)			// usuwa z dowolnego miejsce w  lisci 
{
	data *tmp = bot;
	if (counter == 1)
	{
		counter = 0;
		delete tmp;			//je�li lista ma jeden el
	}
	if (id == 0)							//jeli uwuwamy pierwszy el
	{
		tmp = bot;
		bot = bot->next;
		bot->previous = NULL;
		counter--;
		delete tmp;
	}
	if (counter == id)						//je�li ostatni
	{
		tmp = top;
		top = top->previous;
		top->next = NULL;
		counter--;
		delete tmp;
	}
	if (counter > id && 0 < id)				//ze srodka po id 
	{
		tmp = bot;
		for (int i = 0; i < counter; i++)
		{
			if (id==i)
			{
				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;
				delete tmp;
				counter--;
				break;
			}
			tmp = tmp->next;
		}
	}
}


bool TWList::check(int val)					//czy jest warto�� w tablicy
{
	data *tmp = bot;
	for (int i = 0; i < counter; i++)
	{
		if (tmp->value==val)
		{
			return true;
		}
		tmp = tmp->next;
	}

	return false;
}


TWList::~TWList()		//dopiesa� 
{
	data *tmp = top;
	while (bot == NULL)
	{
		if (tmp->previous != NULL)
		{
			tmp = tmp->previous;
			delete tmp->next;
		}
		else delete bot;

	}
}
