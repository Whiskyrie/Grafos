#ifndef CRIAR_GRAFO_H
#define CRIAR_GRAFO_H

/* --------------------------- */
pDGrafo createGraph()
{

  pDGrafo grafo = malloc(sizeof(DGrafo));
  grafo->listaVertices = createList(); // Cria a lista de vertices
  return grafo;
}

#endif
