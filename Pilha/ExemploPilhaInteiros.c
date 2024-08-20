#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Pilha.h"

int main()
{
    pDPilha pPilhaInt = createStack();

    /* teste de empilhamento */
    pushInfo(pPilhaInt, allocateInt(5));
    pushInfo(pPilhaInt, allocateInt(3));
    pushInfo(pPilhaInt, allocateInt(9));
    pushInfo(pPilhaInt, allocateInt(1));
    pushInfo(pPilhaInt, allocateInt(2));

    /* teste de desempilhamento */
    void *info = popInfo(pPilhaInt);
    printf("\nDesempilhou o inteiro = %d \n", *((int *)info));

    while (isStackEmpty(pPilhaInt) == 0)
    {
        info = popInfo(pPilhaInt);
        printf("\nDesempilhou o inteiro = %d \n", *((int *)info));
    }
}
