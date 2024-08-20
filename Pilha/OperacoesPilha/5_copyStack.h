#ifndef COPY_STACK_H
#define COPY_STACK_H

pDPilha copyStack(pDPilha pd, FuncaoAlocacao pfa)
{
    pDPilha pDCopia = createStack();
    pDPilha pDAux = createStack();

    int count = 0;
    void *info;
    void *infoCopia;

    while (isStackEmpty(pd) == 0)
    {
        pushInfo(pDAux, popInfo(pd));
        count++;
    }
    count = 0;
    while (isStackEmpty(pDAux) == 0)
    {
        info = popInfo(pDAux);
        infoCopia = pfa(info);
        pushInfo(pd, info);
        pushInfo(pDCopia, infoCopia);
        count++;
    }
    return pDCopia;
}

#endif