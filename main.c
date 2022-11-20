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
    List *lista = cria_ls();
    int exc_reserva;
    int buscar_reserva;
    int edit_reserva;
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
                reserva = realizar_reserva();
                lista = insere_hospede(lista, reserva);
                cadastra = reservar_quarto();
                lista = inserir_quarto(lista, cadastra);
                break;

            case OPCAO2:
                printf("Informe o numero de hospede: ");
                scanf("%d", &exc_reserva);
                lista = excluir_reserva(lista, exc_reserva);
                printf("Excluido com Sucesso!\n");
                Beep(1000,500);
                break;

            case OPCAO3:
                Listar_reserva(lista);
                break;

            case OPCAO4:
                printf("Informe o numero de hospede:");
                scanf("%d", &buscar_reserva);
                Buscar_reserva(buscar_reserva, lista);
                break;

            case OPCAO5:
                printf("Informe o numero de hospede:");
                scanf("%d", &edit_reserva);
                Editar_reserva(lista, edit_reserva);
                break;

            case OPCAO6:
                printf("Informe <1> para disponibilidade dos quartos:");
                scanf("%d", &dispo_quarto);
                if(1){
                    Quartos_disponiveis(lista, dispo_quarto);
                }
                else{
                    printf("Hiii, não quervermos ver os quartosdisponiveis\n");
                }
                break;

            case OPCAO7:

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