#ifndef decifra_h
#define decifra_h
#include "leitura.h"

void decrypt_words(int *max_value, words leitura, int size, int index, int *Alphabet, char *unique_letters, int *letter_value);
void Morph(int *max_value, int size, int *Alphabet, char *unique_letters, int *letter_value, words palavras);

#endif