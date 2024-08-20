#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H

int pathExistsRecursive(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc)
{

   if (fc(vOrig, vDest) == 0)
   {
      return 1;
   }

   pDLista verticesIncidentes = findIncidentVertices(grafo, vDest, fc);

   if (verticesIncidentes->quantidade == 0)
   {
      return 0;
   }

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade)
   {

      pVertice verticeIncidente = (pVertice)searchInfoPosition(verticesIncidentes, cont);
      cont++;

      if (pathExistsRecursive(grafo, vOrig, verticeIncidente, fc) != 0)
      {
         flag = 1;
         break;
      }
   }

   return flag;
}

int pathExists(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc)
{

   pVertice vOrigem = findVertex(grafo, idOrig, fc);
   pVertice vDestino = findVertex(grafo, idDest, fc);

   if (vOrigem == NULL || vDestino == NULL)
   {
      return 0;
   }
   return pathExistsRecursive(grafo, vOrigem, vDestino, fc);
}
#endif
