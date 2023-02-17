
/*  Tomasz Nałęcz
    Grupa U2
    03.04.2020r. */

//  program3d


#include <stdio.h>
#include <stdbool.h>


int main (void)
{
    bool menu = true ;

    float dane[200] = {0} ;

    while (menu)
    {
        puts("\n1.Wczytaj i wyswietl dane.");
        puts("2.Oblicz i wyswietl wartosc srednia.");
        puts("3.Koniec");

        int n;
        printf("Podaj opcje:");
        scanf("%d", &n);

        if ( n <= 0)
        {
            puts("Wybrana opcja jest niepoprawna!\n");
            continue;
        }

        if ( n >= 4)
        {
            puts("Wybrana opcja jest niepoprawna!\n");
            continue;
        }

        switch(n)
        {
            case 1 :
                puts("\n'Wczytaj i wyswietl dane':");

                int a;

                while(1)
                {

                    printf("Podaj liczbe danych z zakresu (65,200]:");
                    scanf("%d", &a);

                    if( a < 66)
                    {
                        puts("Podana liczba nie miesci sie w zakresie!\n");
                        continue;
                    }

                    if( a > 200)
                    {
                        puts("Podana liczba nie miesci sie w zakresie!\n");
                        continue;
                    }
                    break;
                }


                FILE *plik = fopen ("wzrost_studentow.txt", "r");

                if (!plik)
                {
                    puts("Nie mozna czytac pliku 'wzrost_studentow.txt'.");
                    return 1;
                }

                else
                {
                    for (int i=0; i < a; i++)
                    {
                        fscanf(plik, "%f", &dane[i]);
                    }

                    for (int i=0; i < a; i++)
                    {
                        printf("%.3f   ", dane[i]);
                        if( i%6 == 5)
                            puts("\n");
                    }
                }
                fclose(plik);

                continue;

            case 2 :
                puts("\n'Oblicz i wyswietl wartosc srednia':");

                int b;

                while(1)
                {

                    printf("Podaj liczbe danych z zakresu (65,200]:");
                    scanf("%d", &b);

                    if( b < 66)
                    {
                        puts("Podana liczba nie miesci sie w zakresie!\n");
                        continue;
                    }

                    if( b > 200)
                    {
                        puts("Podana liczba nie miesci sie w zakresie!\n");
                        continue;
                    }
                    break;
                }


                FILE *plik2 = fopen ("wzrost_studentow.txt", "r");

                if (!plik2)
                {
                    puts("Nie mozna czytac pliku 'wzrost_studentow.txt'.");
                    return 1;
                }

                else
                {
                    for (int i=0; i < b; i++)
                    {
                        fscanf(plik2, "%f", &dane[i]);
                    }

                    float suma = 0;

                    for(int i=0; i < b; i++)
                    {
                        suma += dane[i];
                    }

                    float srednia = suma/b;

                    while(1)
                    {
                        puts("Gdzie wpisac wynik?");
                        puts("1.Na ekranie");
                        puts("2.W pliku");

                        int k;
                        printf("Podaj opcje:");
                        scanf("%d", &k);


                        if ( k < 1)
                        {
                            puts("Wybrana opcja jest niepoprawna!\n");
                            continue;
                        }

                        if ( k > 2)
                        {
                            puts("Wybrana opcja jest niepoprawna!\n");
                            continue;
                        }

                        switch(k)
                        {
                            case 1 :
                                puts("'Na ekranie':");

                                printf("Dla liczby danych: %d\nSrednia=%.3f\n", b, srednia);
                                break;

                            case 2 :
                                puts("'W pliku':");

                                char nazwa[16];

                                printf("Podaj nazwe pliku do zapisu planu \n");
                                scanf("%s", nazwa);


                                FILE *plik3=fopen(nazwa, "w");

                                fprintf(plik3,"Dla liczby danych %d\nSrednia=%.3f\n", b, srednia);

                                fclose(plik3);

                                printf("Zapisano wynik do pliku %s\n", nazwa);
                                break;
                        }
                        break;
                    }
                }
                fclose(plik2);
                continue;

            case 3 :
                break;

        }

        break;
    }

    return 0;
}









