#ifndef IS_EULERIAN_H
#define IS_EULERIAN_H

int isEulerian(pDGrafo grafo)
{
    // Um grafo é euleriano se todos os vértices têm grau par
    pDLista vertices = grafo->listaVertices;
    pNoh atual = vertices->primeiro;

    while (atual != NULL)
    {
        pVertice v = atual->info;
        pDLista adjacents = v->listaAdjacencias;

        if (adjacents->quantidade % 2 != 0)
        {
            return 0; // Se algum vértice tem grau ímpar, o grafo não é euleriano
        }

        atual = atual->prox;
    }

    return 1; // Todos os vértices têm grau par
}

#endif // IS_EULERIAN_H