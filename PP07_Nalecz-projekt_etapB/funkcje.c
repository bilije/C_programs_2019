/*	Tomasz Nalecz
	Grupa U2
	04.06.2020r. */
	
// Projekt, etap II, B

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
	fscanf(plik,"%hu", &dane->typ_pliku);
	fscanf(plik, "%hu", &dane->szerokosc);
	fscanf(plik, "%hu", &dane->wysokosc);
	fscanf(plik, "%hu", &dane->kolor);
	fscanf(plik, "%hu", &dane->kompresja);
}

void wczytaj_dane (FILE *plik, naglowek *dane, uint8_t *tablica)
{
	if(dane->kolor == 0)
	{
	
		for(int i = 0; i < dane->wysokosc*dane->szerokosc; i++)
		{
			fscanf(plik, "%hu", &tablica[i]);
		}
	}
	else
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc*3; i++)
		{
			fscanf(plik, "%hu", &tablica[i]);
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
	fprintf(plik, "Dane =\n");
	
	if(dane->kolor == 0)
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc; i++)
		{
			fprintf(plik, "%hu\n", tablica[i]);
		}
	}
	else
	{
		for(int i = 0; i < dane->wysokosc*dane->szerokosc*3; i++)
		{
			fprintf(plik, "%hu\n", tablica[i]);
		}
	}
}

void kopiuj(naglowek *oryg, naglowek *kopia)
{
	kopia->typ_pliku = oryg->typ_pliku;
	kopia->szerokosc = oryg->szerokosc;
	kopia->wysokosc = oryg->wysokosc;
	kopia->kolor = oryg->kolor;
	kopia->kompresja = oryg->kompresja;
}

uint8_t *tabkonwer (naglowek *kopia, uint8_t *tablica)
{
	if( kopia->kolor == 0)
	{
		uint8_t *danekonwer = (uint8_t*) calloc (sizeof (uint8_t), kopia->szerokosc*kopia->wysokosc*3);
		if(!danekonwer)
		{
			puts("Blad alokacji pamieci!");
			exit (1);
		}
		
		int j = 0;
		
		for(int i=0; i < kopia->szerokosc*kopia->wysokosc; i++)	
		{
				danekonwer[j] = tablica[i];
				danekonwer[j+1] = tablica[i];
				danekonwer[j+2] = tablica[i];
				
				j += 3;	
		}
		kopia->kolor = 1;
		return danekonwer;
	}
	else
	{
		return tablica;
	}
}

void zapisz_plik (FILE *plik, naglowek *kopia, uint8_t *tablica)
{
	fprintf(plik, "%hu ", kopia->typ_pliku);
	fprintf(plik, "%hu ", kopia->szerokosc);
	fprintf(plik, "%hu ", kopia->wysokosc);
	fprintf(plik, "%hu ", kopia->kolor);
	fprintf(plik, "%hu ", kopia->kompresja);
	
	for(int i=0; i < kopia->szerokosc*kopia->wysokosc*3; i++)
	{
		fprintf(plik, "%hu ", tablica[i]);
	} 
}

