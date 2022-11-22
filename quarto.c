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
  printf("  <1> Sim    <2> Nao   ");
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

List *inserir_quarto(List *list, Quarto *novo_quarto){

  List *novo = (List*) malloc (sizeof(List));
  novo->dados = novo_quarto;
  novo->next = list;

  return novo;
}

List *cria_ls(){
  return NULL;
}

List *excluir_reservaQ(List *list, int numero_identificacao){
	List *ant= NULL;
	List *p= list;
	while(p->dados->numero_quarto != numero_identificacao){
		if(p == NULL){
			return list;
		}
		ant=p;
    p=p->next;
	}
	/*Fazendo exclução*/
	if(ant == NULL){//caso seja no inicio do elemento
		list=p->next;
	}
	else{
		ant->next=p->next;
	}
	free(p);
	return list;	
}

void Listar_reservaQ(List* list){

	List*p;

	for(p=list; p!=NULL; p=p->next){
		printf("Numero do quarto = %d \n", p->dados->numero_quarto);
    printf("Disponibilidade = %d \n", p->dados->disponibilidade);
		printf("Localizacao = %s \n", p->dados->localizacao);
    printf("Preco = %.2f \n", p->dados->preco);
	}

}

void Buscar_reservaQ(int numero_identificao, List* list){
	List *p;

	for(p =list; p !=NULL; p =p->next){
		if(p->dados->numero_quarto == numero_identificao){
		printf("Numero do quarto = %d \n", p->dados->numero_quarto);
    printf("Disponibilidade = %d \n", p->dados->disponibilidade);
		printf("Localizacao = %s \n", p->dados->localizacao);
    printf("Preco = %.2f \n", p->dados->preco);
		}
	}

}

void Editar_reservaQ(List *list, int numero_identificacao){
	List *p;
	
	for(p = list; p != NULL; p = p->next){
		if(p->dados->numero_quarto == numero_identificacao){
			printf("Numero do quarto:\n");
      scanf("%d", &p->dados->numero_quarto);
      printf("Disponibilidade: \n");
      scanf("%d", &p->dados->disponibilidade);
      printf("Localizacao: \n");
      scanf(" %[^\n]", p->dados->localizacao);
      printf("Preco: \n");
      scanf("%f", &p->dados->preco);
		}
	}

}

void Quartos_disponiveis(List *list, int numero){
	List *percorre;

	for(percorre=list; percorre != NULL; percorre=percorre->next){
		if(percorre->dados->disponibilidade == numero){
			printf("Numero: %d\n", percorre->dados->numero_quarto);
			printf("Preco: %.2f\n", percorre->dados->preco);			
      printf("Localizacao: %s\n", percorre->dados->localizacao);
		}
	}
}