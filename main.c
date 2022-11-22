#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hospedagem.c"
#include "quarto.c"

#define TITULO_OPCAO1 "realizar reserva"
#define TITULO_OPCAO2 "excluir reserva"
#define TITULO_OPCAO3 "listar reserva"
#define TITULO_OPCAO4 "buscar reserva"
#define TITULO_OPCAO5 "editar reserva"
#define TITULO_OPCAO6 "consultar quartos disponiveis"
#define TITULO_OPCAO7 "consultar quantitativo de hospedes"
#define TITULO_OPCAO8 "sair do programa"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

 void LimpaBuffer(void){
    int ValorLido;
    
    do{
        ValorLido = getchar();
    }while ((ValorLido != '\n') && (ValorLido != EOF));
 }

int LeOpcao(int menorValor, int maiorValor){

    int op;

    while(1){
        printf("\nInforme sua opcao: ");

        op = getchar();

        if(op >= menorValor && op <= maiorValor){
            LimpaBuffer();
            break;
        }
        else{
            printf("\nOpcao invalida. Tente novamente!");
            printf("\nOpcao deve estar entre %c e %c.\n", menorValor, maiorValor);

            LimpaBuffer();
        }
    }
    return op;
}

void ApresentaMenu(int nItens, int menorOpcao, ...){
    int i;

    va_list argumentos;

    va_start(argumentos, menorOpcao);

    for(i=0; i< nItens; i++){
        printf("%c - %s \n", menorOpcao++, va_arg(argumentos, char*));
    }

    va_end(argumentos);
}

int main(void){
    unsigned char op;
    unsigned int saida = 0;
    Hospede *reserva;
    Lista *lista = cria_ls_hosp();
    List *list = cria_ls();
    int exc_hospede, exc_quarto;
    int buscar_hospede, buscar_quarto;
    int edit_hospede, edit_quarto;
    int dispo_quarto;
    Quarto *cadastra;

    do{
        printf("\n");
        ApresentaMenu (N_OPCOES, OPCAO1,
                        TITULO_OPCAO1, TITULO_OPCAO2,
                        TITULO_OPCAO3, TITULO_OPCAO4,
                        TITULO_OPCAO5, TITULO_OPCAO6, 
                        TITULO_OPCAO7, TITULO_OPCAO8);

        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);

        switch(op){
            case OPCAO1:
                Beep(1000,500);
                reserva = realizar_reservaH();
                lista = insere_hospede(lista, reserva);
                cadastra = reservar_quarto();
                list = inserir_quarto(list, cadastra);
                break;

            case OPCAO2:
                printf("Informe o numero de hospede: ");
                scanf("%d", &exc_hospede);
                lista = excluir_reservaH(lista, exc_hospede);
                printf("Informe o numero do quarto: ");
                scanf("%d", &exc_quarto);
                list = excluir_reservaQ(list, exc_quarto);
                printf("Excluido com Sucesso!\n");
                Beep(1000,500);
                break;
                
            case OPCAO3:
                Listar_reservaH(lista);
                Listar_reservaQ(list);
                break;

            case OPCAO4:
                printf("Informe o numero de hospede:");
                scanf("%d", &buscar_hospede);
                Buscar_reservaH(buscar_hospede, lista);
                printf("Informe o numero do quarto:");
                scanf("%d", &buscar_quarto);
                Buscar_reservaQ(buscar_quarto, list);
                break;

            case OPCAO5:
                printf("Informe o numero de hospede:");
                scanf("%d", &edit_hospede);
                Editar_reservaH(lista, edit_hospede);
                printf("Informe o numero do quarto:");
                scanf("%d", &edit_quarto);
                Editar_reservaQ(list, edit_quarto);
                break;

            case OPCAO6:
                printf("Informe <1> para verificar a disponibilidade dos quartos:");
                scanf("%d", &dispo_quarto);
                Quartos_disponiveis(list, dispo_quarto);
                break;

            case OPCAO7:
                quantitativo_de_hospede(lista);
                break; 

            case OPCAO8:
                saida = 1;
                printf("Obrigado por usar este programa\n");
                break;
        
            default:
                printf("Este programa possui um bug!\n");
                return 1;   
        }
    }while(!saida);

    return 0;
}