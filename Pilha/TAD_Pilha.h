#ifndef PILHA_TAD_H
#define PILHA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da pilha */
typedef struct dPilha DPilha;
typedef DPilha *pDPilha;
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void (*FuncaoImpressaoDupla)(void *, void *);
typedef void *(*FuncaoAlocacao)(void *);
typedef void (*FuncaoLiberacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPilha createStack();
void pushInfo(pDPilha pdPilha, void *info);
void *popInfo(pDPilha pdPilha);
int isStackEmpty(pDPilha pdPilha);
pDPilha copyStack(pDPilha pd, FuncaoAlocacao pfa);

#endif
