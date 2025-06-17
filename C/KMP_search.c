#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_next(char *patt, int *next) {
    int i = 0, j = -1; // i当前主传正在匹配的字符位置，也是next的下标
    next[0] =
        -1; // next 数组的下标从 0 开始，表示模式串中每个字符的最长前缀后缀长度
    int patt_len = strlen(patt);
    while(i < patt_len) {
        if(j == -1 || patt[i] == patt[j]) {
            i++;
            j++;
            if(patt[i] != patt[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
            // 如果不相同，则查询前一个位置的next索引，并搜索
        }
    }
}

// 搜索patt在str中首次出现的位置，并返回其在str中的索引
int KMP_search(char *str, char *patt) {
    if(str == NULL || patt == NULL) {
        printf("NULL pointer!\n");
        return -1; // 返回错误码
    }
    int i = 0, j = 0;
    int str_len = strlen(str), patt_len = strlen(patt);
    int *next = (int *)malloc((strlen(patt)) * sizeof(int));
    if(next == NULL) {
        printf("Memory allocation failed!\n");
        return -1; // 返回错误码
    }
    build_next(patt, next);

    while(i < str_len && j < patt_len) {
        // 单字匹配，若匹配成功则光标后移
        if(j == -1 || str[i] == patt[j]) {
            i++;
            j++;
        } else {
            j = next[j]; // 若不成功则根据next数组查下一个匹配的下标
        }
    }
    free(next);
    if(j == strlen(patt)) {
        return i - strlen(patt); // 返回值为当前位置减patt长度
    } else {
        return -1;
    }
}

void test_KMP() {
    char *teststr1 = "aabsaaabdsa";
    char *testpatt1 = "abd";
    char *teststr2 = "goglegoogllgegollegooglelegooego";
    char *testpatt2 = "google";
    char *teststr3 = "";
    char *testpatt3 = "abc";
    char *teststr4 = "abc";
    char *testpatt4 = "";

    printf("Test 1: %d\n", KMP_search(teststr1, testpatt1)); // 6
    printf("Test 2: %d\n", KMP_search(teststr2, testpatt2)); // 18
    printf("Test 3: %d\n", KMP_search(teststr3, testpatt3)); // -1
    printf("Test 4: %d\n", KMP_search(teststr4, testpatt4)); // 0
}

int main() { test_KMP(); }