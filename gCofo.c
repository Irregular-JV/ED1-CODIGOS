#define _GCOFO_C_
#include "gCofo.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

gCofo *gcofCreate(int max_itens)
{
    gCofo *gc;

    if(max_itens > 0) {
        gc = (gCofo*) malloc(sizeof(gCofo));
        if(gc != NULL) {
            gc -> item= (void**) malloc(sizeof(void*) * max_itens);
            if(gc -> item != NULL) {
                gc -> numItens = 0;
                gc -> maxItens = max_itens;
                gc -> cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}


int gcofDestroy(gCofo *gc) 
{
    if (gc != NULL) {
        if(gc -> numItens == 0) {
            free(gc -> item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}


int gcofInsert(gCofo *gc, void *item)
{
    if(gc != NULL) {
        if(gc -> numItens < gc -> maxItens) {
            gc -> item[gc -> numItens] = item;
            gc -> numItens++;
            return TRUE;
        }
    }
    return FALSE;
}


void *gcofGetFirst(gCofo *gc) 
{
    if(gc != NULL) {
        if(gc -> numItens > 0) {
            gc -> cur = 0;
            return gc -> item[gc -> cur];
        }
    }
    return NULL;
}

void *gcofGetNext(gCofo *gc)
{
    if(gc != NULL) {
        if(gc -> cur < gc -> numItens - 1) {
            gc -> cur++;
            return gc -> item[gc -> cur];
        }
    }
    return NULL;
}


void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *, void *)) {
    void *data;
    int i, j, stat;

    if (gc != NULL) {
        if (gc->numItens > 0) {
            i = 0;
            stat = cmp(key, gc->item[i]);

            while (i < gc->numItens && stat != TRUE) {
                i++;
                if (i < gc->numItens) {
                    stat = cmp(key, gc->item[i]);
                }
            }

            if (stat == TRUE) {
                data = gc->item[i];

                // Desloca os itens seguintes para a esquerda
                for (j = i; j < gc->numItens - 1; j++) {
                    gc->item[j] = gc->item[j + 1];
                }

                gc->numItens--; // Decrementa o número de itens
                return data;
            }
        }
    }

    return NULL;
}



void *gcofQuery (gCofo *gc, void *key, int (*cmp) (void *, void*)) {
    void * data; int i, stat;
    if (gc != NULL) {
        if(gc -> numItens > 0) {
            i = 0; stat = cmp(key, gc -> item[i]);
            while (i < gc -> numItens && stat != TRUE)
            {
                i++;
                stat = cmp(key, gc -> item[i]);
            }

            if (stat == TRUE) {
                data = gc -> item[i];
                return data;
            }
            
        }
    }
    return NULL;
}