#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int compareInt(void *info1, void *info2)
{
   int *p1 = (int *)info1;
   int *p2 = (int *)info2;
   return *p2 - *p1;
}

/* ---------------------------------------- */
void printInt(void *info)
{
   int *pi = (int *)info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void *allocateIntInfo(void *info)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = *((int *)info);
   return pi;
}
/* ---------------------------------------- */
int *allocateInt(int n)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = n;
   return pi;
}
/* ---------------------------------------- */
void *allocateInfoInt(void *info)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = *((int *)info);
   return pi;
}
/* ---------------------------------------- */
void freeInt(void *info)
{
   int *pi = (int *)info;
   free(pi);
}

/* ---------------------------------------- */
int mapInt(void *xxx)
{

   return *((int *)xxx);
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data
{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int compareDate(void *info1, void *info2)
{
   struct Data *p1 = (struct Data *)info1;
   struct Data *p2 = (struct Data *)info2;
   return ((p2->ano - p1->ano) * 365) +
          ((p2->mes - p1->mes) * 30) +
          (p2->dia - p1->dia);
}
/* ---------------------------------------- */
void printDate(void *info)
{
   struct Data *pd = (struct Data *)info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void *allocateDateInfo(void *info)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = ((struct Data *)info)->dia;
   pd->mes = ((struct Data *)info)->mes;
   pd->ano = ((struct Data *)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data *allocateDate(int dia, int mes, int ano)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}
/* ---------------------------------------- */
int compareVertex(void *info1, void *info2)
{

   pVertice v1 = (pVertice)info1;
   pVertice v2 = (pVertice)info2;

   int *id1 = (int *)v1->info;
   int *id2 = (int *)v2->info;

   return *id2 - *id1;
}

/* ----------------------------- */
void printAdjacency(void *info1)
{
   pVertice v = (pVertice)info1;
   printf("%d - ", *((int *)(v->info)));
}
/* ----------------------------- */
void printVertexWidth(void *info1)
{
   pVertice v = (pVertice)info1;
   printf("%d ", *((int *)v->info));
}
/* ----------------------------- */
void printVertex(void *info1)
{
   pVertice v = (pVertice)info1;
   printf("\nVertice %d - Adjacentes [", *((int *)v->info));

   printList(v->listaAdjacencias, printAdjacency);
   printf("]\n");
}

/* ----------------------------- */
void printVertexWithoutAdjacencies(void *info1)
{
   pVertice v = (pVertice)info1;
   printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void *allocateVertexInfo(void *info)
{
   pVertice pv = (pVertice)malloc(sizeof(Vertice));
   pv->info = allocateInfoInt(((pVertice)info)->info);
   return pv;
}

#endif /* UTILS_H */
