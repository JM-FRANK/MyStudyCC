#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char temp;
    do {
        temp = getchar();
        printf("%c ", temp);
    } while(temp >= '0' && temp <= '9');

    system("pause");
    return 0;
}