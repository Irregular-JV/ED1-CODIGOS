#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"
#define _CQUEUE_C



typedef struct _queue_ CQueue;

CQueue *cqCreate(int max) {
    if(max > 0) {
        CQueue *q = (CQueue *) malloc (sizeof(CQueue));
        if(q != NULL) {
            q -> elms = (void**) malloc(sizeof(void*) *max);
            if(q -> elms != NULL) {
                q-> front = 0;
                q -> rear = -1;
                q -> maxItens = max;
                q-> numItens = 0;
                return q;
            }
        }
    }
    return NULL;
}

int cqDestroy(CQueue *cq) {
    if(cq != NULL) {
        if(cq -> numItens ==0) {
            free(cq -> elms);
            free(cq);
            return TRUE;
        }
    }
    return FALSE;
}
int cqIncCirc(int i, int max) {
    if ( i == max -1) {
        return 0;
    } else {
        return i + 1;
    }
}

int cqDeCirc(int i, int max) {
    if ( i == 0) {
        return max -1;
    } else {
        return i - 1;
    }
}



int cqEnqueue(CQueue *cq, void *data) {
    if(cq != NULL) {
        if(cq -> numItens < cq -> maxItens) {
            cq -> rear = cqIncCirc(cq -> rear, cq -> maxItens);
            cq -> elms[cq -> rear] = data;
            cq -> numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *cqDequeue(CQueue *cq) {
    void *aux;
    if(cq != NULL) {
        if(cq -> numItens > 0) {
            aux = cq -> elms[cq -> front];
            cq -> front = cqIncCirc(cq -> front, cq -> maxItens);
            cq -> numItens--;
            return aux;
        }
    }
    return NULL;
}

//Acessa o elemento do inicio da fila
void *cqFirst (CQueue *cq ) {
    void *data;
    if(cq != NULL) {
        if(cq -> numItens > 0) {
            data = cq -> elms[cq -> front];
            return data;
        }
    }
    return NULL;
}


//Começa os exercícios
void *cqGetLast(CQueue *cq) {
    // int ultimaPos;
    if (cq != NULL) {
        if (cq -> numItens > 0) {
            // ultimaPos = cqDeCirc(cq->rear, cq -> maxItens);
            return cq -> elms[cq -> rear];
        }
    }
    return NULL;
}

//Recebe um vetor com n elementos e os coloca na fila
int cqEnqueueN(CQueue *cq, int n, void **elms) {
    int cont = 0, i;
    if(cq != NULL) {
        if(elms != NULL && n > 0) {
        for(i = 0; i < n; i++) {
            if (cqEnqueue(cq, elms[i]))
                cont++;
            }
        }
    }
    return cont;
} 

//Retorna um vetor com os n primeiros elementos da fila
void *cqDequeueN(CQueue *q, int n) {
    void **vet;
    int i;
    if (q != NULL) {
        if (n > 0) {
            vet = (void **) malloc(sizeof(void *) * n);
            if (vet != NULL) {
                for(i = 0; i < n; i++) {
                    vet[i] =cqDequeue(q);
                }
                return (void*) vet;
            }
        }
    }
    return NULL;
}

void *cqDequeueSpecified(CQueue *q, void *key, int (*cmp(void *, void *))) {
    //Quarda um item;
    void *data;
    int i, idx, stat;
    if (q != NULL) {
        if (key != NULL && q -> numItens > 0 ) {
            idx = q -> front;
            stat = FALSE;
            i = 0;
            while ( i < q -> numItens && !stat){
                if(cmp(key, q -> elms[idx])) {
                    stat = TRUE;  
                } else {
                    idx = cqIncCirc(idx, q -> maxItens);
                }
                i++;
            }

        }
        
        if(stat) {
            data = q -> elms[idx];
            while (idx != q -> rear){
                int next = cqIncCirc(idx, q-> maxItens);
                q-> elms[idx] = q-> elms[next];
                idx = next;
            }
            q -> rear = cqDeCirc(q -> rear, q-> maxItens);
            q -> numItens--;
            return data;
        }

    }
    return NULL;
}















