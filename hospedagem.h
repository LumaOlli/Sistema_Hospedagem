#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

/*Função que recebe como parâmetro nova reserva do tipo hospede, onde vai ser armazenado os dados dos hospedes*/
Hospede *realizar_reserva(void);

/*Função que recebe como parametro nova reserva e elemento, onde vai ser percorrida a lista para que a reserva
de um determinado hospede seja excluida*/
Lista *excluir_reserva(Lista *nova_reserva, int elemento);

/*Função listar para imprimir os dados do hospede*/
void listar_reserva();

/**/
Lista * insere(Lista *lista, Hospede *elemento);

/**/
Lista* cria_ls(); 

/**/
Lista* excluir_reserva(Lista *lista, int elemento);

/**/
void Listar_reserva(Lista* lista);

/*Função que irá buscar uma reserva específica na lista dos hospedes do hotel e retornar a lista atualizada*/
void Buscar_reserva(int numero_informado, Lista *lista);

/*Função encarregada de editar/atualizar um reserva do hotel*/
void Editar_reserva(Lista *lista, int numero_informado);

/*Função que irá olhar quantos quartos estão disponíveis no hotel*/
void consultar_quartos_disponiveis();

/*Função que irá verificar se a lista esta vazia e irá retornar a mesma*/
int vazia(Lista *nova_reserva);

/*Função responsável por verificar e mostra a quantidade de hospedes na lista*/
void quantitativo_de_hospede(Lista *nova_reserva);
