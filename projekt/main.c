#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "komunikacja.h"
#include "cjsonik.h"
#include "eksploracja.h"





int main(int argc, char **argv)
{
    char*token;
    char buffer[2048];
   //FILE *f = fopen("odp.txt", "r");
   //fread(buffer,1,2048,f);
   //fclose(f);
    mapka* wizualizacja=(mapka*) malloc(sizeof(mapka));;
    
    for(int i=2;argv[i]!=NULL;i++)
    {
    //FILE *f = fopen("odp.txt", "r+");
    //fread(buffer,1,2048,f);
    if(strcmp("info", argv[i]) == 0)
    info(argv[1]);
    if(strcmp("rotate_right", argv[i]) == 0)
    rotate_right(argv[1]);
    if(strcmp("rotate_left", argv[i]) == 0)
    rotate_left(argv[1]);
    if(strcmp("move", argv[i]) == 0)
    {
    move(argv[1]);
    wczytaj("mapa.txt",wizualizacja);
    FILE *f = fopen("odp.json", "r+");
    fread(buffer,1,2048,f);
    wizualizacja->gra=stan_gry(buffer);
    printf("%d",wizualizacja->gra->current_x);
    uzupelnij(wizualizacja);
    printf("%c",wizualizacja->mapa[1][1]);
    wypisztxt("mapa.txt",wizualizacja);
    wypisz(wizualizacja);

    
    }

    if(strcmp("explore", argv[i]) == 0)
    {   
        explore(argv[1]);
        FILE *f = fopen("odp.json", "r+");
        fread(buffer,1,2048,f); 
        wczytaj("mapa.txt",wizualizacja);
        wizualizacja->graex=stan_gry_ex(buffer);
        uzupelnijex(wizualizacja);
        wypisztxt("mapa.txt",wizualizacja);
        wypisz(wizualizacja);
    }
    if(strcmp("reset", argv[i]) == 0)
    {
    reset(argv[1]);
    ustawienie_poczatkowe(wizualizacja);
    wypisztxt("mapa.txt",wizualizacja);
    }


    //FILE *f = fopen("odp.txt", "r");
    //fread(buffer,1,2048,f);
    //wizualizacja->gra=stan_gry(buffer);
    //fclose(f);
    //printf("%s\n",h->field_type);
    //printf("%d\n",h->y1);
    //printf("%d\n",h->x2);
    //printf("%d\n",h->y2);
    //printf("%d\n",h->x3);
    //printf("%d\n",h->y3);
    //printf("%s\n",h->type1);
    //printf("%s\n",h->type2);
    //printf("%s\n",h->type3);
    //free(h);
    //free(h->type1);
    //free(h->type2);
    //free(h->type3);
    //fclose(f);
    }
    return 0;
}