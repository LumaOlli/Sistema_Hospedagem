#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede Hospede;

typedef struct lista Lista;

int criar_reserva();

Lista *excluir_reserva(Lista *nova_reserva, int elemento);

void listar_reserva();

Lista *buscar_reserva(int reserva, Lista *nova_reserva);