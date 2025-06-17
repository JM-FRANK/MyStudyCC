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
void NRTvisit(TreeNode *head) {
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
// 迭代逆序遍历前序线索二叉树
void NRTvisitR(TreeNode *head) {
    TreeNode *curr = head->r_ch; // 从最后一个节点开始
    while(curr != head) {
        printf("Content is %c.\n", curr->data);
        // 如果左指针为线索，直接跳到左线索
        if(curr->l_tag) {
            curr = curr->l_ch;
        } else {
            // 否则，需找到curr的前驱节点
            // 由于没有父指针，只能从head->l_ch（根）出发，寻找curr的前驱
            TreeNode *p = head->l_ch;
            TreeNode *pre = head;
            while(p != curr) {
                // 若p有右孩子且不是线索，且右孩子不等于curr，则一直往右走
                while(p->r_ch != NULL && !p->r_tag && p->r_ch != curr) {
                    p = p->r_ch;
                }
                // 如果右孩子就是curr，说明p是curr的前驱
                if(p->r_ch == curr) {
                    pre = p;
                    break;
                }
                // 否则往左子树走
                if(p->l_ch != NULL && !p->l_tag) {
                    p = p->l_ch;
                } else {
                    break;
                }
            }
            curr = pre;
        }
    }
}
int main() {
    Tree testT;
    TreeNode head;
    char *testtree = "ABDH##I##EJ###CF##G##";
    creatTree(&testT, &testtree);
    PrethreadTree(&head, &testT);
    NRTvisit(&head);
    NRTvisitR(&head);
    freeTree(testT);
    return 0;
}