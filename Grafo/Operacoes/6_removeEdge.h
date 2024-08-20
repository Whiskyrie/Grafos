#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void removeEdge(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc)
{
    pVertice verticeOrigem = findVertex(grafo, vOrig, fc);
    pVertice verticeDestino = findVertex(grafo, vDest, fc);

    if (verticeOrigem == NULL || verticeDestino == NULL)
    {
        return; // Um ou ambos os vértices não existem no grafo
    }

    // Remove o vértice de destino da lista de adjacências do vértice de origem
    pNoh atual = verticeOrigem->listaAdjacencias->primeiro;
    pNoh anterior = NULL;

    while (atual != NULL)
    {
        if (fc(atual->info, verticeDestino) == 0)
        {
            if (anterior == NULL)
            {
                verticeOrigem->listaAdjacencias->primeiro = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            verticeOrigem->listaAdjacencias->quantidade--;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

#endif
