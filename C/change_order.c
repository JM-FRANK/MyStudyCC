#include <stdio.h>
#include <stdlib.h>

int main() {
    while(1) {
        int num, a, b, c;
        scanf("%d", &num);
        a = num / 100;
        b = (num / 10) % 10;
        c = num % 10;
        printf("%d", a + b * 10 + c * 100);
        system("pause");
    }
    return 0;
}