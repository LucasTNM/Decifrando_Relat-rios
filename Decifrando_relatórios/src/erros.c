#include <stdio.h>
#include <stdlib.h>
#include "../include/leitura.h"
#include "../include/erros.h"

// checa se o número de argumentos é válido
void check_arguments(int argc, char **argv) {
    
    // Check if the number of arguments is valid
    if(argc != 3) {
        printf("Erro! Digite o nome do arquivo!\n");
        exit(1);
    }
    // checa se o número de argumentos é valido
    if(argv[1] == NULL) {
        printf("Erro! Digite o nome do arquivo!\n");
        exit(1);
    }
    // checa se o número de argumentos é valido
    if (argv[2] == NULL) {
        printf("Erro! Digite o nome do arquivo!\n");
        exit(1);
    }
}

// libera a memória alocada
void free_memory(int *ptr1, int *ptr2, char *ptr3, words *ptr4) {
    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);
}