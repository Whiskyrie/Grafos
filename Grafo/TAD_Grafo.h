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
/*
int isSubGraph(pDGrafo, pDGrafo, FuncaoComparacao);

// Um grafo é conexo se existe pelo menos um caminho entre
// cada par de vértices do grafo. Caso contrário, o grafo é desconexo.
int isGraphConnected(pDGrafo, FuncaoComparacao);

// Um grafo é bipartido se seus vértices podem ser divididos
// em dois conjuntos independentes de tal forma que todas
// as arestas conectam vértices de conjuntos distintos.
int isGraphBipartite(pDGrafo, FuncaoComparacao);

int hasHamiltonianPath(pDGrafo, FuncaoComparacao);
int hasEulerianPath(pDGrafo, FuncaoComparacao);

// Uma coloração de um grafo é válida se as duas extremidades de cada aresta
// têm cores diferentes.
int colorGraph(pDGrafo);

// Um emparelhamento em um grafo não-dirigido G é um
// conjunto de arestas com a seguinte propriedade:
// cada vértice de G incide em no máximo uma aresta do emparelhamento.
// (Um laço não pode fazer parte de um emparelhamento porque incide
// duas vezes no mesmo vértice.)
pDLista matching(pDGrafo);

// ----------------------------------------------
// ----------------------------------------------
// ----------------------------------------------

// O conjunto de todos os vértices que têm algum vizinho na lista de vértices
pDLista neighborhood(pDGrafo, pDLista);

// O conjunto de todas as arestas que têm uma ponta em um vértice da lista de vértices
pDLista cutSet(pDGrafo, pDLista);

int areIsomorphic(pDGrafo, pDGrafo); // complexidade de ordem fatorial

int isGraphRegular(pDGrafo);

// Um conjunto de vértices de um grafo é estável se seus elementos são dois a dois
// não-adjacentes, ou seja, se nenhuma aresta tem ambas as pontas no conjunto.
pDLista stableSets(pDGrafo);

// Um conjunto estável X é maximal se não faz parte de um conjunto estável maior
pDLista maximalStableSet(pDGrafo);
pDLista maximumStableSets(pDGrafo);

// Uma clique em um grafo é qualquer conjunto de vértices dois a dois adjacentes
pDLista clique(pDGrafo);

// Uma cobertura de um grafo é qualquer conjunto de vértices que contenha
// pelo menos uma das pontas de cada aresta.
pDLista vertexCovers(pDGrafo);
*/
#endif
