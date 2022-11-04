#include <stdio.h>
#include <stdlib.h>
#include "hospedagem.h"

int main(){
    
    int opcao = 1;
    
<<<<<<< HEAD
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
	
=======
    printf("Inform option: ");
    scanf("%d", &choise);

    switch(choise){
    case 1:{
        /*system("cls");  --lembrar de colocar em todos os cases*/ 
        /*chamar função*/
        break;
    }
    case 2:{
        /*chamar função*/
        break;
    }
    /* cases 3 ate 7*/
    default:
    if(choise == 8){
      continue;
      }
    }
  }
  if(choise==8)
  printf("\n\n O Programa foi fechado");
>>>>>>> 639e832db6fa75eb1f7220050a395cf74eba722c
}