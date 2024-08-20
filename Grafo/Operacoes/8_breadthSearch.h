#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void breadthSearch(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi)
{
    pDFila verticesPendentes;
    pDLista verticesVisitados;

    verticesPendentes = createQueue();
    verticesVisitados = createList();

    // Enfileira o primeiro vértice do grafo
    enqueueInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

    while (isQueueEmpty(verticesPendentes) != 0)
    {
        pVertice vAtual = dequeueInfo(verticesPendentes);

        // Visita o vértice se ainda não foi visitado
        if (containsInfo(verticesVisitados, vAtual, fc) == 0)
        {
            fi(vAtual);
            addInfo(verticesVisitados, vAtual);

            // Enfileira todas as adjacências do vértice atual que não foram visitadas
            pNoh atual = vAtual->listaAdjacencias->primeiro;
            while (atual != NULL)
            {
                if (containsInfo(verticesVisitados, atual->info, fc) == 0)
                {
                    enqueueInfo(verticesPendentes, atual->info);
                }
                atual = atual->prox;
            }
        }
    }

    // Libera a memória alocada
    destroyQueue(verticesPendentes);
    destroyList(verticesVisitados);
}
#endif
