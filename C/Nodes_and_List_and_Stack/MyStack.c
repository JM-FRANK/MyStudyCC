#include <stdio.h>

typedef double ElemType;

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *ListStack;

typedef enum {
    LEFT_PARE = 1,
    RIGHT_PARE,
    SPACE,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EOS,
    NUM,
    TYPE_ERR
} contentType;

StackNode *createSKN(ElemType e) {
    StackNode *SKN = (StackNode *)malloc(sizeof(StackNode));
    if(SKN == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    SKN->data = e;
    SKN->next = NULL;
    return SKN;
}

void pushSKN(ListStack *LSK, ElemType e) {
    StackNode *SKN = createSKN(e);
    SKN->next = *LSK;
    *LSK = SKN;
}

void popSKN(ListStack *LSK, ElemType *e) {
    if(*LSK == NULL) {
        printf("The listStack is NULL\n");
        return;
    }
    *e = (*LSK)->data;
    StackNode *temp = *LSK;
    (*LSK) = (*LSK)->next;
    free(temp);
}

int LSKisEmpty(ListStack *LSK) { return LSK == NULL; }

void freeLSK(ListStack *LSK) {
    if(LSK == NULL)
        return;
    StackNode *temp = NULL;
    while(*LSK != NULL) {
        temp = *LSK;
        *LSK = (*LSK)->next;
        free(temp);
    }
    *LSK = NULL;
}
