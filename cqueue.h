#ifndef _CQUEUE_H
#define _CQUEUE_H
#define TRUE 1
#define FALSE 0
#ifdef _CQUEU_C_



    typedef struct _queue_ {
        int front, rear;
        int maxItens;
        int numItens;
        void **elms;
    } CQueue;
    
    CQueue *cqCreate(int max);
    int cqDestroy(CQueue *cq);
    int cqEnqueue(CQueue *cq, void *data);
    void *cqDequeue(CQueue *cq);
    void *cqFirst(CQueue *cq);
    int cqIncCirc(int i, int max);
    int cqDeCirc(int i, int max);

#else 
    typedef struct _queue_ {
        int front, rear;
        int maxItens;
        int numItens;
        void **elms;
    } CQueue;
    extern CQueue *cqCreate(int max);
    extern int cqDestroy(CQueue *cq);
    extern int cqEnqueue(CQueue *cq, void *data);
    extern void *cqDequeue(CQueue *cq);
    extern void *cqFirst(CQueue *cq);
    extern int cqIncCirc(int i, int max);
    extern int cqDeCirc(int i, int max);
    
#endif
#endif