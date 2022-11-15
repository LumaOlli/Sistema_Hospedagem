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
	int info;
	Lista *nova_reserva;
};

Hospede *realizar_reserva(Hospede *nova_reserva){
	int opcao;

	nova_reserva=(Lista*)malloc(sizeof(Lista));

	while(opcao == 1){

		printf("Informe o nome: \n");
		scanf(" %[^\n]", nova_reserva->nome);
		system("cls");
		printf("Informe a duracao da estadia: \n");
		scanf("%d", &nova_reserva->duracao_de_estadia);
		system("cls");
		printf("Informe o documento: \n");
		scanf(" %[^\n]", nova_reserva->documento);
		system("cls");

		printf("Deseja continuar marcando nova reserva?\n");
		printf("    <1-SIM>               <2-NAO>\n");
		scanf("%d", &opcao);

	}
	return nova_reserva;
}	

Lista *excluir_reserva(Lista *nova_reserva, int elemento){

	Lista *anterior =NULL;
	Lista *percorre = nova_reserva;

	while(percorre->nova_reserva = elemento){
		
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

	FILE *listar_a_reserva = fopen("ListarReserva.txt", "rw");

	if(listar_a_reserva == NULL){
		printf("Nao foi possivel abrir o arquivo!!\n");
		exit (1);		
	}
}

Lista *buscar_reserva(int reserva, Lista *nova_reserva){
	Lista * percorre;

	for(percorre=nova_reserva; percorre != NULL; percorre=percorre->nova_reserva){
		if (percorre->info == reserva){
			return percorre;
		}		
	}

	return NULL;
}

void editar_reserva(Hospede *atualizar_reserva, int index){
	printf("================================================================");
	printf("                        EDITAR RESERVA                          ");
	printf("================================================================");

	printf("A escolha da edição foi %s\n", atualizar_reserva[index].nome);
	printf("Procesando..\n");
	printf("Nome: \n");
	scanf(" %[^\n]", atualizar_reserva[index].nome);
	
	printf("Tempo de estadia: \n");
	scanf("%d", &atualizar_reserva[index].duracao_de_estadia);

	printf("Documento: \n");
	scanf(" %[^\n]", atualizar_reserva[index].documento);
}

void consultar_quartos_disponiveis(){
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

int vazia(Lista *nova_reserva){
	return nova_reserva == NULL;
}

void quantitativo_de_hospede(Lista *nova_reserva){
	int i = 0;

	if(vazia(nova_reserva)){
		printf("A lista está vazia!!\n");
	}
	else{
		while(nova_reserva != NULL){
			printf("%i", nova_reserva->info);
			nova_reserva = nova_reserva->info;
			i++;
		}
	}

	printf("Ha %i hospedes no Hotel!\n", i);
}