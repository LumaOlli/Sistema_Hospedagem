#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto Quarto;

typedef struct list List;

/*Função responsável por cadastrar as informações dos quartos*/
Quarto *reservar_quarto(void);

/**/
List *inserir_quarto(List *list, Quarto *novo_quarto);

/**/
List *cria_ls();

/*Função que irá olhar quantos quartos estão disponíveis no hotel*/
//void Quartos_disponiveis(List *list, int numero);

/**/
List *excluir_reservaQ(List *list, int numero_identificacao);

/**/
void Listar_reservaQ(List* list);

/**/
void Buscar_reservaQ(int numero_identificao, List* list);

/**/
