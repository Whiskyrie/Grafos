#ifndef FILA_TAD_H
#define FILA_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da fila */
typedef struct dFila DFila;
typedef DFila *pDFila;

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDFila createQueue();
void enqueueInfo(pDFila pdFila, void *info);
void *dequeueInfo(pDFila pdFila);
int isQueueEmpty(pDFila pdFila);
void destroyQueue(pDFila fila);

#endif
