#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Fila.h"

int main()
{
    pDFila pFilaInt = createQueue();

    pDFila pFilaCopia = createQueue();

    /* teste de enfileiramento */
    enqueueInfo(pFilaInt, allocateInt(5));
    enqueueInfo(pFilaInt, allocateInt(3));
    enqueueInfo(pFilaInt, allocateInt(9));
    enqueueInfo(pFilaInt, allocateInt(1));
    enqueueInfo(pFilaInt, allocateInt(2));

    /* teste de desenfileiramento */
    void *info = dequeueInfo(pFilaInt);
    enqueueInfo(pFilaCopia, info);
    printf("\nRetirou o inteiro = %d \n", *((int *)info));

    while (isQueueEmpty(pFilaInt) != 0)
    {
        info = dequeueInfo(pFilaInt);
        enqueueInfo(pFilaCopia, info);
        printf("\nRetirou o inteiro = %d \n", *((int *)info));
    }

    /* Como ficou a fila original? ficou vazia!
       Mas temos uma c�pia dela na outra fila */
}
