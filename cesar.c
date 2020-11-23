#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "chiffrer.h"

#define CHIFFRER "MAJUScule"
#define DECHIFFRER "pdmxvfXOH"
#define key 3
#define MAXLEN 100

int main()
{
  char str[] = CHIFFRER;
  char str_dec[] = DECHIFFRER;

  char copie[MAXLEN] = {0};
  strcpy(copie, str);

  //On applique nos fonctions chiffrer de cryptage et de decryptage
  chiffrer(str, key);
  printf("%s codé par la méthode césar avec une clé de %d est %s\n", copie, key, str);

  char copie_decrypt[100] = {0};
  strcpy(copie_decrypt, str_dec);

  //On appliques la fonction cesar_decrypt
  cesar_decrypt(str_dec, key);
  printf("%s décodé par la méthode césar avec une clé de %d est %s\n", copie_decrypt, key, str_dec);

  return 0;
}
