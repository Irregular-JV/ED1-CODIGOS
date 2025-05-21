#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



char* inverteCaractere(char *caracteres, int tam){
    Stack *stk;
    int i = 0;
    char *invertida;
    if (caracteres != NULL && tam > 0) {
        stk = stkCreate(tam);
        if(stk != NULL) {
            for(i = 0; i < tam; i++) {
               stkPush(stk, (void*) &(caracteres[i]));
            }
        }
        
        
        invertida = (char *) malloc(sizeof(char) * (tam +1));
        if(invertida != NULL) {
            for(i = 0; i < tam; i++) {
                char *p = (char*) stkPop(stk);
                if (p != NULL) {
                    invertida[i] = *p;
                }
            }
            invertida[tam] = '\0';
        }
        stkDestroy(stk);

    }
    return invertida;
}

int main() {
    char *c;
    c = (char*) malloc(sizeof(char) * 10);
    scanf("%s", c);
    printf("%s", inverteCaractere(c, 10));
    return 0;
}