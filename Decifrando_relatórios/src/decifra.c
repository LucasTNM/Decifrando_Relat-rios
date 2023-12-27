#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/decifra.h"

// Função que verifica se a soma das palavras é igual a terceira palavra
void Morph(int *max_value, int size, int *Alphabet, char *unique_letters, int *letter_value, words palavras) {
    // Variáveis auxiliares para armazenar o tamanho das palavras
    int var1 = strlen(palavras.first_word);
    int var2 = strlen(palavras.second_word);
    int var3 = strlen(palavras.third_word);

    char aux1[var1 + 1];
    char aux2[var2 + 1];
    char aux3[var3 + 1];

    // Verifica se a primeira letra de cada palavra é igual a 0
    if(Alphabet[palavras.first_word[0] - 'A'] == 0 || Alphabet[palavras.second_word[0] - 'A'] == 0 || Alphabet[palavras.third_word[0] - 'A'] == 0) {
        if((palavras.first_word[0] == palavras.second_word[0]) && (palavras.second_word[0] == palavras.third_word[0])) {
            *max_value = 0;
            return;
        }
        return;
    }

    if((palavras.first_word[0] == palavras.second_word[0]) && (palavras.second_word[0] == palavras.third_word[0])) {
        *max_value = 0;
        return;
    }

    // Verifica se a primeira letra de cada palavra é igual a 0
    for(int i = 0; i < var1; i++) {
        aux1[i] = Alphabet[palavras.first_word[i] - 'A'] + '0';
    }
    aux1[strlen(palavras.first_word)] = '\0';
    // Verifica se a primeira letra de cada palavra é igual a 0
    for(int i = 0; i < var2; i++) {
        aux2[i] = Alphabet[palavras.second_word[i] - 'A'] + '0';
    }
    aux2[strlen(palavras.second_word)] = '\0';
    // Verifica se a primeira letra de cada palavra é igual a 0
    for(int i = 0; i < var3; i++) {
        aux3[i] = Alphabet[palavras.third_word[i] - 'A'] + '0';
    }
    aux3[strlen(palavras.third_word)] = '\0';
    
    // Converte as strings para inteiros
    int value1 = atoi(aux1);
    int value2 = atoi(aux2);
    int value3 = atoi(aux3);

    // Verifica se a soma das palavras é igual a terceira palavra
    if(value1 + value2 == value3) {
        if(value3 > *max_value) {
            *max_value = value3;
            
            // Armazena os valores das letras
            for(int i = 0; i < size; i++) {
                letter_value[i] = Alphabet[unique_letters[i] - 'A'];
            }
        }
    }
}

// Função que descriptografa as palavras
void decrypt_words(int *max_value, words leitura, int size, int index, int *Alphabet, char *unique_letters, int *letter_value) {
    // Verifica se o index é igual ao tamanho
    if (index != size) {
        
        // Loop para percorrer o alfabeto
        for(int i = 9; i >= 0; i--) {
        Alphabet[unique_letters[index] - 'A'] = i;
        
        // Chama a função recursivamente
        decrypt_words(max_value, leitura, size, index + 1, Alphabet, unique_letters, letter_value);
        }
    }
    // Chama a função Morph
    Morph(max_value,size, Alphabet, unique_letters, letter_value, leitura);

}
