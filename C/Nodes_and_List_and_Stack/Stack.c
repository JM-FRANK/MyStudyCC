#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define initSize 10

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

int LSKisEmpty(ListStack *LSK) { return *LSK == NULL; }

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

contentType getToken(char c) {
    if(!isdigit(c)) {
        switch(c) {
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        case ' ':
            return SPACE;
        default:
            return TYPE_ERR;
        }
    } else {
        return NUM;
    }
}

ElemType getNumber(char *num, int *i) {
    ElemType result = 0;
    while(num[(*i)] != '\0' && getToken(num[(*i)]) != SPACE) {
        result = result * 10 + (num[(*i)] - '0');
        (*i)++;
    }
    (*i)--;
    return result;
}

// 计算后缀表达式的值
double eval(char *exp) {
    ListStack opt = NULL;
    ElemType a, b, result;
    for(int i = 0; exp[i]; i++) {
        // 当走到字符串结尾前一直循环
        switch(getToken(exp[i])) {
        //  若为数字则压入栈顶
        case NUM:
            a = getNumber(exp, &i);
            pushSKN(&opt, a);
            break;
        //  取出栈顶元素为前个元素并运算
        case ADD:
            popSKN(&opt, &b);
            popSKN(&opt, &a);
            a = a + b;
            pushSKN(&opt, a);
            break;
        case SUB:
            popSKN(&opt, &b);
            popSKN(&opt, &a);
            a = a - b;
            pushSKN(&opt, a);
            break;
        case MUL:
            popSKN(&opt, &b);
            popSKN(&opt, &a);
            a = a * b;
            pushSKN(&opt, a);
            break;
        case DIV:
            popSKN(&opt, &b);
            popSKN(&opt, &a);
            a = a / b;
            pushSKN(&opt, a);
            break;
        /*
        case MOD:
            popSKN(&opt, &a);
            a = a % getNumber(exp, &i);
        */
        case SPACE:
            break;
        default:
            printf("Error: Invalid character '%c' in expression\n", exp[i]);
            freeLSK(&opt);
            break;
        }
    }
    popSKN(&opt, &result);
    freeLSK(&opt);
    return result;
}
/*
int AOps(ListStack LSK, int *ans) {
    ListStack OPT = NULL;
    // 未完成!
    while(LSK != NULL) {
        if(LSK->data >= 41 && LSK->data <= 47) {
            int a, b;
            popSKN(&OPT, &b);
            popSKN(&OPT, &a);
            ans = a;
            pushSKN(&OPT, ans);
        } else {
            int i;
            popSKN(LSK, i);
            pushSKN(&OPT, i);
        }
        return (OPT->data);
    }
}
*/

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    //  时间检测
    char a[] = "8 2 / 2 + 5 6 * -";
    printf("The answer is %lf\n", eval(a));

    //  时间检测
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The spend time is %f s\n", cpu_time_used);
    return 0;
}