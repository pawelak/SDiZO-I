// SDIZO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Table.h"
#include "TWList.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "SDIZO.h"
#include "heap.h"
#include <Windows.h>
#include "MENU.h"


LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}


int main()
{











	// ---------------------------testy--------------------------

		//###################################Tablica########################################
	LARGE_INTEGER CountStart, CountEnd, freq, timeOperation;

	srand(time(NULL));
	RandData randData;
	randData.odczytZm();

	int sekundadzielnik = 1000000;
	int populacja = 0;
	int ilerazy = 100;
	string gdzie = "result.txt";

	randData.setilosc(populacja);
	fstream plik;
	plik.open(gdzie, ios::out | ios::trunc);
	// *******************************ADD*****************************************
	//-----------------------------ADD na pocz¹tku ------------------------------------ gotowy, liczy w mikto x100 na 
	for (int i = 0; i < 5; i++)
	{
		populacja = populacja + 2000;
		randData.setilosc(populacja);

		plik << "\n";

	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		Table t(randData.source);

	//		CountStart = startTimer();
	//		t.add(rand(), 0);
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart; //takie dziwne ¿eby uwzglêdnia³o moje taktowanie procesowra
	//																				//a pomno¿one razy coœ zeby mi wysz³o w wygodnej jednostce ms lub mikro s 
	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}
	//		plik.close();

		//plik << "\n" + std::to_string(populacja) + "na koncu " + "\n";

		//-----------------------------ADD na koñcu ------------------------------------

			//fstream plik;
			//plik.open(gdzie, ios::out | ios::trunc);
		//for (int i = 0; i < ilerazy; i++)
		//{
		//	randData.randPlik();
		//	Table t(randData.source);

		//	CountStart = startTimer();
		//	t.add(rand(), t.tabSizeget());
		//	CountEnd = endTimer();

		//	timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
		//	QueryPerformanceFrequency(&freq);
		//	double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart; //takie dziwne ¿eby uwzglêdnia³o moje taktowanie procesowra
		//																				  //a pomno¿one razy coœ zeby mi wysz³o w wygodnej jednostce ms lub mikro s 
		//	std::string str = std::to_string(tm);
		//	plik << str + " ";
		//}
		//plik.close();


		//-----------------------------ADD w œrodku------------------------------------

		//fstream plik;
		//plik.open(gdzie, ios::out | ios::trunc);
		/*plik << "\n" + std::to_string(populacja) + "w srodku " + "\n";

		for (int i = 0; i < ilerazy; i++)
		{
			randData.randPlik();
			Table t(randData.source);

			CountStart = startTimer();
			t.add(rand(), (rand() % populacja - 2) + 1);
			CountEnd = endTimer();

			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
			QueryPerformanceFrequency(&freq);
			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

			std::string str = std::to_string(tm);
			plik << str + " ";
		}

	}
	plik.close();
	*/
	//*************************************DEL********************************************
		//-----------------------------DEL na pocz¹tku ------------------------------------ 



	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		Table t(randData.source);

	//		CountStart = startTimer();
	//		t.del(0);
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}
	//plik.close();

//-----------------------------DEL na koñcu ------------------------------------


	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		Table t(randData.source);

	//		CountStart = startTimer();
	//		t.del(t.tabSizeget()-1);
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart; //takie dziwne ¿eby uwzglêdnia³o moje taktowanie procesowra
	//																					  //a pomno¿one razy coœ zeby mi wysz³o w wygodnej jednostce ms lub mikro s 
	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}



//	-----------------------------DEL w œrodku------------------------------------


	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		Table t(randData.source);

	//		CountStart = startTimer();
	//		t.del((rand() % populacja - 1) + 1);
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}



//*****************************szukanie***************************

	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		Table t(randData.source);

	//		CountStart = startTimer();
	//		t.finde((rand() % (randData.getzG() - randData.getzD())) +randData.getzD());
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}



	//###############################Lista##########################################

	//********************************ADD pocz¹tek*****************************

	//	for (int i = 0; i < ilerazy; i++)
	//	{

	//		randData.randPlik();
	//		TWList lista(randData.source);

	//		CountStart = startTimer();
	//		lista.addP(rand());
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}


	//-----------------------------ADD na koñcu ------------------------------------


	//	for (int i = 0; i < ilerazy; i++)
	//	{
	//		randData.randPlik();
	//		TWList lista(randData.source);

	//		CountStart = startTimer();
	//		lista.addE(rand());
	//		CountEnd = endTimer();

	//		timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
	//		QueryPerformanceFrequency(&freq);
	//		double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart; //takie dziwne ¿eby uwzglêdnia³o moje taktowanie procesowra
	//																					  //a pomno¿one razy coœ zeby mi wysz³o w wygodnej jednostce ms lub mikro s 
	//		std::string str = std::to_string(tm);
	//		plik << str + " ";
	//	}
	//}
	//plik.close();

