#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int InverteString(char *str, int n) {
    Stack *stk;
    int i, j, cont; char *strTemp;
    if(str != NULL && n > 0) {
        stk = stkCreat(n);
        if(stk != NULL) {
            strTemp = (char*) malloc(sizeof(char) * n+1);
            if (strTemp == NULL)  {
                stkDestroy(stk);
                return 0;
            }

            i = 0; cont = 0; j = 0;
            while(i <= n) {
                if(str[i] == ' ' || i == n) {
                    while(cont > 0) {
                        strTemp[j] = *(char *)stkPop(stk);
                        cont--;
                        j++;
                    }
                    if(i < n) {
                        strTemp[j] = ' ';
                        j++;
                    }
                } else {
                    stkPush(stk, (void*) &str[i]);
                    cont++;
                }
                i++;
            }
            strTemp[j] = '\0';

            for(i = 0; i <= n; i++) {
                str[i] = strTemp[i];
            }
            free(strTemp);
            stkDestroy(stk);
            return 1;
        }
    }
    return 0;
}