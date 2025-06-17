#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node, *NodeList;

// 头插法（使用void函数，通过二级指针修改head）
void insertAtHead(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *head; // 新节点指向原头节点
    *head = newNode;       // 更新头指针
}

// 打印链表
void printList(Node *head) {
    Node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node *head) {
    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

size_t i = 0;
size_t len = 7;
void teststr(Node *test) { (*test).data = 'a'; }
int main() {
    Node test;
    test.data = 'b';
    teststr(&test);
    printf("It's %c.\n", test.data);

    return 0;
}