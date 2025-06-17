#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int *data;
int *parent;

void init_parent(int *parent, int len) {
    for(int i = 0; i < len; i++) {
        parent[i] = -1; // 负值表示根节点，同时高度为1
    }
}

int find_root(int *parent, const int x) {
    if(parent[x] < 0) {
        return x;
    } else {
        return parent[x] = find_root(parent, parent[x]); // 路径压缩
    }
}

void union_set(int *parent, const int x, const int y) {
    int root_x = find_root(parent, x);
    int root_y = find_root(parent, y);
    if(root_x != root_y) {
        if(parent[root_x] < parent[root_y]) {
            parent[root_y] = root_x; // 负数越小的值高度越大
        } else if(parent[root_x] > parent[root_y]) {
            parent[root_x] = root_y;
        } else {
            parent[root_x] = root_y;
            parent[root_y]--; // 树高度加一
        }
    }
}

void list_root(const int *data, const int *parent) {
    printf("The root of data is:\n");
    for(int i = 0; i < SIZE; i++) {
        if(parent[i] < 0) {
            printf("data[%d] = %d.\n", i, data[i]);
        }
    }
}

int main() {
    data = (int *)malloc(sizeof(int) * SIZE);
    parent = (int *)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < SIZE; i++) {
        data[i] = i * 10;
        printf("data[%d] = %d.\n", i, data[i]);
    }
    init_parent(parent, SIZE);
    union_set(parent, 1, 3);
    union_set(parent, 4, 3);
    union_set(parent, 5, 1);
    union_set(parent, 2, 6);
    for(int i = 0; i < SIZE; i++) {
        printf("The parent of data[%d] = %d is data[%d] = %d.\n", i, data[i],
               parent[i] < 0 ? -parent[i] : parent[i],
               data[find_root(parent, i)]);
    }
    list_root(data, parent);

    free(data);
    free(parent);
    return 0;
}
