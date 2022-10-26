#include "hospedagem.h"

int main(void){
    int choise=1;
    
  while(choise != 8){
    printf("\n                   MENU                       \n");
    printf("================================================\n");
    printf("1. Make reservation\n");
    printf("2. Relete reservation\n");
    printf("3. List reservation\n");
    printf("4. Search for reservation\n");
    printf("5. Edit reservation\n");
    printf("6. Check available rooms\n");
    printf("7. Consult number of guests\n");
    printf("8. Go out\n");
    printf("================================================\n");
    
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
}