#ifndef DESENFILEIRAR_INFO_FILA_H
#define DESENFILEIRAR_INFO_FILA_H

void *dequeueInfo(pDFila pdFila)
{

    if (pdFila != NULL && isQueueEmpty(pdFila) != 0)
        return removeInfoPos(pdFila->pdLista, 1);

    /* indica que a fila estah vazia */
    return NULL;
}

#endif
