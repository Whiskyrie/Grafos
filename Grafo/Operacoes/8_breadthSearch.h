#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void breadthSearch(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi)
{
    pDLista verticesPendentes;
    pDLista verticesVisitados;

    verticesPendentes = createList();
    verticesVisitados = createList();

    // Insere o primeiro vértice na lista de pendentes
    addInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

    while (verticesPendentes->quantidade > 0)
    {
        pNoh nohAtual = verticesPendentes->primeiro;
        pVertice verticeAtual = (pVertice)nohAtual->info;

        // Visita o vértice se ainda não foi visitado
        if (containsInfo(verticesVisitados, verticeAtual, fc) == 0)
        {
            fi(verticeAtual);
            addInfo(verticesVisitados, verticeAtual);

            // Insere as adjacências do vértice atual na lista de pendentes, se não foram visitadas
            pNoh atual = verticeAtual->listaAdjacencias->primeiro;
            while (atual != NULL)
            {
                if (containsInfo(verticesVisitados, atual->info, fc) == 0)
                {
                    addInfo(verticesPendentes, atual->info);
                }
                atual = atual->prox;
            }
        }

        // Remove o vértice atual da lista de pendentes
        verticesPendentes->primeiro = nohAtual->prox;
        if (verticesPendentes->quantidade == 1)
        {
            verticesPendentes->ultimo = NULL;
        }
        verticesPendentes->quantidade--;
        free(nohAtual);
    }

    // Libera a memória alocada
    destroyList(verticesPendentes);
    destroyList(verticesVisitados);
}

#endif