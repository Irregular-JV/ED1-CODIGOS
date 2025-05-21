#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int verificaFormatoString(char *str, int n) {
    int i;
    Stack *stk;
    char *c;

    if(str != NULL) {
        stk = stkCreate(n);
        if (stk != NULL) {
            i = 0;
            while(i < n ) {
                if(str[i] != ')') {
                    c = malloc(sizeof(char));
                    if(c == NULL) {
                        stkDestroy(stk);
                        return 0;
                    }
                    *c = '(';
                    stkPush(stk, c);
                } else if(str[i] == ')'){
                    if(!stkIsEmpty(stk)) {
                        c = (char*) stkPop(stk);
                        free(c);
                    } else {
                        stkDestroy(stk);
                        return 0;
                    }
                }
                i++;
            }
            if(stkIsEmpty(stk)) {
                stkDestroy(stk);
                return 1;
            } else {
                while (!stkIsEmpty(stk)){
                    free(stkPop(stk));
                }
                stkDestroy(stk);
                return 0;
            }
        }
    }
    return 0;
}