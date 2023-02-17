/*	Tomasz Nalecz
	Grupa U2
	04.06.2020r. */
	
// Projekt, etap II, B

#include "biblioteka.h"

int wczytaj (int d_gran, int g_gran, const char * komunikat)
{
	int wybor = 0;
	printf("Podaj %s z zakresu <%d, %d>:", komunikat, d_gran, g_gran);
	do
	{
		scanf("%d", &wybor);
	}
	while(wybor < d_gran || wybor > g_gran);
	return wybor;
}

int main (int argc, char *arg[])
{
	if(argc < 4)
	{
		puts("\n!!!UWAGA!!!\nNie podano wszystkich parametrow!");
	}
	if(argc > 4)
	{
		fputs("\nPodano za duzo parametrow!!!\n", stderr);
		return 1;
	}
	
	while(1)
	{
		puts("\n****MENU****");
		puts("1.Otworz plik i wczytaj dane");
		puts("2.Konwertuj plik i zapisz zmiany");
		puts("3.Koniec");
	
		int n = wczytaj(1, 3, "opcje menu");
	
		switch (n)
		{
			case 1:
				
				puts("\nOtwieranie pliku i wczytywanie danych:");
				
				char nazwa1[16];
				if(argc == 1)
				{
					printf("Podaj nazwe pliku ktorego chcesz otworzyc:");
					scanf("%s", nazwa1);
				}
				else
				{
					strcpy(nazwa1, arg[1]);
				}
			
				FILE *plik1;	 
				plik1 = plik(czytaj, nazwa1);
	
				naglowek dane;
				
				wczytaj_strukture (plik1, &dane);
				
				uint8_t *tablica;
				
				if(dane.kolor == 0)
				{
					tablica = (uint8_t*) calloc (sizeof (uint8_t), dane.szerokosc*dane.wysokosc);
					
					if(!tablica)
					{
						puts("Blad alokacji pamieci!");
						exit (1);
					}
				}
				else
				{
					tablica = (uint8_t*) calloc (sizeof (uint8_t), dane.szerokosc*dane.wysokosc*3);
					
					if(!tablica)
					{
						puts("Blad alokacji pamieci!");
						exit (1);
					}
				}
				wczytaj_dane(plik1, &dane, tablica);
				
				char nazwa2[16];
				if(argc <= 2)
				{
					printf("Podaj nazwe pliku, w ktorym chcesz wpisac elementy pliku:");
					scanf("%s", nazwa2);
				}
				else
				{
					 strcpy(nazwa2, arg[2]);
				}
			
				FILE *plik2;
				plik2 = plik(zapisz, nazwa2);
		
				wpisz(&dane, tablica, plik2);
				fclose(plik2);
				
				continue;
				
			case 2:
				
				if(dane.typ_pliku == 0)
				{
					puts("\nNie otwarto zadnego pliku!");
				}
				else
				{
					puts("\nKonwertowanie pliku i zapisywanie zmian:");
					
					naglowek duplikat;
					
					kopiuj( &dane, &duplikat);
					
					uint8_t *konwdane = tabkonwer (&duplikat, tablica);
					
					char nazwa3[16];
					if(argc <= 3)
					{
						printf("Podaj nazwe nowego pliku:");
						scanf("%s", nazwa3);
					}
					else
					{
						strcpy(nazwa3, arg[3]);
					}
					
					FILE *plik3;
					plik3 = plik(zapisz, nazwa3);
					
					zapisz_plik(plik3, &duplikat, konwdane);
					
					fclose(plik2);
					free(konwdane);
				}
				
				continue;
				
			case 3:
				puts("\nKoniec...");
				free(tablica);
	
				break;
		}
		break;
	}
	
	return 0;
}






