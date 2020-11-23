#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *chiffrer(char str[], int shift) {
  int i = 0;

  while (str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i]<= 'Z') {
      char c = str[i]  - 'A';
      c += shift;
      c = c % 26;
      str[i] = c  + 'A';
      str[i] = tolower(str[i]);
    }
    else if (str[i] >= 'a' && str[i]<= 'z')
    {
      char c = str[i]  - 'a';
      c += shift;
      c = c % 26;
      str[i] = c  + 'a';
      str[i] = toupper(str[i]);
    }
    i++;
  }
  return str;
}

void cesar_decrypt(char str_dec[], int shift) {
  int i = 0;

  while (str_dec[i] != '\0')
  {
    if (str_dec[i] >= 'A' && str_dec[i]<= 'Z') {
      char c = str_dec[i]  - 'A';
      c -= shift;
      c = c % 26;
      str_dec[i] = c  + 'A';
      str_dec[i] = tolower(str_dec[i]);
    }
    else if (str_dec[i] >= 'a' && str_dec[i]<= 'z')
    {
      char c = str_dec[i]  - 'a';
      c -= shift;
      c = c % 26;
      str_dec[i] = c  + 'a';
      str_dec[i] = toupper(str_dec[i]);
    }
    i++;
  }
}
