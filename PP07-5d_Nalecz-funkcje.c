/*  Tomasz Nałęcz
    Grupa U2
    24.04.2020r. */

// Program5D

#include <stdio.h>
#include <string.h>

int wczytaj (int dolna_granica, int gorna_granica, char * co)
{
    while(1)
    {
        printf("\nWczytujemy numer %s z przedzialu od %d do %d.\n", co , dolna_granica, gorna_granica);
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

void data_czas(char * data, char * czas)
{
    int dzien = wczytaj (1, 31, "dnia");
    int miesiac = wczytaj (1, 12, "miesiaca");
    int rok = wczytaj (2000, 2030, "roku");

    int godzina = wczytaj (0, 23, "godziny");
    int minuta = wczytaj (0, 59, "minuty");
    int sekunda = wczytaj (0, 59, "sekundy");

    puts("\nDo wyboru sa dwa formaty daty:");
    puts("1.dd-MM-rrrr");
    puts("2.dd/MM/rrrr");
    int format_data = wczytaj (1, 2, "formatu");

    switch (format_data)
    {
        case 1 :
            if(miesiac < 10)
            {
                sprintf(data, " %d-0%d-%d", dzien, miesiac, rok);
            }
            else
            {
                sprintf(data, " %d-%d-%d", dzien, miesiac, rok);
            }
            break;

        case 2 :
            if(miesiac < 10)
            {
                sprintf(data, " %d/0%d/%d", dzien, miesiac, rok);
            }
            else
            {
                sprintf(data, " %d/%d/%d", dzien, miesiac, rok);
            }
            break;
    }

    puts("\nDo wyboru sa dwa formaty czasu");
    puts("1.gg.mm.ss");
    puts("2.gg:mm:ss");
    int format_czas = wczytaj (1, 2, "formatu");

    switch (format_czas)
    {
        case 1 :
            if(minuta < 10 && sekunda > 9)
            {
                sprintf(czas, " %d.0%d.%d", godzina, minuta, sekunda);
            }
            if(minuta < 10 && sekunda < 10)
            {
                sprintf(czas, " %d.0%d.0%d", godzina, minuta, sekunda);
            }
            if(minuta > 9 && sekunda < 10)
            {
                sprintf(czas, " %d.%d.0%d", godzina, minuta, sekunda);
            }
            else
            {
                sprintf(czas, " %d.%d.%d", godzina, minuta, sekunda);
            }
            break;

        case 2 :
            if(minuta < 10 && sekunda > 9)
            {
                sprintf(czas, " %d:0%d:%d", godzina, minuta, sekunda);
            }
            if( minuta < 10 && sekunda < 10)
            {
                sprintf(czas, " %d:0%d:0%d", godzina, minuta, sekunda);
            }
            if(minuta > 9 && sekunda < 10)
            {
                sprintf(czas, " %d:%d:0%d", godzina, minuta, sekunda);
            }
            else
            {
                sprintf(czas, " %d:%d:%d", godzina, minuta, sekunda);
            }
            break;
    }
}

void wypisz(const char * data, const char * czas)
{
    char wpis[40];
    printf("Podaj wlasny wpis:");
    scanf("%s", wpis);

    char lancuch[65];
    strcpy(lancuch, wpis);
    strcat(lancuch, data);
    strcat(lancuch, czas);

    puts(lancuch);
}


int main (void)
{
    while(1)
    {
        puts("****MENU*****");
        puts("1.Utworz date");
        puts("2.Wypisz date");
        puts("3.Koniec");

        int n = wczytaj(1, 3, "menu");

        switch (n)
        {
            case 1 :
                puts("Utworzenie daty:");
                char data[12];
                char czas[8];
                data_czas(data , czas);

                continue;

            case 2 :
                puts("Wypisanie daty:");
                wypisz(data, czas);

                continue;

            case 3 :
                puts("Wylaczenie programu");
                break;
        }
        break;
    }
    return 0;
}
