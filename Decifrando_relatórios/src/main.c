#include <stdio.h>
#include <stdlib.h>
#include "../include/leitura.h"
#include "../include/decifra.h"
#include "../include/erros.h"
#include "../include/saida.h"

int main(int argc, char **argv) {
    
    // Check if the arguments are valid
    check_arguments(argc, argv);

    words *leitura;

    leitura = malloc(sizeof(words));
    
    // Read the archive
    read_archive(argv[1], leitura);
    
    char *unique_letters;
    unique_letters = malloc(8 * sizeof(char));

    // retorna a quantidade de letras únicas
    int count = validation_letters(&leitura, unique_letters);
    
    int *Alphabet;
    
    int max_value = -1;
    
    int *Letter_Value;

    // aloca a memória
    Alphabet = malloc(26 * sizeof(int));
    Letter_Value = malloc(26 * sizeof(int));

    for(int i = 0; i < 26; i++) {
        Alphabet[i] = 0;
        Letter_Value[i] = 0;
    }
    
    // chama a função que faz a permutação
    decrypt_words(&max_value, *leitura, count, 0, Alphabet, unique_letters, Letter_Value);

    // chama a função que imprime a saída
    output(max_value, unique_letters, Letter_Value, argv[2]);

    // libera a memória alocada
    free_memory(Alphabet, Letter_Value, unique_letters, leitura);
    
    return 0;
}
