#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initData 0

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// 创建节点
LNode* createNode(ElemType value){
    LNode *node = (LNode *)malloc(sizeof(LNode));
    if(node == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

// 向链表头部插入节点
void insertHead(LinkList *L, ElemType e){
    LNode *node = createNode(e);
    node->next = *L;
    *L = node;
}

// 向链表尾部插入节点
void insertTail(LinkList *L, ElemType e){
    LNode *node = createNode(e);
    LNode *p;   // 当前节点
    LNode *last;// 记录上一节点
    p = last = *L;
    while(p != NULL){
        last = p;
        p = p->next;
    }
    last->next = node;
}


// 向链表第i个位置后插入元素e
bool ListInsert(LinkList *L, int i, ElemType e){
    if(i < 0){
        printf("Wrong rank!\n");
        return false;
    }
    LNode *p;   // 当前扫描到的节点
    int j = 0;  // 节点位置
    p = *L;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    if(p == NULL){
        printf("The linklist is not long enough!\n");
        return false;
    }
    LNode *s = createNode(e);
    s->next = p->next;  // 将新节点的下一个改为原节点的下一个
    p->next = s;        // 将原节点的下一个改为新节点
    return true;
}


int main(){
    LinkList map=NULL;
    insertHead(&map, 10);
    insertTail(&map, 20);
    ListInsert(&map, 5, 30);
    // for(int i=0; i < 10; i++){
    // }
    LNode *p = map;
    for(int i=0; p != NULL; i++){
        printf("The %d node is %d\n", i, p->data);
        p = p->next;
    }
    return 0;
}
