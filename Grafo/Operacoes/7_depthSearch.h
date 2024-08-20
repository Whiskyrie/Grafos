#ifndef BUSCA_PROFUNDIDADE_H
#define BUSCA_PROFUNDIDADE_H

/* --------------------------- */
void depthSearch(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi)
{

   pDPilha verticesPendentes;
   pDLista verticesVisitados;

   verticesPendentes = createStack();
   verticesVisitados = createList();

   /* empilha o primeiro v�rtice do grafo (ou seja, o primeiro v�rtice da lista) */
   pushInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

   /* processa todos os v�rtices da pilha */
   while (isStackEmpty(verticesPendentes) != 0)
   {
      pVertice vAtual = popInfo(verticesPendentes);

      /* visita o vertice se ainda n�o foi visitado */
      if (containsInfo(verticesVisitados, vAtual, fc) == 0)
      {
         fi(vAtual);
         addInfo(verticesVisitados, vAtual);
      }

      /* empilha todas as adjac�ncias do v�rtice atual que n�o foram visitadas */
      pNoh atual = vAtual->listaAdjacencias->primeiro;
      while (atual != NULL)
      {
         if (containsInfo(verticesVisitados, atual->info, fc) == 0)
         {
            pushInfo(verticesPendentes, atual->info);
         }
         atual = atual->prox;
      }
   }
}

#endif
