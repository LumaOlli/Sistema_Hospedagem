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

Hospede *realizar_reservaH(void){

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
	    printf("Erro ao abrir arquivo\n");
	} else{
	    printf("Salvo com sucesso!\n");
	}
    fprintf(arquivo_hosp,"Nome: %s\nTempo de reserva:%d\nDocumento: %s\nNumero do hospede:%d\n", nova_reserva->nome, nova_reserva->duracao_de_estadia, nova_reserva->documento, nova_reserva->numero_do_hospede);
    fclose(arquivo_hosp);

	return nova_reserva;
}	

Lista *insere_hospede(Lista *lista, Hospede *elemento){
    
	Lista *novo;
	Lista *ant = NULL;
	Lista *percorre = lista;

	while(percorre != NULL && percorre->info<elemento){
		ant = percorre;
		percorre = percorre->prox;
	}

	novo = (Lista*)malloc(sizeof(Lista));

	novo->info = elemento;

	if(ant == NULL){
		novo->info = lista;
		lista = novo;
	}
	else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return lista;
}

Lista* cria_ls_hosp(){
	return NULL;
}

Lista* excluir_reservaH(Lista *lista, int numero_informado){
	Lista *anterior= NULL;
	Lista *percorre = lista;
	while(percorre->info->numero_do_hospede != numero_informado){
		if(percorre == NULL){
			return lista;
		}
		anterior = percorre;
        percorre =percorre->prox;
	}
	/*Fazendo exclução*/
	if(anterior == NULL){//caso seja no inicio do elemento
		lista=percorre->prox;
	}
	else{
		anterior->prox=percorre->prox;
	}
	free(percorre);
	return lista;	
}

void Listar_reservaH(Lista* lista){
	Lista*percorre;

	for(percorre=lista; percorre!=NULL; percorre=percorre->prox){
		printf("Nome = %s \n", percorre->info->nome);
		printf("Tempo de duracao = %d \n", percorre->info->duracao_de_estadia);
		printf("Documento = %s \n", percorre->info->documento);
	}

}

void Buscar_reservaH(int numero_informado, Lista* lista){
	Lista * percorre;

	for(percorre=lista; percorre !=NULL; percorre=percorre->prox){
		if(percorre->info->numero_do_hospede == numero_informado){
		printf("Nome = %s\n", percorre->info->nome);
		printf("Tempo de duracao = %d\n", percorre->info->duracao_de_estadia);
		printf("Documento = %s\n", percorre->info->documento);
		}
	}

}

void Editar_reservaH(Lista *lista, int numero_informado){
	Lista *percorre;
	
	for(percorre = lista ;percorre != NULL;percorre = percorre->prox){
		if(percorre->info->numero_do_hospede == numero_informado){
			printf("Informe o novo nome:\n");
			scanf(" %[^\n]", percorre->info->nome);
			printf("Novo tempo de duracao: \n");
			scanf("%d", &percorre->info->duracao_de_estadia);
			printf("Novo documento:\n");
			scanf(" %[^\n]", percorre->info->documento);
		}
	}

}

int lista_vazia(Lista *lista){
	return lista == NULL;
}

void quantitativo_de_hospede(Lista *lista){
	int i=0, j;

	if(lista_vazia(lista))
		printf("A lista esta vaizia!\n");
	
	
	else{
		for(j = 0; j> lista != NULL; j++){
			
			printf("%d", lista->info);
			lista = lista->prox;
			i++;
		}

		printf("\nHa %d hospedes!!\n", i);
	}
}