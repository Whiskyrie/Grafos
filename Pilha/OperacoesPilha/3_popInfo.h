#ifndef DESEMPILHAR_INFO_PILHA_H
#define DESEMPILHAR_INFO_PILHA_H

void *popInfo(pDPilha pdPilha)
{

   if (pdPilha != NULL && isStackEmpty(pdPilha) != 0)
      return removeInfoPos(pdPilha->pdLista,
                           pdPilha->pdLista->quantidade);

   /* indica que a pilha estah vazia */
   return NULL;
}

#endif
