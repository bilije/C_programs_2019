/* 	Tomasz Nalecz
	Grupa U2
	22.05.2020r */
	
//	program9d


#include "magazyn.h"

int main (void)
{
	while (1)
	{
		puts("\n****MENU****");
		puts("1.Dopisz jedna pozycje do bazy");
		puts("2.Wypisz cala baze");
		puts("3.Usun baze");
		puts("4.Zakoncz program");
		
		int n = wczytaj(1, 4, "menu");
		
		switch(n)
		{
			case 1 :
				puts("\nDopisanie pozycji do bazy:");
				continue;
			
			case 2 :
				puts("\nWypisanie bazy:");
				continue;
			
			case 3 :
				puts("\nUsuwanie bazy:");
				continue;
				
			case 4 :
				puts("\nWylaczanie programu...");
				break;
		}
		break;
	}
	return 0;
}
