#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/leitura.h"

void read_archive(const char *archive, words *leitura) {
    // Abre o arquivo para leitura
    FILE *open_archive;
    open_archive = fopen(archive, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (open_archive == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // lendo as palavras do arquivo
    fscanf(open_archive, " %[^\n]s\n", (*leitura).first_word);
    fscanf(open_archive, " %[^\n]s\n", (*leitura).second_word);
    fscanf(open_archive, " %[^\n]s\n", (*leitura).third_word);
    
    // Fecha o arquivo
    fclose(open_archive);
    
}

int validation_letters(words **leitura, char *unique_letters) {
    
    //concatenar as palavras
    char string[27] = "\0";
    strcat(string,(*leitura)->first_word);
    strcat(string,(*leitura)->second_word);
    strcat(string,(*leitura)->third_word);
    
    int tamanho = strlen(string);
    int count = 0;
    
    //comparar as letras
    for(int i = 0; i < tamanho; i++) {
        int found = 0;
        
        //comparar a letra com as demais
        for(int j = i + 1; j< tamanho; j++){
            
            //se for igual, found = 1
            if(string[i] == string[j]) {
                found = 1;
                break;
            }
        }
        
        //se found = 0, count++
        if(!found) {
            unique_letters[count] = string[i];
            count++;
        } 
    }
    
    unique_letters[count] = '\0';
    //retorna o count
    return count;
}