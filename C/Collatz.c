#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define maxn 1000

int num[maxn], *arr;
int len;

//* 以数组方式获取数字
void get_num(int* arr){
    char i = 'a';
    memset(num, 0, sizeof(num));
    printf("Please enter a number:");
    for(len=0; i!='\n'; len++){
        scanf("%c",&i);
        num[len] = i - '0';
    }
    num[--len] = '\0';
}

int sin_odd(){
    if()
}
int main(){
    *arr = num;
    system("pause");
    return 0;
}