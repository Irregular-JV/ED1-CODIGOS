#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#define TRUE 1
#define FALSE 0



int VerificaNumASeguidoB(char *str, int len) {
    Stack *stk;
    int i;
    if (str != NULL && len > 0) {
        stk = stkCreate(len);
        if(stk != NULL){
            i = 0;
            while (i < len && str[i] == 'A'){
                stkPush(stk, (void*) &str[i]);
                i++;
            }

            while(i < len && str[i] == 'B') {
                if (stkIsEmpty(stk)) {
                   stkDestroy(stk);
                   return FALSE;
                }
                stkPop(stk);
                i++;
            }
            if(i == len && stkIsEmpty(stk)) {
                stkDestroy(stk);
                return TRUE;
            }
            stkDestroy(stk);
        }
    }
    return FALSE;
}


int main() {
    char *testes[] = {
        "AAABBB",   // válido
        "AABB",     // válido
        "AAABB",    // inválido
        "ABBB",     // inválido
        "AAA",      // inválido
        "BBB",      // inválido
        "",         // inválido (string vazia)
        "AB",       // válido
        "AABBBB",   // inválido
        "AAAAABBBBB"// válido
    };

    int total_testes = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < total_testes; i++) {
        char *str = testes[i];
        int len = strlen(str);

        int resultado = VerificaNumASeguidoB(str, len);

        printf("Teste %d: \"%s\" => %s\n", i + 1, str, resultado == TRUE ? "VÁLIDO" : "INVÁLIDO");
    }
    return 0;
}