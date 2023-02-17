/*	Tomasz Nalecz
	Grupa U2
	29.05.2020r. */
	
// Projekt etap I, A

#include "biblioteka.h"

FILE *plik (enum rodzaj_pracy praca, char *nazwa)
{
	static FILE *plik1;
	if(praca == 0)
	{
		plik1 = fopen (nazwa, "r");
		
		if(!plik1)
		{
			puts("Nie udalo sie otworzyc pliku!");
			exit (1);
		} 
	}
	else
	{
		plik1 = fopen (nazwa, "w");
		
		if(!plik1)
		{
			puts("Nie udalo sie otworzyc pliku!");
			exit (1);
		} 
	}

	return plik1;
}


void wczytaj_strukture (FILE *plik, naglowek *dane)
{
	char t1[7];
	
	printf("%s", t1);
	fscanf(plik, "%s", t1);
	
	int i;
	sscanf(t1, "%d", &i);
	dane->typ_pliku = i;
	
	fscanf(plik, "%s", t1);
	sscanf(t1, "%d", &i);
	dane->szerokosc = i;
	
	
	fscanf(plik, "%s", t1);
	sscanf(t1, "%d", &i);
	dane->wysokosc = i;
	
	
	fscanf(plik, "%s", t1);
	sscanf(t1, "%d", &i);
	dane->kolor = i;
	
	
	fscanf(plik, "%s", t1);
	sscanf(t1, "%d", &i);
	dane->kompresja = i;
}

void wczytaj_dane (FILE *plik, naglowek *dane, uint8_t *tablica)
{
	char t2[4];
	int a;
	if(dane->kolor == 0)
	{
	
		for(int i = 0; i < dane->wysokosc*dane->szerokosc; i++)
		{
			fscanf(plik, "%s", t2);
			sscanf(t2, "%d", &a);
			tablica[i] = a;	
		}
	}
	else
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc*3; i++)
		{
			fscanf(plik, "%s", t2);
			sscanf(t2, "%d", &a);
			tablica[i] = a;	
		}
	}
}

void wpisz (naglowek *dane, uint8_t *tablica, FILE *plik)
{
	fprintf(plik, "Typ pliku = %hu\n", dane->typ_pliku);
	fprintf(plik, "Szerokosc = %hu\n", dane->szerokosc);
	fprintf(plik, "Wysokosc = %hu\n", dane->wysokosc);
	fprintf(plik, "Kolor = %hu\n", dane->kolor);
	fprintf(plik, "Kompresja = %hu\n", dane->kompresja);
	fprintf(plik, "Dane = ");
	
	if(dane->kolor == 0)
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc; i++)
		{
			fprintf(plik, "%hu ", tablica[i]);
		}
	}
	else
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc*3; i++)
		{
			fprintf(plik, "%hu ", tablica[i]);
		}
	}
}
