#ifndef EMPILHAR_INFO_PILHA_H
#define EMPILHAR_INFO_PILHA_H

void pushInfo(pDPilha pdPilha, void *info)
{

    if (pdPilha != NULL)
        addInfo(pdPilha->pdLista, info);
}

#endif
