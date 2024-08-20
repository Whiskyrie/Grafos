#ifndef INCLUIR_VERTICE_H
#define INCLUIR_VERTICE_H

/* ----------------------- */
void addVertex(pDGrafo grafo, void *info, FuncaoComparacao fc)
{

   if (findVertex(grafo, info, fc) == NULL)
   {

      pVertice vertice = malloc(sizeof(Vertice));
      vertice->info = info;
      vertice->grau = 0;
      /* todo vertice ter� uma lista de adjacencia*/
      vertice->listaAdjacencias = createList();

      /* adiciona o novo vertice na lista de vertices
         do grafo */
      addInfo(grafo->listaVertices, vertice);
   }
}

#endif
