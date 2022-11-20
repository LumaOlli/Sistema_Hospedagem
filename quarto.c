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
  printf("Informe a disponibilidade: \n");
  printf("  <1> Sim    <2> Não   ");
  scanf("%d", &cadastrar_quarto->disponibilidade);
  printf("Informe a localizacao: ");
  scanf(" %[^\n]", cadastrar_quarto->localizacao);
  printf("Informe o valor do quarto: ");
  scanf("%f", &cadastrar_quarto->preco);

  FILE *info_quartos = fopen("Quartos.txt", "a");

  if(info_quartos == NULL){
    printf("ERRO AO ABRIR O ARQUIVO!\n");
  }
  else{
    printf("Salvo com sucesso!\n");
  }

  fprintf(info_quartos, "Numero do quarto:%d\nDisponibilidade:%d\nLocalizacao:%s\nPreco:%.2f\n", cadastrar_quarto->numero_quarto, cadastrar_quarto->disponibilidade, cadastrar_quarto->localizacao, cadastrar_quarto->preco);

  fclose(info_quartos);
  return cadastrar_quarto;
}

List *inserir_quarto(List *lista, Quarto *novo_quarto){

  List *novo = (List*) malloc (sizeof(List));
  novo->dados = novo_quarto;
  novo->next = lista;

  return novo;
}

List *cria_ls(){
  return NULL;
}

void Quartos_disponiveis(List *lista, int numero){
	List *percorre;

	for(percorre=lista; percorre != NULL; percorre=percorre->next){
		if(percorre->dados->disponibilidade == numero){
			printf("Numero: %d\n", percorre->dados->numero_quarto);
			printf("Preco: %.2f\n", percorre->dados->preco);
			printf("Localizacao: %s\n", percorre->dados->localizacao);
		}
	}
}