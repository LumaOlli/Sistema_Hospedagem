#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

/*Função que recebe como parâmetro nova reserva do tipo hospede, onde vai ser armazenado os dados dos hospedes*/
Hospede *realizar_reservaH(void);

/*Função que recebe como parametro nova reserva e elemento, onde vai ser percorrida a lista para que a reserva
de um determinado hospede seja excluida*/
Lista *excluir_reservaH(Lista *nova_reserva, int elemento);

/*Função listar para imprimir os dados do hospede*/
void listar_reservaH();

/**/
Lista * insere_hospede(Lista *lista, Hospede *elemento);

/**/
Lista* cria_ls_hosp(); 

/**/
Lista* excluir_reservaH(Lista *lista, int elemento);

/**/
void Listar_reservaH(Lista* lista);

/*Função que irá buscar uma reserva específica na lista dos hospedes do hotel e retornar a lista atualizada*/
void Buscar_reservaH(int numero_informado, Lista *lista);

/*Função encarregada de editar/atualizar um reserva do hotel*/
void Editar_reservaH(Lista *lista, int numero_informado);

/*Função que irá verificar se a lista esta vazia e irá retornar a mesma*/
int VaziaH(Lista *nova_reserva);