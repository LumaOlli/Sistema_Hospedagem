#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

/*Função que recebe como parâmetro um vazio, onde vai ser armazenado os dados dos hospedes*/
Hospede *realizar_reservaH(void);

/*Função que recebe como parametro as variáveis lista do tipo Lista e numero informado do tipo int, 
onde vai ser percorrida a lista para que a reserva de um determinado hospede seja excluida, retorna a lista atualizada*/
Lista* excluir_reservaH(Lista *lista, int numero_informado);

/*Função listar para imprimir os dados do hospede*/
void listar_reservaH();

/*Função que recebe como parâmetro lista do tipo Lista, e elemento do tipo Hospede, onde vai ser inserido e ordenado em uma lista
os dados do hospede, retorna a lista*/
Lista * insere_hospede(Lista *lista, Hospede *elemento);

/*Função vazia que retona NULL*/
Lista* cria_ls_hosp(); 

/*Função que recebe como parâmetro a variável lista do tipo lista, onde vai ser imprimido na tela os dados do hospede*/
void Listar_reservaH(Lista *lista);

/*Função que recebe como parâmetros numero informado do tipo int e lista do tipo Lista, a função irá buscar uma 
reserva específica na lista dos hospedes do hotel e retornar a lista atualizada*/
void Buscar_reservaH(int numero_informado, Lista *lista);

/*Função que recebe como parâmetros lista do tipo Lista e numero informado do tipo int, 
é encarregada de editar/atualizar um reserva do hotel*/
void Editar_reservaH(Lista *lista, int numero_informado);

/*Função que recebe como parâmetro lista do tipo lista, e irá verificar se a lista esta vazia e irá retornar a mesma*/
int lista_vazia(Lista *lista);

/*Função que recebe como parâmetro lista do tipo lista, responsável por verificar quantos hospedes tem na lista*/
void quantitativo_de_hospede(Lista *lista);