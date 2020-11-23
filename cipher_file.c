#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrer.h"

#define MAXLEN 100
#define key 3
// #DEFINE MAXLEN 100

void traitementFichier(FILE *fichier)
{
    char chaine[MAXLEN] = "";
    int test = 0;
    char copie[MAXLEN] = {0};

    while(fgets(chaine, MAXLEN, fichier) != NULL && test <= 10)
    {
        strcpy(copie, chaine);
        chiffrer(chaine, key);
        printf("%s codé par la méthode de cipher avec une clé de %d donne %s", copie, key, chaine);
        test ++;
    }
}

int main(int argc, char *argv[])
{
  FILE *monFichier = NULL ;

  monFichier = fopen(argv[1], "r") ;

  if (monFichier != NULL)
  {
    traitementFichier(monFichier);
    fclose(monFichier);
  }
  else
  {
    printf("Désolé mais le fichier n'a pas pu être ouvet \n");
  }
  return 0;
}
