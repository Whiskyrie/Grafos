#ifndef MOSTRA_GRAFO_H
#define MOSTRA_GRAFO_H

/* --------------------------- */
void displayGraph(pDGrafo grafo, FuncaoImpressao fi)
{

     printList(grafo->listaVertices, fi);
}
#endif
