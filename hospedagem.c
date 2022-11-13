#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospedagem.h"

struct hospede{
	char nome[100];
	int duracao_de_estadia;
	char documento[80];
};

struct lista{
	Hospede info;
	Lista *nova_reserva;
};

int marcar_reserva(){
	Hospede *nova_reserva;
	int opcao;

	nova_reserva = (Lista*)malloc(sizeof(Lista));

	while(opcao == 1){

		printf("Informe o nome: \n");
		scanf(" %[^\n]", &nova_reserva->nome);
		system("cls");
		printf("Informe a duracao da estadia: \n");
		scanf("%d", &nova_reserva->duracao_de_estadia);
		system("cls");
		printf("Informe o documento: \n");
		scanf(" %[^\n]", &nova_reserva->documento);
		system("cls");

		printf("Deseja continuar marcando nova reserva?\n");
		printf("    <1-SIM>               <2-NAO>\n");
		scanf("%d", &opcao);

	}
}	

Lista *excluir_reserva(Lista *nova_reserva, int elemento){

	Lista *anterior =NULL;
	Lista *percorre = nova_reserva;

	while(percorre->nova_reserva != elemento){
		
		if(percorre == NULL){
			anterior = percorre;
			percorre = percorre->nova_reserva;
			
			return percorre;
		}
		
		if(anterior == NULL){
			nova_reserva = percorre->nova_reserva;
		}

		else{
			anterior->nova_reserva = percorre->nova_reserva; 
		}

		free(percorre);

		return printf("A reserva solicitada foi excluida com sucesso!!\n");
	}
}

void listar_reserva(){

	FILE *listar_a_reserva = fopen("ListarReserva,txt", "rw");

	if(listar_a_reserva == NULL){
		printf("Nao for possivel abrir o arquivo!!\n");
		exit -1;		
	}
}

Lista *buscar_reserva(int reserva, Lista *nova_reserva){
	Lista *percorre;

	for(percorre=nova_reserva; percorre != NULL; percorre=percorre->nova_reserva){
		if (percorre->info == reserva){
			return percorre;
		}		
	}

	return NULL;
}

void editar_reserva(Hospede *nova_reserva, int index){
	printf("Editar reserva %s", nova_reserva[index].nome);
	printf("Novo nome: ");
	fflush(stdin); //Sua finalidade é limpar (ou liberar) o buffer de saída
	fgets(nova_reserva[index].nome, 100, stdin);	// lê uma cadeia de caracteres do argumento stream de entrada e o armazena em str

	printf("Novo tempo de duracao: ");
	fflush(stdin); //Sua finalidade é limpar (ou liberar) o buffer de saída
	fgets(nova_reserva[index].duracao_de_estadia, 0, stdin);	// lê uma cadeia de caracteres do argumento stream de entrada e o armazena em str

	printf("Novo documento: ");
	fflush(stdin); //Sua finalidade é limpar (ou liberar) o buffer de saída
	fgets(nova_reserva[index].documento, 80, stdin);	// lê uma cadeia de caracteres do argumento stream de entrada e o armazena em str
}