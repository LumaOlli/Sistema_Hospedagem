#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

int realizar_reserva();

Lista *excluir_reserva(Lista *nova_reserva, int elemento);

void listar_reserva();

Lista *buscar_reserva(int reserva, Lista *nova_reserva);

void editar_reserva(Hospede *nova_reserva, int index);