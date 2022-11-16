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
    fprintf(arquivo_hosp,"Nome: %s\nTempo de reserva:%d\nDocumento: %s\n", nova_reserva->nome, nova_reserva->duracao_de_estadia, nova_reserva->documento);
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
/*
Lista *excluir_reserva(Lista *nova_reserva, int elemento){

	Lista *anterior =NULL;
	Lista *percorre = nova_reserva;

	while(percorre->info->numero_do_hospede != elemento){
		
		if(percorre == NULL){
			anterior = percorre;
			percorre = percorre->prox;
			
			return percorre;
		}
	}	
	if(anterior == NULL){
		nova_reserva = percorre->prox;
	}

	else{
		anterior->prox = percorre->prox; 
	}

	free(percorre);

	return nova_reserva;
	
}

void listar_reserva(){
  FILE *arquivo_hosp;
  char Linha[100];
  char *result;
  int i;
  // Abre um arquivo TEXTO para LEITURA
  arquivo_hosp = fopen("ListarReserva.txt", "rt");
  if (arquivo_hosp == NULL){  // Se houve erro na abertura
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arquivo_hosp)){
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arquivo_hosp);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
	  printf("%s",i,Linha);
      i++;
  }
  fclose(arquivo_hosp);
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

  arq=fopen("Quarto.txt", "rt"); //Abre o arquivo TEXTO para leitura
  if(arq == NULL){  //Caso tenha erro na abertura do arquivo
    printf("Erro na abertura do arquivo");
    return;
  }

  i=1;
  while(!feof(arq)){//Lê linha(inclusive com '/n')*/
  /*<FEOF> retorna um valor dif. de zero se uma operação de
  leitura tentou ler após o final do arquivo. Caso contrário
  return 0.*//*
    resultado=fgets(Linha, 100, arq);
    if(resultado){
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
}*/