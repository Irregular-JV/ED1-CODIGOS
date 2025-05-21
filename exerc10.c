#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

 int cqReorganizaFila( CQueue *cq) {
    int cap, p, prev;
    void *temp;
    if(cq != NULL) {
        if(cq -> numItens > 0) {
            cap = cq -> maxItens;

            while(cq -> front != 0) {
                p = cq ->front;
                prev = cqDeCirc(p, cap);

                temp = cq -> elms[p];
                cq -> elms[p] = cq -> elms[prev];
                cq -> elms[prev] = temp;

                cq -> front = prev;
                cq -> rear = cqDeCirc(cq -> rear,cap);
            }
           return TRUE;
        }
    }
    return FALSE;
 }