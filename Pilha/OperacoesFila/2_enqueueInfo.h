#ifndef ENFILEIRAR_INFO_FILA_H
#define ENFILEIRAR_INFO_FILA_H

void enqueueInfo(pDFila pdFila, void *info)
{

    if (pdFila != NULL)
        addInfo(pdFila->pdLista, info);
}

#endif
