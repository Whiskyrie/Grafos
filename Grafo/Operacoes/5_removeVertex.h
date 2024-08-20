#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void removeVertex(pDGrafo grafo, void *info, FuncaoComparacao fc)
{
    pVertice verticeRemover = findVertex(grafo, info, fc);

    if (verticeRemover == NULL)
    {
        return; // O vértice não existe no grafo
    }

    // Remove todas as arestas que apontam para este vértice
    pNoh atualVertice = grafo->listaVertices->primeiro;
    while (atualVertice != NULL)
    {
        pVertice v = (pVertice)atualVertice->info;
        removeEdge(grafo, v, verticeRemover, fc);
        atualVertice = atualVertice->prox;
    }

    // Remove o vértice da lista de vértices do grafo
    atualVertice = grafo->listaVertices->primeiro;
    pNoh anteriorVertice = NULL;

    while (atualVertice != NULL)
    {
        if (fc(atualVertice->info, verticeRemover) == 0)
        {
            if (anteriorVertice == NULL)
            {
                grafo->listaVertices->primeiro = atualVertice->prox;
            }
            else
            {
                anteriorVertice->prox = atualVertice->prox;
            }
            free(atualVertice);
            grafo->listaVertices->quantidade--;
            break;
        }
        anteriorVertice = atualVertice;
        atualVertice = atualVertice->prox;
    }

    // Libera a memória alocada para o vértice e sua lista de adjacências
    free(verticeRemover->listaAdjacencias);
    free(verticeRemover);
}
#endif
