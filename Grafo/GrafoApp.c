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
    printf("10 - Sair\n");
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
        }

        if (opcao != 10)
        {
            printf("\nPressione qualquer tecla para continuar...");
            getch();
        }

    } while (opcao != 10);

    printf("Programa encerrado.\n");
    return 0;
}