#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

//Função que recebe como parâmetro nova reserva do tipo hospede, onde vai ser armazenado os dados dos hospedes
Hospede *realizar_reserva(Hospede *nova_reserva);

//Função que recebe como parametro nova reserva e elemento, onde vai ser percorrida a lista para que a reserva
//de um determinado hospede seja excluida
Lista *excluir_reserva(Lista *nova_reserva, int elemento);

//
void listar_reserva();

Lista *buscar_reserva(int reserva, Lista *nova_reserva);

void editar_reserva(Hospede *atualizar_reserva, int index);
