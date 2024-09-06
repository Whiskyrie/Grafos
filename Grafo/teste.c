#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Utils.h"
#include "Grafo.h"
#include "../Lista/Lista.h"
#include "../Pilha/Pilha.h"
#include "../Pilha/Fila.h"

int main()
{
    pDGrafo grafo = createGraph();

    // Criar vértices
    for (int i = 1; i <= 5; i++)
    {
        int *pv = (int *)malloc(sizeof(int));
        *pv = i;
        addVertex(grafo, pv, compareVertex);
    }

    // Adicionar arestas para formar um grafo hamiltoniano
    int arestas[][2] = {{1, 2}, {1, 3}, {1, 5}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};
    int numArestas = sizeof(arestas) / sizeof(arestas[0]);

    for (int i = 0; i < numArestas; i++)
    {
        addEdge(grafo, &arestas[i][0], &arestas[i][1], compareVertex);
    }

    printf("Grafo criado:\n");
    displayGraph(grafo, printVertex);

    printf("\nVerificando se o grafo e Hamiltoniano...\n");
    if (isHamiltonian(grafo, compareVertex))
    {
        printf("O grafo e Hamiltoniano!\n");
    }
    else
    {
        printf("O grafo nao e Hamiltoniano.\n");
    }

    return 0;
}