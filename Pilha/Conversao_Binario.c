#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Utils.h"

/* --------------------------*/
int main()
{

    pDPilha pilha;

    int n;

    scanf("%d", &n);

    pilha = createStack();

    int *r;

    while (n > 0)
    {

        r = (int *)malloc(sizeof(int));
        *r = n % 2;

        pushInfo(pilha, r);

        n = n / 2;
    }

    /* teste de desempilhamento */
    void *info = popInfo(pilha);
    printf("\nDesempilhou o inteiro = %d \n", *((int *)info));

    while (isStackEmpty(pilha) != 0)
    {
        info = popInfo(pilha);
        printf("\nDesempilhou o inteiro = %d \n", *((int *)info));
    }

    // void *info;

    // info = popInfo(pilha);
    // printf("\n");
    // printInt(info);

    // printf("\n");
    // mostrarPilha(pilha, printInt);
}
