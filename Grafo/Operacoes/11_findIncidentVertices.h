#ifndef BUSCAR_VERTICES_INCIDENTES_H
#define BUSCAR_VERTICES_INCIDENTES_H

/* --------------------------- */
pDLista findIncidentVertices(pDGrafo grafo, pVertice vDest, FuncaoComparacao fc)
{

   pDLista verticesIncidentes = createList();

   pNoh atual = grafo->listaVertices->primeiro;
   while (atual != NULL)
   {
      pVertice vAtual = (pVertice)atual->info;
      if (containsInfo(vAtual->listaAdjacencias, vDest, fc) != 0)
         addInfo(verticesIncidentes, vAtual);

      atual = atual->prox;
   }

   return verticesIncidentes;
}
#endif
