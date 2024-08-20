#ifndef INCLUIR_ARESTA_H
#define INCLUIR_ARESTA_H

/* --------------------------- */
void addEdge(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc)
{

   pVertice vOrigem = findVertex(grafo, vOrig, fc);
   pVertice vDestino = findVertex(grafo, vDest, fc);

   if (vOrigem == NULL || vDestino == NULL)
   {
      printf("Um dos vertices nao existe! \n");
      return;
   }
   addInfo(vOrigem->listaAdjacencias, vDestino);
}

#endif
