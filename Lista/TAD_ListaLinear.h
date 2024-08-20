#ifndef LISTA_TAD_H
#define LISTA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh Noh;
typedef Noh *pNoh;

/* descritor da lista */
typedef struct dLista DLista;
typedef DLista *pDLista;

/* 3 tipos que representam ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void (*FuncaoImpressaoDupla)(void *, void *);
typedef void *(*FuncaoAlocacao)(void *);
typedef void (*FuncaoLiberacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista createList();

void addInfo(pDLista pd, void *info);

void addInfoAtBeginning(pDLista pd, void *info);

void addInfoInMiddle(pDLista pd, void *info, int pos);

void addInfoOrdered(pDLista pd, void *info, FuncaoComparacao pfc);

int removeInfo(pDLista pd, void *info, FuncaoComparacao pfc);

void *removeInfoPos(pDLista pd, int pos);

int containsInfo(pDLista pd, void *info, FuncaoComparacao pfc);

void printList(pDLista pd, FuncaoImpressao pfi);

void destroyListRecursive(pNoh atual);

void destroyListInfo(pDLista pd, FuncaoLiberacao fl);

pDLista duplicateList(pDLista pd, FuncaoAlocacao fa);

pDLista splitList(pDLista pListaOriginal, int pos);

pDLista mergeLists(pDLista lista1, pDLista lista2, FuncaoComparacao fc);

void reverseList(pDLista pd);

void *searchNodeInfo(pDLista lista, void *info, FuncaoComparacao fc);

void *searchInfoPosition(pDLista lista, int pos);

#endif
