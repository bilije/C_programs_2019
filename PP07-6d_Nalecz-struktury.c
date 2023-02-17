/* 	Tomasz Nalecz
	Grupa U2
	29.04.2020 */

// program 6d

#include <stdio.h>
#include <math.h>

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

struct zesp
{
	double rzecz;
	double uroj;
};

typedef struct zesp zespolona;

zespolona wczytaj_zesp (void)
{
	puts("Wczytywanie liczby zespolonej:");
	zespolona lzesp;
	
	printf("Podaj czesc rzeczywista:");
	scanf("%lf", &lzesp.rzecz);
	printf("Podaj czesc urojona:");
	scanf("%lf", &lzesp.uroj);
	
	return lzesp;
}

void wyswietl_zesp (const zespolona z1)
{
	double bezwzg = fabs (z1.uroj);
	
	if( z1.uroj < 0 )
	{
		printf("%.2lf-i%.2lf", z1.rzecz, bezwzg);
	}
	
	else
	{
		printf("%.2lf+i%.2lf", z1.rzecz, z1.uroj);
	}
}

void oblicz_zesp (zespolona z1, zespolona z2, zespolona * wynik, int opcja)
{
	zespolona w;
	switch (opcja)
	{
		case 1 :
			w.rzecz = z1.rzecz + z2.rzecz;
			w.uroj = z1.uroj + z2.uroj;
			*wynik = w;
			break;
		
		case 2 :
			w.rzecz = z1.rzecz - z2.rzecz;
			w.uroj = z1.uroj - z2.uroj;
			*wynik = w;
			break;
			
		case 3 :
			w.rzecz = z1.rzecz * z2.rzecz - z1.uroj * z2.uroj;
			w.uroj = z1.rzecz * z2.uroj + z1.uroj * z2.rzecz;
			*wynik = w;
			break;
	}
}

void wyswietl_dzialanie (zespolona * z1, zespolona * z2, zespolona * wynik, int opcja)
{
	printf("\nWynik dzialania--");
	
	switch (opcja)
	{
		case 1 :
			printf("(");
			wyswietl_zesp(*z1);
			printf(")+(");
			wyswietl_zesp(*z2);
			printf(")=");
			wyswietl_zesp(*wynik);
			break;
			
		case 2 :
			printf("(");
			wyswietl_zesp(*z1);
			printf(")-(");
			wyswietl_zesp(*z2);
			printf(")=");
			wyswietl_zesp(*wynik);
			break;
			
		case 3 :
			printf("(");
			wyswietl_zesp(*z1);
			printf(")*(");
			wyswietl_zesp(*z2);
			printf(")=");
			wyswietl_zesp(*wynik);
			break;
	}
}

int main (void)
{
	while (1)
	{ 
		puts("\n****KALKULATOR****");
		puts("1.Dodawanie");
		puts("2.Odejmowanie");
		puts("3.Mnozenie");
		puts("4.Koniec");
		
		int n = wczytaj(1, 4, "menu");
		zespolona wynik;
		
		switch (n)
		{
			case 1 :
				puts("\nDodawanie:");
				
				puts("Podaj pierwszy argument");
				zespolona arg1 = wczytaj_zesp ();
				
				puts("\nPodaj drugi argument");				
				zespolona arg2 = wczytaj_zesp ();
				
				printf("\nPierwsza liczba zespolona:");
				wyswietl_zesp (arg1);
				
				printf("\nDruga liczba zespolona:");
				wyswietl_zesp (arg2);
				
				oblicz_zesp( arg1, arg2, &wynik, n);
				
				wyswietl_dzialanie (&arg1, &arg2, &wynik, n);
			
				
				continue;
			
			case 2 :
				puts("\nOdejmowanie:");
				
				puts("Podaj pierwszy argument");
				zespolona arg3 = wczytaj_zesp ();
				
				puts("\nPodaj drugi argument");				
				zespolona arg4 = wczytaj_zesp ();
				
				printf("\nPierwsza liczba zespolona:");
				wyswietl_zesp (arg3);
				
				printf("\nDruga liczba zespolona:");
				wyswietl_zesp (arg4);
				
				oblicz_zesp( arg3, arg4, &wynik, n);
				
				wyswietl_dzialanie (&arg3, &arg4, &wynik, n);
				
				continue;
				
			case 3 :
				puts("\nMnozenie:");
				
				puts("Podaj pierwszy argument");
				zespolona arg5 = wczytaj_zesp ();
				
				puts("\nPodaj drugi argument");				
				zespolona arg6 = wczytaj_zesp ();
				
				printf("\nPierwsza liczba zespolona:");
				wyswietl_zesp (arg5);
				
				printf("\nDruga liczba zespolona:");
				wyswietl_zesp (arg6);
				
				oblicz_zesp( arg5, arg6, &wynik, n);
				
				wyswietl_dzialanie (&arg5, &arg6, &wynik, n);
				
				continue;
			
			case 4 :
				puts("Koniec");
				break;
		}
		break;
	}
	return 0;	
}
