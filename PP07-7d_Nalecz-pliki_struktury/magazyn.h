#ifndef _magazyn_h_
#define _magazyn_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct czsamochodowa 
{
	int liczba_porzadkowa;
	int numer_katalogowy;
	char nazwa [20];
	char model_samochodu [20];
	char kategoria [15];
};

typedef struct czsamochodowa czesc;


int wczytaj (int dolna_granica, int gorna_granica, char * co);


void uzupelnij_dane (czesc *d, int nr);


void wypisz_magazyn(czesc *bib, int n);


#endif
