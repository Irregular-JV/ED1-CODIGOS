#ifndef _STACK_H
#define _STACK_H
#ifdef _STACK_C_

    typedef struct _stack_ Stack;

    Stack *stkCreate(int max);
    int stkPush(Stack *s, void *elm);
    void *stkPop(Stack *s);
    void *stkTop(Stack *s);
    int stkIsEmpty(Stack *s);
    int stkDestroy(Stack *s);
    void *stcMultiPop(Stack *s, int k);

#else
    typedef struct _stack_ {
        int maxItens;
        int top;
        void **item;
    } Stack;
    extern  Stack *stkCreate(int max);
    extern int stkPush(Stack *s, void *elm);
    extern void *stkPop(Stack *s);
    extern void *stkTop(Stack *s);
    extern int stkIsEmpty(Stack *s);
    extern int stkDestroy(Stack *s);
    extern void *stcMultiPop(Stack *s, int k);

#endif
#endif