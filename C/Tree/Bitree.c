#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    struct TreeNode *l_ch;
    struct TreeNode *r_ch;
    bool l_tag;
    bool r_tag;
} TreeNode, *Tree;
typedef struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
} QueueNode;
typedef struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
    size_t size;
} Queue;
// 初始化队列
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}
// 将树节点加入队列
void EnQueue(Queue *q, TreeNode *tnode) {
    QueueNode *qnode = (QueueNode *)malloc(sizeof(QueueNode));
    if(qnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    qnode->node = tnode;
    qnode->next = NULL;
    if(q->front == NULL) {
        q->front = qnode;
        q->rear = qnode;
    } else {
        q->rear->next = qnode;
        q->rear = qnode;
    }
    q->size++;
}
// 出队操作
void DeQueue(Queue *q, TreeNode **tnode) {
    if(q == NULL) {
        printf("NULL Queue pointer!\n");
        return;
    }
    if(q->front == NULL) {
        printf("NULL QueueNode in Queue!\n");
        return;
    }
    *tnode = q->front->node;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
}
// 释放队列，仅释放队列，树节点未释放
void FreeQueue(Queue *q) {
    QueueNode *temp;
    while(q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}
// 以前序遍历建立二叉树
void creatTree(Tree *T, char **str) {
    ElemType ch = *((*str)++);
    if(ch == '#' || ch == '\0') {
        *T = NULL;
    } else {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->l_tag = false; // 初始化线索标记
        (*T)->r_tag = false; // 全为0表示未进行线索化
        creatTree(&(*T)->l_ch, str);
        creatTree(&(*T)->r_ch, str);
    }
}
// 前序遍历线索化二叉树
void Prethread(Tree T, TreeNode **prev) {
    // 若需后序中序线索化仅需要调整结构体位置
    if(T != NULL) {
        if(T->l_ch == NULL) {
            T->l_ch = *prev;
            T->l_tag = true;
        }
        if(*prev != NULL && (*prev)->r_ch == NULL) {
            (*prev)->r_ch = T;
            (*prev)->r_tag = true;
        }
        *prev = T;
        if(!T->l_tag) {
            Prethread(T->l_ch, prev);
        }
        if(!T->r_tag) {
            Prethread(T->r_ch, prev);
        }
    }
}
// 初始化头节点并对二叉树进行前序遍历线索化
void PrethreadTree(TreeNode *head, Tree *T) {
    TreeNode *prev;
    head->l_tag = false;
    head->r_tag = true;
    head->r_ch = head; // 头节点右指针指向自身
    if(*T == NULL) {
        head->l_ch = head;
    } else {
        head->l_ch = *T; // 头节点左指针指向二叉树根节点
        prev = head;
        Prethread(*T, &prev);
        prev->r_ch = head; // 最后一个节点的右线索指向头节点
        prev->r_tag = true;
        head->r_ch = prev; // 头节点的右指针指向最后一个节点
    }
}
// 释放二叉树内存
void freeTree(Tree T) {
    if(T != NULL) {
        if(!T->l_tag) {
            freeTree(T->l_ch);
        }
        if(!T->r_tag) {
            freeTree(T->r_ch);
        }
        free(T);
    }
}
// 迭代顺序遍历线索二叉树
void NRTVisit(TreeNode *head) {
    TreeNode *curr = head->l_ch;
    while(curr != head) {
        printf("Content is %c.\n", curr->data);
        if(!curr->l_tag) {
            curr = curr->l_ch;
        } else {
            curr = curr->r_ch;
        }
    }
}
// 无法优雅的迭代逆序遍历前序线索二叉树
void NRTVisitR(TreeNode *head);
// 层序搜索二叉树
int deepVisit(TreeNode *root) {
    if(NULL == root) {
        printf("NULL head node!\n");
        return -1;
    }
    int depth = 0;
    Queue q;
    initQueue(&q);
    EnQueue(&q, root);
    while(q.front != NULL) {
        int count = q.size;
        while(count > 0) {
            TreeNode *curr;
            DeQueue(&q, &curr);
            printf("Current data is %c in %d.\n", curr->data, depth + 1);
            if(curr->l_ch != NULL && !curr->l_tag) {
                EnQueue(&q, curr->l_ch);
            }
            if(curr->r_ch != NULL && !curr->r_tag) {
                EnQueue(&q, curr->r_ch);
            }
            count--;
        }
        depth++;
    }
    FreeQueue(&q);
    return depth;
}

int main() {
    Tree testT;
    TreeNode head;
    char *testtree = "ABDH##I##EJ###CF##G##";
    creatTree(&testT, &testtree);
    PrethreadTree(&head, &testT);
    printf("The depth of Tree is %d.\n", deepVisit(head.l_ch));
    freeTree(testT);
    return 0;
}