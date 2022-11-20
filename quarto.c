#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

struct quarto{
  int disponibilidade;
  char localizacao[50];
  float preco;
  int numero_quarto;
};

struct list{
  Quarto *dados;
  List *next;
};


Quarto *reservar_quarto(void){

  Quarto *cadastrar_quarto;
  cadastrar_quarto = (Quarto*)malloc(sizeof(Quarto));

  printf("Informe o numero do quarto: ");
  scanf("%d", &cadastrar_quarto->numero_quarto);
  printf("Informe a disponibilidade: ");
  scanf("%d", &cadastrar_quarto->disponibilidade);
  printf("Informe a localizacao: ");
  scanf("%[^\n]", &cadastrar_quarto->localizacao);
  printf("Informe o valor do quarto: ");
  scanf("%f", &cadastrar_quarto->preco);

  FILE *info_quartos = fopen("Quartos.txt", "a");

  if(info_quartos == NULL){
    printf("ERRO AO ABRIR O ARQUIVO!\n");
  }
  else{
    printf("SALVO COM SUCESSO!\n");
  }

  fprintf(info_quartos, "Numero do quarto:%d\nDisponibilidade:%d\nLocalizacao:%s\nPreco:%f\n", cadastrar_quarto->numero_quarto, cadastrar_quarto->disponibilidade, cadastrar_quarto->localizacao, cadastrar_quarto->preco);

  fclose(info_quartos);

  return cadastrar_quarto;
}

List *inserir(List *lista, Quarto *novo_quarto){

  List *novo = (List*) malloc (sizeof(List));
  novo->dados = novo_quarto;
  novo->next = Lista;

  
}