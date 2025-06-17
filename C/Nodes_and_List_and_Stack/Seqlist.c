# include <stdio.h>
#include <stdlib.h>

# define DefineSize 10

typedef struct{
    int *data;
    int MaxSize;
    int length;
}Seqlist;

void initSeq(Seqlist *L){
    L->data = (int *)malloc(DefineSize*sizeof(int));
    L->length = 0;
    L->MaxSize = DefineSize;
}

void IncreaseSize(Seqlist *L, int len){
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    for(int i=0; i < L->length; i++){
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p);
}

void addNum(Seqlist *L, int num){
    if(L->length = L->MaxSize){
        return "The Seqlist is full";
    }
    L->data[L->length] = num;
    L->length++;
}

int main(){
    Seqlist test;
    initSeq(&test);
    addNum(&test, 20);
    addNum(&test, 35);
    for(int i=0; i < test.length; i++){
        printf("test.data is %d\n", test.data[i]);
    }

}