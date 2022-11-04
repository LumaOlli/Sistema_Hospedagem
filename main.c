#include <stdio.h>
#include <stdlib.h>
#include "hospedagem.c"

int main(){
    
  int opcao = 1;
    
  while(opcao != 8){
		printf("\n===============================");
		printf("\n            MENU\n");
		printf("     1 - Marcar Reserva\n");
		printf("     2 - Excluir Reserva\n");
		printf("     3 - Listar Reserva\n");
		printf("     4 - Buscar Reserva\n");
		printf("     5 - Editar Reserva\n");
		printf("     6 - Verificar disponibilidade de quartos\n");
		printf("     7 - Consultar quantidade de hospedes\n");
		printf("     8 - Sair\n");
		printf("\n==================================\n");
		
		printf("\nInforme a acao que deseja realizar: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				criar_reserva;
				break;
			
		}
	}
	
}
