#ifndef CRIAR_PILHA_H
#define CRIAR_PILHA_H
#include <stdlib.h>

pDPilha createStack()
{
    /* aloca memoria para o descritor */
    pDPilha pd = (pDPilha)malloc(sizeof(DPilha));

    /* o descritor da pilha tem os mesmos campos do descritor de lista */
    pd->pdLista = createList();
    return pd;
}

#endif
