#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int stkPushElmAsNRemove(Stack *st, void *elm, int n){
    void *temp;
    int i;
    if(st != NULL && elm != NULL) {
        if (n > 0) {
            for(i = 1; i <= n; i++) {
                if(stkIsEmpty(st)) {
                    return 0; // Não tem elementos suficientes
                }

                temp = stkPop(st);
                if(temp == NULL) return 0; // algo deu errado

                if(i == n) {
                    *(void**)elm = temp;
                }
            }
            return 1;
        }
    }
    return 0;
}

int stkPushElMasNaoRemove(Stack *st, void* elm, int n) {
    int i;
    Stack *temp;

    if (st != NULL && elm != NULL) {
        if (n > 0) {
            temp = stkCreate(n + 1);
            if(temp != NULL) {
                for ( i = 0; i < n; i++) {
                    if(stkIsEmpty(st)){
                        while (!stkIsEmpty(temp)) stkPush(st, stkPop(temp));
                        stkDestroy(temp);
                        return 0;
                    } // Não tem elementos suficientes

                    stkPush(temp, stkPop(st));
                }
                // Insere o novo elemento na posição n
                stkPush(st, elm);

                //Recoloca os elementos retirados
                while(!stkIsEmpty(temp)) {
                    stkPush(st, stkPop(temp));
                }

                stkDestroy(temp);
                return 1;
            }
        }      
    }
    return 0;
}


int stkPushElmAsUltimo(Stack *st, void *elm, int n){
    Stack *temp;
    if(st != NULL && elm != NULL) {
        if (n > 0) {
            if(!stkIsEmpty(st)) {
                temp = stkCreate(st -> maxItens);
                if(temp == NULL) return 0;
                while(!stkIsEmpty(st)) {
                    stkPush(temp, stkPop(st));
                }

                stkPush(st, elm);
                while(!stkIsEmpty(temp)) {
                    stkPush(st, stkPop(temp));
                }

                stkDestroy(temp);
                return 1;
            }    
        }
    }
    return 0;
}



