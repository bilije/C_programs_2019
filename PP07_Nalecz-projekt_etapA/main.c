/*	Tomasz Nalecz
	Grupa U2
	29.05.2020r. */
	
// Projekt etap I, A


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

int main (void)
{
	FILE *plik1;	 
	plik1 = plik(czytaj, "tekst3");
	
	naglowek dane;
	wczytaj_strukture (plik1, &dane);
	
	if(dane.kolor == 0)
	{
		uint8_t *tablica = (uint8_t*) calloc (sizeof (uint8_t), dane.szerokosc*dane.wysokosc);
	
		if(!tablica)
		{
			puts("Blad alokacji pamieci!");
			exit (1);
		}
	
		wczytaj_dane(plik1, &dane, tablica);
		
		FILE *plik2;
		plik2 = plik(zapisz, "wpisane");
		
		wpisz(&dane, tablica, plik2);
		fclose(plik2);
		free(tablica);
	}
	else
	{
		uint8_t *tablica = (uint8_t*) calloc (sizeof (uint8_t), dane.szerokosc*dane.wysokosc*3);
		if(!tablica)
		{
			puts("Blad alokacji pamieci!");
			exit (1);
		}
	
		wczytaj_dane(plik1, &dane, tablica);
		
		FILE *plik3;
		plik3 = plik(zapisz, "wpisane");
		
		wpisz(&dane, tablica, plik3);
		fclose(plik3);
		free(tablica);
	}
	fclose(plik1);
	return 0;
}
