#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 100

typedef struct{
    int dados[MAX];
    int topA;
    int topoB;

} PilhasDuplas;

//Vamos criar as pilhas
void criarPilhas(PilhasDuplas *p) {
    p ->topA = -1;
    p->topoB = MAX;
}

//Vamos verificar se a pilha A está vazia
int vaziaA(PilhasDuplas *p) {
    return (p ->topA == -1);
}

int vaziaB(PilhasDuplas *p) {
    return (p ->topA == MAX);
}

//Verificar se ambas estão cheias (colidiram), eles estariam no meio
int pilhasCheias(PilhasDuplas *p) {
    return (p -> topA + 1 == p-> topoB);
}

//Empilha A
int empilhaA(PilhasDuplas *p, int valor) {
    if(!pilhasCheias(p)) {
        p -> topA++;
        p -> dados[p -> topA] = valor;
        return 1;
    }
    return 0;
}

// Empilha b
int empilhaB(PilhasDuplas *p, int valor) {
    if(!pilhasCheias(p)) {
        p ->topoB --;
        p ->dados[p->topoB] = valor;
        return 1;
    }
    return 0;
}


int desempilhaA(PilhasDuplas *p, int *valor) {
    if(!vaziaA(p)) {
        *valor = p-> dados[p->topA];
        p-> topA--;
        return 1;
    }
    return 0;
}
 
int desempilhaB(PilhasDuplas *p, int *valor) {
    if(!vaziaB(p)) {
        *valor = p->dados[p->topoB];
        p-> topoB++;
        return 1;
    }
    return 0;
}





int main() {
    PilhasDuplas p;
    int x;

    criarPilhas(&p);

    empilhaA(&p, 10);
    empilhaA(&p, 20);
    empilhaB(&p, 99);
    empilhaB(&p, 88);

    desempilhaA(&p, &x);
    printf("Desempilhou A: %d\n", x);

    desempilhaA(&p, &x);
    printf("Desempilhou A: %d\n", x);

    desempilhaB(&p, &x);
    printf("Desempilhou B: %d\n", x);
    desempilhaB(&p, &x);
    printf("Desempilhou B: %d\n", x);


    return 0;
}
