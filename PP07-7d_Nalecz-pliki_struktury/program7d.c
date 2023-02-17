/*	Tomasz Nalecz
	Grupa U2
	8.05.2020r */
	
// program 7d

#include "magazyn.h" 

int main (void)
{
	int numer = 1;
	czesc *baza = (czesc*) malloc (sizeof (czesc) * 19);
	
	while (1)
	{
		puts("\n****MENU****");
		puts("1.Dopisz 1 pozycje do bazy");
		puts("2.Wypisz cala baze");
		puts("3.Koniec");
		
		int n = wczytaj (1, 3, "menu");
		
		
		switch (n)
		{
			case 1 :
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
			
			case 2 :
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
			
			case 3 :
				puts("\nKoniec");
				free(baza);
				break;
				
		}
		
		break;			
	}
	return 0;
}



