#include "stdafx.h"
#include "TWList.h"




void TWList::addN(int value)		//dodje do listy nakoñcu
{	
	if (counter == 1)
	{
		current->previous = NULL;
		current->next = NULL;
		current->value = value;
		counter++;
		top = current;
	}
	else
	{
		current = new data;
		top->next = current;
		current->previous = top;
		current->next = NULL;
		current->value = value;
		counter++;
		top = current;
	}
	
}

void TWList::addP(int value)		//dodaje do listy na pocz¹tku 
{
	if (counter == 1)
	{
		current->previous = NULL;
		current->next = NULL;
		current->value = value;
		counter++;
		bot = current;
	}
	else
	{
		current = new data;
		bot->previous = current;
		current->next = top;
		current->previous = NULL;
		current->value = value;
		counter++;
		bot = current;
	}

}

string TWList::addM(int value, int after)		//dodaje do listy w srodku 
{
	data *tmp = new data;
	tmp = bot;
	while (tmp != NULL)
	{
		if (tmp->value == after)
		{
			data *added = new data;
			added->previous = tmp;
			added->value = value;
			added->next = tmp->next;
			tmp->next = added;
			return "zostalo dodane";
		}
		tmp = tmp->next;
	}
	return "niema takiego elementu";
}

string TWList::addCount(int value, int after)	//wstawia coœ za któr¹œ liczb¹ (odlicza) nie dzia³a do pozycji 1 wiêc w MENU za-ifowaæ i urzyæ addP
{
	if (after < counter)
	{
		int c=1;				///chwilowo koncept nie dzia³aj¹cy jeszcze
		data *tmp = new data;
		tmp = bot;
		while (!tmp)
		{
			
			if (c == after)
			{
				cout << " w if ";
				data *added = new data;
				added->previous = tmp;
				added->value = value;
				added->next = tmp->next;
				tmp->next = added;
				return "zostalo dodane";
			}
			c++;
			tmp = tmp->next;
		} 
	}
	else
	{
		return "niema takiego elementu(za daleko)";
	}
}

string TWList::del(int a)			// usuwa z dowolnego miejsce w  lisci 
{
	data *tmp = bot;
	while (tmp != NULL)
	{
			
			if (tmp->value == a)		//jeœli znajdzie a
			{
				
				if (tmp->previous == NULL && tmp->next == NULL)		// jeœli tylko jeden el na liœcie
				{
					delete tmp;
					return "usunieto";
				}

				if (tmp->previous == NULL)							//jeœli szukane jest pierwsze
				{
					data *tmpN = tmp->next;
					tmpN->previous = NULL;
					bot = tmpN;
					delete tmp;
					return "usunieto";
				}

				if (tmp->next == NULL)								// jeseli szukane ostatnie
				{
					data *tmpP = tmp->previous;
					tmpP->next = NULL;
					delete tmp;
					top = tmpP;
					return "usunieto";

				}		
				if(tmp->previous != NULL && tmp->next != NULL)		//jeœli szukane w srodku
				{
					data *tmpP = tmp->previous;
					data *tmpN = tmp->next;
					tmpP->next = tmpN;
					tmpN->previous = tmpP;
					delete tmp;
					return "usunieto";
					break;
				}
				break;
			}
			
			tmp = tmp->next;
			cout << tmp;
	}
	cout << "else" << endl;
	return "brak takiej danej";
}



void TWList::firstt(int value)			//metoda do prób	
{

	
}

void TWList::printall()					//sypisuje listê w wierszu
{
	cout << endl;
	data *tmp = bot;
	cout << tmp->value << " ";

	do
	{
		tmp = tmp->next;
		cout << tmp->value << " ";
	} while (tmp->next != NULL);
	cout << endl;
}

void TWList::printlallall()		//dypisuje dok³adnie wszytko adresy previous value next i wartoœæ value
{
	cout << endl;
	data *tmp = bot;
	cout << tmp << " " << tmp->previous << " " << tmp->value << " " << tmp->next << endl; ;

	do
	{
		tmp = tmp->next;
		cout << tmp << " " << tmp->previous << " " << tmp->value << " " << tmp->next << endl; ;
	} while (tmp->next != NULL);
	cout << endl;
}

TWList::TWList()
{
	current = new data;
	counter=1;
	current->value = NULL;
	current->next = NULL;
	current->previous = NULL;
	bot = current;
	top = current;
}

TWList::TWList(int a)		// nie dzia³a nie wiem czemu ale jeœli while(plik>>zm) damy w MENU albo int main to jest ok (dopracowaæ)
{
	TWList();
	RandData randData;
	randData.zapis(a);
	std::ifstream plik;
	plik.open("dane.txt");
	int zmienna;
	while (plik >> zmienna)
	{
		cout << endl << zmienna << endl;
		this->addN(zmienna);
	}
}


TWList::~TWList()		//dopiesaæ jakies zwalnianie
{
}
