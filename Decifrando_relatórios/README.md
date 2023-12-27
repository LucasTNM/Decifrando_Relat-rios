# Decifrando Relatórios

## Descrição
Este é um programa para encontrar Inúmeros relatórios envolvendo transações ilegais encontrados pela polícia federal na sua mais recente operação: “Gizé".Cada transação é composta por uma soma de dois números, resultando em um terceiro. Contudo, os relatórios estão cifrados.Cada dígito foi substituído por uma letra maiúscula, isto é, os números se tornaram palavras.

## Especificações de entrada
O arquivo de entrada entrada possui três linhas com as palavras A, B e C, as quais
descrevem uma transação, isto é, C equivale à soma de A e B. É garantido que as palavras
não ultrapassam 8 caracteres e que o número de caracteres distintos nas três palavras é
no máximo 7.

## Especificações de saída
A primeira linha do arquivo de saída deve possuir o maior valor possível de C. Caso
não seja possível decifrar a transação, o valor a ser impresso é “-1”, senão, as próximas
linhas devem descrever a correspondência utilizada para obter os números da transação.
Cada uma destas linhas está no formato“c : d” em que c corresponde a uma letra e d
corresponde a um algarismo.
No caso em que seja possível decifrar o relatório, as correspondências podem ser dadas
em qualquer ordem.

## Compilação e Execução
Para compilar e executar o programa, siga os seguintes comandos no terminal:

1. Certifique-se de que o `make` esteja instalado em seu computador.
2. Execute o seguinte comando para compilar o programa:

    make

3. Execute o seguinte comando para rodar o programa:
    
    make run 
    
    Atente-se para os arquivos dentro do makefile no comando run, é necessário colocar o arquivo de entrada e saída EX: 
    run:$(BINDIR)/main ./entrada.txt ./saida.txt

Se você desejar apagar os arquivos objetos e o executável, utilize o seguinte comando:

    make clean


# EXEMPLO:
make
make run

Entrada:
AB
A
BCC

Saída:
100
A:9
B:1
C:0

///////////////////
Entrada:
AB
A
CDC

Saída:
101
A:9
B:2
C:1
D:0

///////////////////
Entrada:
AB
BC
AC

Saída:
-1