#include <stdio.h>
#include <stdlib.h>
#include "quarto.h"

void ler_arq(){
  FILE *arq;
  char Linha[100];
  char *resultado;
  int i;

  arq=fopen("Quarto.txt", "rt"); /*Abre o arquivo TEXTO para leitura*/
  if(arq == NULL){  /*Caso tenha erro na abertura do arquivo*/
    printf("Erro na abertura do arquivo");
    return;
  }

  i=1;
  while(!feof(arq)){/*Lê linha(inclusive com '/n')*/
  /*<FEOF> retorna um valor dif. de zero se uma operação de
  leitura tentou ler após o final do arquivo. Caso contrário
  return 0.*/
    resultado=fgets(Linha, 100, arq);/*O fgets lê ate 99  caracteres e/ou '/n'*/
    if(resultado){/*Caso a leitura for bem sucedida*/
      printf(" %d: %s", i, Linha);
      i++;
    }
  }
  fclose(arq);
}