//-----------------------------ADD w œrodku------------------------------------


		for (int i = 0; i < ilerazy; i++)
		{
			randData.randPlik();
			TWList lista(randData.source);

			CountStart = startTimer();
			lista.addCount(rand(), (rand() % populacja - 2) + 1);
			CountEnd = endTimer();

			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
			QueryPerformanceFrequency(&freq);
			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;

			std::string str = std::to_string(tm);
			plik << str + " ";
		}
	}
plik.close();

//*************************************DEL********************************************
//-----------------------------DEL na pocz¹tku ------------------------------------ 

//		for (int i = 0; i < ilerazy; i++)
//		{
//			randData.randPlik();
//			TWList lista(randData.source);
//
//			CountStart = startTimer();
//			lista.del(0);
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();



//-----------------------------DEL na koñcu ------------------------------------

//
//		for (int i = 0; i < ilerazy; i++)
//		{
//			randData.randPlik();
//			TWList lista(randData.source);
//
//			CountStart = startTimer();
//			lista.del(lista.getc());
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();


//	-----------------------------DEL w œrodku------------------------------------
//
//		for (int i = 0; i < ilerazy; i++)
//		{
//			randData.randPlik();
//			TWList lista(randData.source);
//
//			CountStart = startTimer();
//			lista.del((rand() % lista.getc() - 2) + 1);
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();


//*****************************szukanie***************************

//
//		for (int i = 0; i < ilerazy; i++)
//		{
//			randData.randPlik();
//			TWList lista(randData.source);
//
//			CountStart = startTimer();
//			lista.check((rand() % (randData.getzG() - randData.getzD())) +randData.getzD());
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();






//########################## HEAP ############################

//--------------------------add ------------------------------


//		for (int i = 0; i < ilerazy; i++)
//		{
//
//			randData.randPlik();
//			Heap heap(randData.source);
//
//
//			CountStart = startTimer();
//			heap.add(rand());
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//}
//plik.close();



//*************************************DEL********************************************
//-----------------------------DEL ----------------------------------- 

//		for (int i = 0; i < ilerazy; i++)
//		{
//			randData.randPlik();
//			Heap heap(randData.source);
//
//			CountStart = startTimer();
//			heap.del();
//			CountEnd = endTimer();
//
//			timeOperation.QuadPart = CountEnd.QuadPart - CountStart.QuadPart;
//			QueryPerformanceFrequency(&freq);
//			double tm = ((double)timeOperation.QuadPart)*sekundadzielnik / freq.QuadPart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();





//*****************************szukanie***************************

//
//		for (int i = 0; i < ilerazy; i++)
//		{
//			randdata.randplik();
//			heap heap(randdata.source);
//
//			countstart = starttimer();
//			heap.heapcheak(rand());
//			countend = endtimer();
//
//			timeoperation.quadpart = countend.quadpart - countstart.quadpart;
//			queryperformancefrequency(&freq);
//			double tm = ((double)timeoperation.quadpart)*sekundadzielnik / freq.quadpart;
//
//			std::string str = std::to_string(tm);
//			plik << str + " ";
//		}
//	}
//plik.close();







	//MENU menu;
	//menu.MENU1();

	//Heap h("dane.txt");
	//h.print();
	//h.add(90);
	//h.add(88);
	//h.print();
	//h.print();


	/*TWList tl;
	tl.printall();
	tl.addE(1);
	tl.addE(1);
	tl.addE(2);
	tl.addE(1);
	tl.addP(3);
	tl.addP(3);
	tl.addP(3);
	tl.print();
	tl.addCount(22,2);
	tl.addCount(33,4);
	tl.addCount(32,4);

	tl.printall();
	tl.del(4);
	tl.print();
	tl.check(3);*/

	//table.printTab();

	/*fstream plik;
	plik.open("results.txt", ios::out | ios::trunc);
	for (int i = 0; i < 10; i++)
	{
		Table table(randData.source);
		performanceCountStart = startTimer();
		for (int i = 0; i < 100; i++)
		{
			table.add((rand() % 100 + 0), (rand() % table.tabSize + 0));
		}
		performanceCountEnd = endTimer();
		double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		std::string str = std::to_string(tm);
		plik << str + "\n";
		table.~Table();
	}
	plik.close();*/



	

	



    return 0;
}




