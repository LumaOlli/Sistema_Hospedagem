#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto Quarto;

typedef struct list List;

/*Função responsável por cadastrar as informações dos quartos*/
Quarto *reservar_quarto(void);

/**/
List *inserir(List *lista, Quarto *novo_quarto);

/**/
List *cria();