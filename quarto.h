#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto Quarto;

typedef struct list List;

/*Função responsável por cadastrar as informações dos quartos*/
Quarto *reservar_quarto(void);

/*Função que recebe como parâmetro as variàveis list do tipo List e novo quarto do tipo Quarto, é responsàvel por inserir em uma lista
os quartos, retorna novo*/
List *inserir_quarto(List *list, Quarto *novo_quarto);

/*Função vazia que retorna NULL*/
List *cria_ls();

/*Função que irá olhar quantos quartos estão disponíveis no hotel*/
void Quartos_disponiveis(List *list, int numero);

/*Função que recebe como parâmetro as variáveis list do tipo List e numero indentificação do tipo int, é responsável por excluir um 
determindo quarto escolhido, tem como retorno a lista atualizada*/
List *excluir_reservaQ(List *list, int numero_identificacao);

/*Função que recebe como parâmetro a variável list do tipo List, é responsável por imprimir na tela as informações dos quartos 
cadastrados*/
void Listar_reservaQ(List* list);

/*Função que recebe como parâmetro as variáveis número indentificação, do tipo int, e list, do tipo List, é responsável por
buscar na lista um determindo quarto informado pelo usuário*/
void Buscar_reservaQ(int numero_identificao, List* list);

/*Função que recebe como parâmetro as variáveis list, do tipo List, e número indentificado, do tipo int, é responsável por buscar um
derteminado quarto e editar as informações do derteminado quarto*/
void Editar_reservaQ(List *list, int numero_identificacao);

/*Função que recebe como parâmetro as variáveis list, do tipo List, e número, do tipo int, é responsável por mostrar a quantidade de 
quartos disponiveis*/
void Quartos_disponiveis(List *list, int numero);

/*Função que recebe como parâmetro a variável list, do tipo List, é responsável por atualizar o arquovo txt*/
void listartxt_Q(List* list);