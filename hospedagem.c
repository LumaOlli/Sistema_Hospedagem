<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> b714e2d18d91e35e96624d80bc8879d2f7c7c9c4
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
	Lista *prox_hospede;
};

int marcar_reserva(){
	
	Hospede *novo_hospede;
	Lista *prox_hospede;
	int opcao;
	
	novo_hospede = (Lista*)malloc(sizeof(Lista));
	
	if(novo_hospede == NULL){
		exit (1);
	}
	
	do{
		printf("Informe o nome: ");
		scanf("%[\n]", &novo_hospede->nome);
		printf("Informe a sua estadia: ");
		scanf("%d", &novo_hospede->duracao_de_estadia);
		printf("Agora informe o seu documento: ");
		scanf("%[\n]", &novo_hospede->documento);
		
		printf("Deseja inserir um novo hospede?\n");
		printf("   <1> Sim           <2>Não");
		scanf("%d", &opcao);
		
	}while(opcao == 2);
	
	FILE *infoHotel = fopen("quarto.txt", "r");
	
	if(infoHotel == NULL){
		printf("ERRO AO ABRIR ARQUIVO!\n");
	}else{
		printf("AGUARDE UM MOMENTO...\n");
	}
	
	char c, dados[]="quarto.txt", infos[50];
	int i;
	char *pesquisar = "Disponibilidade: Sim";
	
	while((c = fgetc(infoHotel)) != EOF){//c vai ser igual a uma palavra no arquivo enquanto não for o final do arquivo
		
		if(c == pesquisar){//primeiro caractere da string que que estamos procurando
		
			for(i = 0; i < strlen(pesquisar); i++){//cada caractere que da string que vai ser comparado com o próximo 
				c = fgetc(infoHotel);//vai ler mais um caracter
				if(c == EOF){//se chegar no final vai parar
					break;
				}
				if(*(pesquisar + i) != c){//se um caracter subsequente for diferente da pesquisar vai sair do loop
					break;
				}
			}   
			
			if(i == strlen(pesquisar)){//se i == qtd 
				while((fgets(infos, sizeof(infos)), infoHotel) != NULL){
					
				}
				break;
			}	
		}
	}
}

void excluir_reserva()
<<<<<<< HEAD
=======
=======
>>>>>>> f45ee8f5b7b124c78dcaef83a21855ded7976bc6
>>>>>>> b714e2d18d91e35e96624d80bc8879d2f7c7c9c4
