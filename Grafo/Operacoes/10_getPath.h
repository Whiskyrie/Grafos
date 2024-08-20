#ifndef GET_CAMINHO_H
#define GET_CAMINHO_H

/* --------------------------- */
pDLista getPathRecursive(pDGrafo grafo, pVertice vOrig, pVertice vDest, pDLista caminhoParcial, FuncaoComparacao fc, FuncaoAlocacao fa)
{

   if (fc(vOrig, vDest) == 0)
   {
      return caminhoParcial;
   }

   pDLista verticesIncidentes = findIncidentVertices(grafo, vDest, fc);

   if (verticesIncidentes->quantidade == 0)
      return NULL;

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade)
   {

      pVertice verticeIncidente = (pVertice)searchInfoPosition(verticesIncidentes, cont);
      cont++;

      pDLista caminhoIncrementado = duplicateList(caminhoParcial, fa);
      addInfo(caminhoIncrementado, verticeIncidente);
      if (getPathRecursive(grafo, vOrig, verticeIncidente, caminhoIncrementado, fc, fa) != NULL)
      {
         flag = 1;
         break;
      }
   }

   if (flag == 0)
   {
      return NULL;
   }
   return caminhoParcial;
}

/* --------------------------- */
pDLista getPath(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc, FuncaoAlocacao fa)
{

   pVertice vOrigem = findVertex(grafo, idOrig, fc);
   pVertice vDestino = findVertex(grafo, idDest, fc);

   if (vOrigem == NULL || vDestino == NULL)
   {
      return 0;
   }

   pDLista caminhoParcial = createList();
   addInfo(caminhoParcial, vDestino);
   return getPathRecursive(grafo, vOrigem, vDestino, caminhoParcial, fc, fa);
}
#endif
