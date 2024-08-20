#ifndef DESTROY_QUEUE_H
#define DESTROY_QUEUE_H

void destroyQueue(pDFila fila)
{
    if (fila == NULL)
    {
        return;
    }
    // Remove e libera todos os elementos da fila
    while (!isQueueEmpty(fila))
    {
        void *item = dequeueInfo(fila);
        free(item);
    }
    free(fila);
}

#endif // DESTROY_QUEUE_H