#include <stdio.h>
#include <stdlib.h>
int main() {
    int time1, time2, h1, m1, h2, m2, p1, p2, xt;
    scanf("%d %d", &time1, &time2);
    h1 = time1 / 100;
    m1 = time1 % 100;
    h2 = time2 / 100;
    m2 = time2 % 100;
    p1 = h1 * 60 + m1;
    p2 = h2 * 60 + m2;
    xt = p2 - p1;
    printf("%02d:%02d", xt / 60, xt % 60);
    return 0;
}