#ifndef ESTAVAZIA_FILA_H
#define ESTAVAZIA_FILA_H

int isQueueEmpty(pDFila pdFila)
{

    if (pdFila != NULL)
    {
        return pdFila->pdLista->quantidade;
    }
    else
    {
        return 0;
    }
}
#endif
