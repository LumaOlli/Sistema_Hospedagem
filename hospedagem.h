#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

//Função que , onde a reserva de cada hosede vai ser armazenado em uma lista encadeada para armazernar seus dados
Hospede *realizar_reserva();
//Função que recebe como parametro nova reserva e elemento
Lista *excluir_reserva(Lista *nova_reserva, int elemento);

void listar_reserva();

Lista *buscar_reserva(int reserva, Lista *nova_reserva);

void editar_reserva(Hospede *atualizar_reserva, int index);
