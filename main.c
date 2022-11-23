#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hospedagem.c"
#include "quarto.c"

#define TITULO_OPCAO1 "Realizar Reserva"
#define TITULO_OPCAO2 "Excluir Reserva"
#define TITULO_OPCAO3 "Listar Reserva"
#define TITULO_OPCAO4 "Buscar Reserva"
#define TITULO_OPCAO5 "Editar Reserva"
#define TITULO_OPCAO6 "Consultar Quartos Disponiveis"
#define TITULO_OPCAO7 "Consultar Quantitativo de Hospedes"
#define TITULO_OPCAO8 "Sair do Programa"

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

    Lista*percorre;
    List *p;

    Lista *lista = cria_ls_hosp();
    List *list = cria_ls();
    int exc_hospede, exc_quarto;
    int buscar_hospede, buscar_quarto;
    int edit_hospede, edit_quarto;
    int dispo_quarto;
    Quarto *cadastra;

    printf("\n===============================\n");
    printf("             MENU              \n");
    printf("===============================\n");
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
                printf("\n===============================\n");
                printf("       Realizar Reserva        \n");
                printf("===============================\n");
                Beep(1000,500);
                printf("\n");
                reserva = realizar_reservaH();
                lista = insere_hospede(lista, reserva);
                printf("\n");
                cadastra = reservar_quarto();
                list = inserir_quarto(list, cadastra);
                system("cls");
                printf("\n");
                break;

            case OPCAO2:
                printf("\n===============================\n");
                printf("       Excluir Reserva         \n");
                printf("===============================\n");
                printf("Informe o numero de hospede: ");
                scanf("%d", &exc_hospede);
                lista = excluir_reservaH(lista, exc_hospede);
                printf("\n");
                printf("Informe o numero do quarto: ");
                scanf("%d", &exc_quarto);
                list = excluir_reservaQ(list, exc_quarto);
                printf("\n");
                printf("Excluido com Sucesso!\n");
                printf("\n");
                Beep(1000,500);
                break;
                
            case OPCAO3:
                printf("\n===============================\n");
                printf("        Listar Reserva         \n");
                printf("===============================\n");
                printf("Hospedes\n");
                Listar_reservaH(lista);
                printf("Quartos\n");
                Listar_reservaQ(list);
                printf("\n");
                break;

            case OPCAO4:
                printf("\n===============================\n");
                printf("        Buscar Reserva         \n");
                printf("===============================\n");
                printf("Informe o numero de hospede:");
                scanf("%d", &buscar_hospede);
                Buscar_reservaH(buscar_hospede, lista);
                printf("\n");
                printf("Informe o numero do quarto:");
                scanf("%d", &buscar_quarto);
                Buscar_reservaQ(buscar_quarto, list);
                printf("\n");
                break;

            case OPCAO5:
                printf("\n===============================\n");
                printf("        Editar Reserva         \n");
                printf("===============================\n");
                printf("Informe o numero de hospede:");
                scanf("%d", &edit_hospede);
                Editar_reservaH(lista, edit_hospede);
                printf("\n");
                printf("Informe o numero do quarto:");
                scanf("%d", &edit_quarto);
                Editar_reservaQ(list, edit_quarto);
                printf("\n");
                break;

            case OPCAO6:
                printf("\n======================================\n");
                printf("    Consultar Quartos Disponiveis     \n");
                printf("======================================\n");
                printf("Informe <1> para verificar a disponibilidade dos quartos:");
                scanf("%d", &dispo_quarto);
                Quartos_disponiveis(list, dispo_quarto);
                printf("\n");
                break;

            case OPCAO7:
                printf("\n============================================\n");
                printf("    Consultar Quatitativos de  Hospedes     \n");
                printf("============================================\n");
                quantitativo_de_hospede(lista);
                printf("\n");
                break; 

            case OPCAO8:
                Listartxt(lista);
                listartxt_Q(list);
                saida = 1;
                printf("Obrigado por usar este programa\n");
                printf("\n======================\n");
                printf("     Tchau ;)       \n");
                printf("    Boas ferias     \n");
                printf("====================\n");
                break;
        
            default:
                printf("Este programa possui um bug!\n");
                return 1;   
        }
    }while(!saida);

    return 0;
}