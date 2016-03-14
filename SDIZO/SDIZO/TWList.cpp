#include "stdafx.h"
#include "TWList.h"




void TWList::addN(int value)		//dodje do listy nako�cu
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

void TWList::addP(int value)		//dodaje do listy na pocz�tku 
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

string TWList::addCount(int value, int after)	//wstawia co� za kt�r�� liczb� (odlicza) nie dzia�a do pozycji 1 wi�c w MENU za-ifowa� i urzy� addP
{
	if (after < counter)
	{
		int c=1;				///chwilowo koncept nie dzia�aj�cy jeszcze
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
			
			if (tmp->value == a)		//je�li znajdzie a
			{
				
				if (tmp->previous == NULL && tmp->next == NULL)		// je�li tylko jeden el na li�cie
				{
					delete tmp;
					return "usunieto";
				}

				if (tmp->previous == NULL)							//je�li szukane jest pierwsze
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
				if(tmp->previous != NULL && tmp->next != NULL)		//je�li szukane w srodku
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



void TWList::firstt(int value)			//metoda do pr�b	
{

	
}

void TWList::printall()					//sypisuje list� w wierszu
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

void TWList::printlallall()		//dypisuje dok�adnie wszytko adresy previous value next i warto�� value
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

TWList::TWList(int a)		// nie dzia�a nie wiem czemu ale je�li while(plik>>zm) damy w MENU albo int main to jest ok (dopracowa�)
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


TWList::~TWList()		//dopiesa� jakies zwalnianie
{
}
