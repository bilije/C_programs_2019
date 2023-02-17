/*	Tomasz Nalecz
	Grupa U2
	15.05.2020r */
	
//	program 8d

#include "magazyn.h"

int main (void)
{
	int numer = 1;
	int rozmiar;
	czesc *baza = (czesc*) malloc (sizeof (czesc) * rozmiar);
	
	
	while (1)
	{
		puts("\n****MENU****");
		puts("1.Okresl wielkosc bazy i ja utworz");
		puts("2.Dopisz jedna pozycje do bazy");
		puts("3.Wypisz cala baze");
		puts("4.Koniec");
		
		int n = wczytaj(1, 4, "menu");
		
		switch(n)
		{
			case 1 : 
				puts("\nTworzenie bazy:");
				
				rozmiar = wczytaj(0, UINT16_MAX >> 6, "wielkosci bazy");
				
				puts("Baza została utworzona");
				
				continue;
				
			case 2 :
				
				if(!rozmiar)
				{
					fputs("Blad alokacji pamieci!", stderr);
					exit (1);
				}
				
				puts("\nDopisywanie do bazy:");
				
				if(numer >= 20)
				{
					puts("Baza jest juz pelna!");
				}
				
				else
				{
					uzupelnij_dane( &baza, numer);
					//printf("%d", baza[1].liczba_porzadkowa);
					numer++;
					//printf("%d", baza[1].numer_katalogowy);
				}
				continue;
				
			case 3 :
				puts("\nWypisywanie bazy:");
				
				if( numer <= 1 )
				{
					puts("Baza jest pusta!");
				}
				
				else
				{
					wypisz_magazyn( &baza, numer);
				}
				continue;
				
			case 4 :
				puts("Koniec");
				free(baza);
				break;
		}
		break;
	}
	return 0;
}
