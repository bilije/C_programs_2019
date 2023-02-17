#include "magazyn.h"


int wczytaj (int dolna_granica, int gorna_granica, char * co)
{
	while (1)
	{	
		printf("\nWczytujemy numer %s z przedzialu od %d do %d.\n", co, dolna_granica, gorna_granica);
		int numer;
		printf("Podaj numer z podanego przedzialu:");
		scanf("%d", &numer);
		
		if( numer < dolna_granica || numer > gorna_granica )
		{	
			puts("Wybrana liczba nie miesci sie w przedziale!");
			continue;
		}
		
		else
		{
			return numer;
		}
	}
}



void uzupelnij_dane (czesc *d, int nr)
{
	d[nr-1].liczba_porzadkowa = nr;
	
	puts("\nZamiast spacji prosze wpisywac '.'");
	
	printf("\nNumer katalogowy:");
	scanf("%d", &d[nr-1].numer_katalogowy);
	
	printf("\nMarka:");
	scanf("%s", d[nr-1].nazwa);
	
	printf("\nModel:");
	scanf("%s", d[nr-1].model_samochodu);
	
	printf("\nKategoria:");
	scanf("%s", d[nr-1].kategoria);
	
	char *znak;
	while ((znak=strchr(d[nr-1].model_samochodu, '.'))!=NULL)
	{
		*znak=' ';
	}
	
	
}


void wypisz_magazyn(czesc *bib, int n)
{
	puts("LP | Nr Katalogowy |    Marka    |    Model    | Kategoria ");
	
	for(int i=0; i < n-1; i++)
	{
		printf("%-3d| %-14d| %-12s| %-12s| %s\n", 
				bib[i].liczba_porzadkowa, bib[i].numer_katalogowy, bib[i].nazwa, bib[i].model_samochodu, bib[i].kategoria);
	}
}

