/* 	Tomasz Nalecz
	Grupa U2
	15.05.2020r */
	
// program 8d


#ifndef _magazyn_h_
#define _magazyn_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

enum czesci {NAPED = 16, ELEKTRYKA = 32, ZAWIESZENIE = 64, HAMULCE = 128, BEZPIECZENSTWO = 256};


struct czsamochodowa 
{
	int liczba_porzadkowa;
	int numer_katalogowy;
	char nazwa [20];
	char model_samochodu [20];
	char kategoria [15];
	uint16_t czs;
};

typedef struct czsamochodowa czesc;


int wczytaj (int dolna_granica, int gorna_granica, char * co);

uint16_t dodaj_grupe (void);

void uzupelnij_dane (czesc *d, int nr);

void wypisz_kategorie ( char *lgat, const uint16_t *gat);

void wypisz_magazyn(czesc *bib, int n);




#endif
