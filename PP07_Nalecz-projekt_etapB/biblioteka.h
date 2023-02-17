/*	Tomasz Nalecz
	Grupa U2
	04.06.2020r. */
	
// Projekt, etap II, B


#ifndef _biblioteka_h_
#define	_biblioteka_h_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum rodzaj_pracy {czytaj, zapisz};

struct naglowek
{
	uint16_t typ_pliku;
	uint16_t szerokosc;
	uint16_t wysokosc;
	uint8_t kolor;
	uint8_t kompresja;
};

typedef struct naglowek naglowek;

int wczytaj (int d_gran, int g_gran, const char * komunikat);

FILE *plik (enum rodzaj_pracy praca, char *nazwa);

void wczytaj_strukture (FILE *plik, naglowek *dane);

void wczytaj_dane (FILE *plik, naglowek *dane, uint8_t *tablica);

void wpisz (naglowek *dane, uint8_t *tablica, FILE *plik);

void kopiuj(naglowek *oryg, naglowek *kopia);

uint8_t *tabkonwer (naglowek *kopia, uint8_t *tablica);

void zapisz_plik (FILE *plik, naglowek *kopia, uint8_t *tablica);
#endif
