#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Utils.h"
#include "Grafo.h"
#include "../Lista/Lista.h"
#include "../Pilha/Pilha.h"
#include "../Pilha/Fila.h"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

pDGrafo ConstroiGrafo()
{
    pDGrafo grafo = createGraph();
    int num;

    do
    {
        limparTela();
        printf("Construcao do Grafo\n");
        printf("-------------------\n");
        displayGraph(grafo, printVertex);
        printf("\nDigite os valores para inserir no grafo como vertices (0 para sair): ");
        scanf("%d", &num);

        if (num != 0)
        {
            int *pv = (int *)malloc(sizeof(int));
            *pv = num;
            addVertex(grafo, pv, compareVertex);
        }
    } while (num != 0);

    return grafo;
}

void addArestas(pDGrafo grafo, int arestas[][2], int numArestas, FuncaoComparacao fc)
{
    for (int i = 0; i < numArestas; i++)
    {
        int vOrigem = arestas[i][0];
        int vDestino = arestas[i][1];
        addEdge(grafo, &vOrigem, &vDestino, fc);
    }
}

void exibirMenu()
{
    printf("Menu de Opcoes\n");
    printf("\n---------------\n");
    printf("0  - Construir grafo\n");
    printf("1  - Incluir Vertice\n");
    printf("2  - Incluir Aresta\n");
    printf("3  - Excluir Vertice\n");
    printf("4  - Excluir Aresta\n");
    printf("5  - Mostrar grafo\n");
    printf("6  - Busca em profundidade\n");
    printf("7  - Busca em amplitude\n");
    printf("8  - Existe caminho? (entre dois vertices)\n");
    printf("9  - Encontra caminho (entre dois vertices)\n");
    printf("10 - Verificar se o grafo e Hamiltoniano\n");
    printf("11 - Verificar se o grafo e Euleriano\n");
    printf("12 - Adicionar Multiplas arestas\n");
    printf("13 - Sair\n");
    printf("---------------\n");
    printf("\nEscolha uma opcao: ");
}

/* ----------------------------- */
int main()
{
    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = createGraph();

    do
    {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);

        limparTela();

        switch (opcao)
        {
        case 0:
            grafo = ConstroiGrafo();
            break;

        case 1:
            pv = (int *)malloc(sizeof(int));
            printf("ID do vertice: ");
            scanf("%d", pv);
            addVertex(grafo, pv, compareVertex);
            printf("Vertice adicionado.\nGrafo atualizado:\n");
            displayGraph(grafo, printVertex);
            break;

        case 2:
            printf("ID do vertice origem: ");
            scanf("%d", &vOrigem);
            printf("ID do vertice destino: ");
            scanf("%d", &vDestino);
            addEdge(grafo, &vOrigem, &vDestino, compareVertex);
            printf("Aresta adicionada. Grafo atualizado:\n");
            displayGraph(grafo, printVertex);
            break;

        case 3:
            printf("ID do vertice a ser removido: ");
            scanf("%d", &vOrigem);
            removeVertex(grafo, &vOrigem, compareVertex);
            printf("Vertice removido. Grafo atualizado:\n");
            displayGraph(grafo, printVertex);
            break;

        case 4:
            printf("ID do vertice origem: ");
            scanf("%d", &vOrigem);
            printf("ID do vertice destino: ");
            scanf("%d", &vDestino);
            removeEdge(grafo, &vOrigem, &vDestino, compareVertex);
            printf("Aresta removida. Grafo atualizado:\n");
            displayGraph(grafo, printVertex);
            break;

        case 5:
            printf("Grafo atual:\n");
            displayGraph(grafo, printVertex);
            break;

        case 6:
            printf("Busca em profundidade:\n");
            depthSearch(grafo, compareVertex, printVertexWithoutAdjacencies);
            break;

        case 7:
            printf("Busca em amplitude:\n");
            breadthSearch(grafo, compareVertex, printVertexWidth);
            break;

        case 8:
            printf("ID do vertice origem: ");
            scanf("%d", &vOrigem);
            printf("ID do vertice destino: ");
            scanf("%d", &vDestino);

            int result = pathExists(grafo, &vOrigem, &vDestino, compareVertex);
            if (result != 0)
                printf("Existe caminho entre %d e %d!\n", vOrigem, vDestino);
            else
                printf("Nao existe caminho entre %d e %d.\n", vOrigem, vDestino);
            break;

        case 9:
            printf("ID do vertice origem: ");
            scanf("%d", &vOrigem);
            printf("ID do vertice destino: ");
            scanf("%d", &vDestino);

            pDLista caminho = getPath(grafo, &vOrigem, &vDestino, compareVertex, allocateVertexInfo);
            if (caminho->quantidade > 0)
            {
                printf("Existe um caminho entre %d e %d:\n", vOrigem, vDestino);
                printList(caminho, printVertexWithoutAdjacencies);
            }
            else
                printf("Nao existe um caminho entre %d e %d.\n", vOrigem, vDestino);
            break;

        case 10:
            printf("Verificando se o grafo e Hamiltoniano...\n");
            if (isHamiltonian(grafo, compareVertex))
            {
                printf("O grafo e Hamiltoniano!\n");
            }
            else
            {
                printf("O grafo nao e Hamiltoniano.\n");
            }
            break;

        case 11:
            printf("Verificando se o grafo e Euleriano...\n");
            if (isEulerian(grafo))
            {
                printf("O grafo e Euleriano!\n");
            }
            else
            {
                printf("O grafo nao e Euleriano.\n");
            }
            break;
        case 12:
        {
            int numArestas;
            printf("Quantas arestas deseja adicionar? ");
            scanf("%d", &numArestas);

            int(*arestas)[2] = malloc(numArestas * sizeof(*arestas));

            for (int i = 0; i < numArestas; i++)
            {
                printf("Aresta %d:\n", i + 1);
                printf("  Vertice origem: ");
                scanf("%d", &arestas[i][0]);
                printf("  Vertice destino: ");
                scanf("%d", &arestas[i][1]);
            }

            addArestas(grafo, arestas, numArestas, compareVertex);

            free(arestas);

            printf("Arestas adicionadas. Grafo atualizado:\n");
            displayGraph(grafo, printVertex);
        }
        break;
        }

        if (opcao != 13)
        {
            printf("\nPressione qualquer tecla para continuar...");
            getch();
        }

    } while (opcao != 13);

    printf("Programa encerrado.\n");
    return 0;
}