#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrer.h"

#define MAXLEN 100
// #DEFINE MAXLEN 100

int main(int argc, char *argv[])
{
  char str[MAXLEN];
  char copie[100] = {0};
  int key = atoi(argv[1]);

  printf("\n Entrez La chaîne de charactère à crypter\n");
  fgets(str, MAXLEN, stdin);

  strcpy(copie, str);

  // On lit notre fonction CHIFFRER

  chiffrer(str, key);
  printf("%s codé par la fonction chiffrer avec une clé de %d est %s\n", copie, key, str);
  return 0;
}
