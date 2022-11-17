#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospedagem.h"

struct hospede{
	char nome[100];
	int duracao_de_estadia;
	char documento[80];
	int numero_do_hospede;
};

struct lista{
	Hospede *info;
	Lista *prox;
};

Hospede *realizar_reserva(void){

	Hospede *nova_reserva;
	nova_reserva=(Hospede*)malloc(sizeof(Hospede));

	printf("Informe o nome: \n");
	scanf(" %[^\n]", nova_reserva->nome);
	printf("Informe a duracao da estadia: \n");
	scanf("%d", &nova_reserva->duracao_de_estadia);
	printf("Informe o documento: \n");
	scanf(" %[^\n]", nova_reserva->documento);
	printf("Informe o numero do hospede: \n");
	scanf("%d", &nova_reserva->numero_do_hospede);

	FILE *arquivo_hosp;
	arquivo_hosp = fopen("ListarReserva.txt", "a"); 
	
	if(arquivo_hosp == NULL){
	    printf("Erro ao abrir arquivo");
	} else{
	    printf("Salvo com sucesso!");
	}
    fprintf(arquivo_hosp,"Nome: %s\nTempo de reserva:%d\nDocumento: %s\nNumero do hospede:%d\n", nova_reserva->nome, nova_reserva->duracao_de_estadia, nova_reserva->documento, nova_reserva->numero_do_hospede);
    fclose(arquivo_hosp);

	return nova_reserva;
}	

Lista *insere(Lista *lista, Hospede *elemento){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    nova->info = elemento;
    nova->prox = lista;
    return nova;
}

Lista* cria_ls(){
	return NULL;
}

Lista* excluir_reserva(Lista *lista, int elemento){
	Lista *anterior= NULL;
	Lista *percorre = lista;
	while(percorre->info != NULL){
		if(percorre == NULL){
			return percorre;
		
			anterior = percorre;
            percorre =percorre->prox;
		}
	}
	if(anterior == NULL){
		lista=percorre->prox;
	}
	else{
		anterior->prox=percorre->prox;
	}
	free(percorre);
	return lista;	
}