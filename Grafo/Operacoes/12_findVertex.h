#ifndef BUSCAR_VERTICE_H
#define BUSCAR_VERTICE_H

pVertice findVertex(pDGrafo grafo, void *idVertice, FuncaoComparacao fc)
{

    Vertice v;
    v.info = idVertice;
    return searchNodeInfo(grafo->listaVertices, &v, fc);
};

#endif
