#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/decifra.h"
#include "../include/saida.h"

void output(int max_value, char *unique_letters, int *letter_value, const char *argv) {
    // Verifica se o valor máximo é igual a -1
    FILE *arq;
    if(max_value == -1) {
        arq = fopen(argv, "w");
        
        // Verifica se o arquivo foi aberto corretamente
        if(arq == NULL) {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
        
        // Escreve -1 no arquivo
        fprintf(arq,"-1\n");
        fclose(arq);
        return;
    }
    
    // Abre o arquivo para escrita
    arq = fopen(argv, "w");

    // Verifica se o arquivo foi aberto corretamente
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    // Escreve o valor máximo no arquivo
    fprintf(arq, "%d", max_value);
    // Escreve as letras e seus valores no arquivo
    for(int i = 0; i < strlen(unique_letters); i++) {
        fprintf(arq, "\n%c:%d", unique_letters[i], letter_value[i]);
    }
    
    // Fecha o arquivo
    fclose(arq);
}