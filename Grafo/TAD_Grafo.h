#ifndef GRAFO_TAD_H
#define GRAFO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct vertice Vertice;
typedef Vertice *pVertice;

typedef struct dGrafo DGrafo;
typedef DGrafo *pDGrafo;

/* tipos referentes aos ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void *(*FuncaoAlocacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDGrafo createGraph();

void addVertex(pDGrafo grafo, void *info, FuncaoComparacao fc);

void addEdge(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc);

void removeVertex(pDGrafo, void *, FuncaoComparacao);

void removeEdge(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc);

void displayGraph(pDGrafo grafo, FuncaoImpressao fi);

pVertice findVertex(pDGrafo grafo, void *idVertice, FuncaoComparacao fc);

pDLista findIncidentVertices(pDGrafo grafo, pVertice vDest, FuncaoComparacao fc);

void depthSearch(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi);

void breadthSearch(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi);

int pathExists(pDGrafo, void *, void *, FuncaoComparacao);

pDLista getPath(pDGrafo, void *, void *, FuncaoComparacao, FuncaoAlocacao);

pDLista findIncidentVertices(pDGrafo grafo, pVertice vDest, FuncaoComparacao fc);

pVertice findVertex(pDGrafo grafo, void *idVertice, FuncaoComparacao fc);

int isHamiltonian(pDGrafo grafo, FuncaoComparacao fc);

int isEulerian(pDGrafo grafo);

#endif
