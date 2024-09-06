#ifndef IS_HAMILTONIAN_H
#define IS_HAMILTONIAN_H

int canAddToPath(pVertice v, pDLista path, int pos, FuncaoComparacao fc)
{
    printf("Verificando se pode adicionar vertice %d na posicao %d\n", *(int *)v->info, pos);

    // Verifica se o vértice já está no caminho
    if (containsInfo(path, v, fc) > 0) // Corrigido: Verificando se o vértice está no caminho
    {
        printf("Vertice %d ja esta no caminho\n", *(int *)v->info);
        return 0;
    }

    // Se não é o primeiro vértice, verifica se há uma aresta com o vértice anterior
    if (pos > 0)
    {
        pVertice lastVertex = searchInfoPosition(path, pos); // Corrigido: Posição ajustada
        if (!containsInfo(lastVertex->listaAdjacencias, v, fc))
        {
            printf("Nao ha aresta entre %d e %d\n", *(int *)lastVertex->info, *(int *)v->info);
            return 0;
        }
    }

    printf("Pode adicionar vertice %d na posicao %d\n", *(int *)v->info, pos);
    return 1;
}

int hamiltonianPathUtil(pDGrafo grafo, pDLista path, int pos, FuncaoComparacao fc)
{
    printf("Entrando em hamiltonianPathUtil, pos = %d\n", pos);

    // Se todos os vértices estão incluídos no caminho
    if (pos == grafo->listaVertices->quantidade)
    {
        printf("Caminho Hamiltoniano encontrado!\n");
        return 1;
    }

    // Tenta diferentes vértices como próximo candidato no caminho
    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL)
    {
        pVertice v = atual->info;
        printf("Tentando adicionar vertice %d\n", *(int *)v->info);

        if (canAddToPath(v, path, pos, fc))
        {
            addInfo(path, v);
            printf("Adicionado vertice %d ao caminho\n", *(int *)v->info);

            if (hamiltonianPathUtil(grafo, path, pos + 1, fc) == 1)
                return 1;

            // Se adicionar v não leva a uma solução, remove-o
            removeInfoPos(path, pos); // Corrigido: Remover na posição correta
            printf("Removido vertice %d do caminho\n", *(int *)v->info);
        }

        atual = atual->prox;
    }

    printf("Nenhum caminho Hamiltoniano encontrado a partir da posicao %d\n", pos);
    return 0;
}

int isHamiltonian(pDGrafo grafo, FuncaoComparacao fc)
{
    printf("Iniciando verificacao de grafo Hamiltoniano\n");

    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0)
    {
        printf("Grafo vazio ou invalido\n");
        return 0; // Grafo vazio não é hamiltoniano
    }

    if (grafo->listaVertices->quantidade == 1)
    {
        printf("Grafo com apenas um vertice e trivialmente Hamiltoniano\n");
        return 1; // Grafo com um vértice é trivialmente hamiltoniano
    }

    pDLista path = createList();
    pNoh primeiroVertice = grafo->listaVertices->primeiro;
    addInfo(path, primeiroVertice->info);
    printf("Comecando com o vertice %d\n", *(int *)primeiroVertice->info);

    int result = hamiltonianPathUtil(grafo, path, 1, fc);

    destroyListInfo(path, NULL);

    printf("Resultado final: %d\n", result);
    return result;
}

#endif // IS_HAMILTONIAN_H
