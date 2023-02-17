/*	Tomasz Nalecz
	Grupa U2
	22.05.2020r. */
	
// program9d

#include <magazyn.h>

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




uint16_t dodaj_grupe (void)
{
	int ilosc = 0;
	enum czesci grupa = 0;
	
	while (1)
	{
		puts("\n1.Dodaj grupe czesci");
		puts("2.Zakoncz");
		
		int k = wczytaj(1, 2, "polecenia");
		
		switch(k)
		{
			case 1 :
				if(ilosc < 3)
				{
					ilosc++;
					puts("\nNumeracja grup:");
					puts("Naped - 1");
					puts("Elektryka - 2");
					puts("Zawieszenie - 3");
					puts("Hamulce - 4");
					puts("Bezpieczenstwo - 5");
					
					int nrgr = wczytaj(1, 5, "grupy");
					
					switch(nrgr)
					{
						case 1 :
							if(grupa & NAPED)
							{
								puts("\nTa grupa zostala już dodana!");
							}
							else
							{
								grupa |= NAPED;
							}
							break;	
						
						case 2 :
							if(grupa & ELEKTRYKA)
							{
								puts("\nTa grupa zostala już dodana!");
							}
							else
							{
								grupa |= ELEKTRYKA;
							}
							break;
						
						case 3 :
							if(grupa & ZAWIESZENIE)
							{
								puts("\nTa grupa zostala już dodana!");
							}
							else
							{
								grupa |= ZAWIESZENIE;
							}
							break;
							
						case 4 :
							if(grupa & HAMULCE)
							{
								puts("\nTa grupa zostala już dodana!");
							}
							else
							{
								grupa |= HAMULCE;
							}
							break;
						
						case 5 :
							if(grupa & BEZPIECZENSTWO)
							{
								puts("\nTa grupa zostala już dodana!");
							}
							else
							{
								grupa |= BEZPIECZENSTWO;
							}
							break;		
					}
					continue;	
				}
				else
				{
					puts("Dodano juz 3 grupy!");
					break;
				}
				
			case 2 :
				break;
		}
		break;
	}
	return grupa;
}




void uzupelnij_dane (czesc *d, int nr)
{
	d[nr-1].liczba_porzadkowa = nr;
	
	printf("\nNumer katalogowy:");
	scanf("%s", d[nr-1].numer_katalogowy);
	
	printf("\nMarka:");
	scanf("%s", d[nr-1].nazwa);
	
	puts("Zamiast spacji prosze wpisywac '.'");
	printf("\nModel:");
	scanf("%s", d[nr-1].model_samochodu);
	
	printf("\nKategoria:");
	scanf("%s", d[nr-1].kategoria);
	
	d[nr-1].czs = dodaj_grupe ();
	
	char *znak;
	while ((znak=strchr(d[nr-1].model_samochodu, '.'))!=NULL)
	{
		*znak=' ';
	}
	
	
}

void wypisz_kategorie ( char *lgat, const uint16_t *gat)
{
	
	
	if(*gat & NAPED)
	{
		strcat(lgat, "Naped:");
	}
	if(*gat & ELEKTRYKA)
	{
		strcat(lgat, "Elektryka:");
	}
	if(*gat & ZAWIESZENIE)
	{
		strcat(lgat, "Zawieszenie:");
	}
	if(*gat & HAMULCE)
	{
		strcat(lgat, "Hamulce:");
	}
	if(*gat & BEZPIECZENSTWO)
	{
		strcat(lgat, "Bezpieczentswo:");
	}

	printf("%s", lgat);
}

int losuj(int pocz, int koniec)
{
	int jeden;
	
	do
	{
		jeden = rand () % koniec;
	}
	while(jeden < pocz);
	
	return jeden;
}
