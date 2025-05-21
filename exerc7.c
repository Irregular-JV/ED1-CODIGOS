#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int VerificaFormatoString(char *str, int n) {
    Stack *stk; // Armazena a outra metade
    char *top;
    int i;

    if(str != NULL && n > 0) {
        stk = stkCreate(n);
        if (stk != NULL) {
            i = 0;
            while(i < n && str[i] != 'C') {
                stkPush(stk, (void*) &str[i]);
                i++;
            }

            if(i == 0 || i == n-1 || str[i] != 'C') {
                stkDestroy(stk);
                return 0;
            }

            i++; // Saio do ponto 'C'
            
            //Vou verificar caractere com caractere da pilha
            while(i < n ) {
                top = (char*) stkPop(stk);
                if (top == NULL || str[i] != *top) {
                    stkDestroy(stk);
                    return 0;
                }
                i++;
            }

            if(!stkIsEmpty(stk)){
                stkDestroy(stk);
                return 0;
            }

            stkDestroy(stk);
            return 1;
        }
    }
    return 0;

}



int main() {
    char *ex1 = "ABBACABBA";  // válido
    char *ex2 = "ABACAB";     // inválido
    char *ex3 = "ABABACABABA"; // válido
    char *ex4 = "ACB";        // inválido (faltam elementos)

    printf("Teste 1: %d\n", VerificaFormatoString(ex1, 9));
    printf("Teste 2: %d\n", VerificaFormatoString(ex2, 6));
    printf("Teste 3: %d\n", VerificaFormatoString(ex3, 11));
    printf("Teste 4: %d\n", VerificaFormatoString(ex4, 3));

    return 0;
}