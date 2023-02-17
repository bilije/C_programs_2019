/* 	Tomasz Nalecz
	Grupa U2
	17.04.2020 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
	bool menu = true;

	int rozmiar;
	char *tekst = (char*) calloc (sizeof (int), rozmiar);

	while (menu)
	{
		puts("\n1.Wczytaj tekst do analizy");
		puts("2.Wypisz tekst");
		puts("3.Szukaj słowa");
		puts("4.Koniec");

		int n;
		printf("Podaj numer opcji:");
		scanf("%d", &n);

		if( n <= 0 || n >= 5 )
		{
			puts("Wybrana opcja jest niepoprawna!");
			continue;
		}

		switch(n)
		{
			case 1 :
				puts("\nWczytywanie tekstu do analizy:");

				while (1)
				{
					printf("Podaj liczbę znakow do analizy (minimum 60):");
					scanf("%d" , &rozmiar);

					if ( rozmiar < 60 )
					{
						puts("Podana liczba jest zbyt mała!");
						continue;
				    }
					break;
				}

				while (1)
				{
					puts("Masz do wyboru dwa teksty:");
					puts("1.'Romeo i Julia'");
					puts("2.'Quo Vadis'");

					int a;
					printf("Podaj numer tekstu:");
					scanf("%d", &a);

					if( a <= 0 || a >= 3 )
					{
						puts("Podany numer nie istnieje!\n");
						continue;
					}

					switch(a)
					{
						case 1 :
							puts("Wybrano 'Romeo i Julia'.");

							FILE *plik1 = fopen ("pg1112.txt", "r"); //nazwa pliku z "Romeo i Julia"

							if (!plik1)
							{
								puts("Nie mozna odczytac pliku!");
								return 1;
							}

							int z;
							printf("Podaj od którego znaku chcesz wczytywać:");
							scanf("%d" , &z);
							char *zapychacz = (char*) calloc (sizeof (int), z);

							for(int i=0; i <= rozmiar; i++)
							{
								if (i < z)
								{
									fscanf(plik1, "%s", zapychacz[i]);
									break;
								}
								else
								{
									fscanf(plik1, "%s", tekst[i-z]);
									break;
								}
							}
							free (zapychacz);

							fclose(plik1);
							break;

						case 2 :
							puts("wybrano 'Quo Vadis'.");

							FILE *plik2 = fopen ("2853-0.txt", "r"); //nazwa pliku z "Quo Vadis"

							if (!plik2)
							{
								puts("Nie mozna odczytac pliku!");
								return 1;
							}

							int x;
							printf("Podaj od którego znaku chcesz wczytywać:");
							scanf("%d" , &x);
							char *zapychacz2 = (char*) calloc (sizeof (int), x);

							for(int i=0; i <= rozmiar; i++)
							{
								if (i < x)
								{
									fscanf(plik2, "%s", zapychacz2[i]);
									break;
								}
								else
								{
									fscanf(plik2, "%s", tekst[i-x]);
									break;
								}
							}
							free (zapychacz2);

							fclose(plik2);
							break;
					}
					break;
				}
				continue;

			case 2 :

				puts("\nWypisanie tekstu:");

				char *poczatek = tekst; // <-- do pokazania dlugosci tekstu do analizy
				char *koniec = tekst+rozmiar;
				size_t zakres = koniec - poczatek;
				printf("Dlugosc analizowanego tekstu %zu.", zakres);

				for(int i=0; i <= rozmiar; i++)
				{
					printf("%s", tekst[i]);  //"Naruszenie ochrony pamieci"
				}
				continue;

			case 3 :
				puts("Szukanie słowa:");
				char slowo[16];
				printf("Podaj szukane slowo:");
				scanf("%s", slowo);

				char *znak = strchr (tekst, '*slowo');

				if (znak)
					printf("Znaleziono szukane slowo na pozycji %zu", znak - tekst);
				else
					puts("Nie znaleziono szukanego slowa");

				continue;

			case 4 :
				break;
		}
		break;
	}
	return 0;
}

