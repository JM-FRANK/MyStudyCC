#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff

typedef struct {
    VertexType vertex[MAXSIZE];     // 节点
    EdgeType arc[MAXSIZE][MAXSIZE]; // 权重
    int vertex_num;                 // 节点数
    int edge_num;                   // 边数
} Mat_Graph;

typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

void create_graph(Mat_Graph *G) {
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';

    for(int i = 0; i < G->vertex_num; i++) {
        for(int j = 0; j < G->vertex_num; j++) {
            if(i == j) {
                G->arc[i][j] = 0;
            } else {
                G->arc[i][j] = MAX;
            }
        }
    }
    // A-B A-F B-C B-G B-I C-D C-I D-E D-G D-H D-I E-F E-H F-G G-H
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    G->arc[1][2] = 18;
    G->arc[1][6] = 16;
    G->arc[1][8] = 12;
    G->arc[2][3] = 22;
    G->arc[2][8] = 8;
    G->arc[3][4] = 20;
    G->arc[3][6] = 22;
    G->arc[3][7] = 16;
    G->arc[3][8] = 21;
    G->arc[4][5] = 26;
    G->arc[4][7] = 7;
    G->arc[5][6] = 17;
    G->arc[6][7] = 19;
    for(int i = 0; i < G->vertex_num; i++) {
        for(int j = 0; j < i; j++) {
            G->arc[i][j] = G->arc[j][i];
        }
    }
}

void prim(Mat_Graph *G, int st) {
    int i, j, k;
    int min;
    int weighted[MAXSIZE];
    int vex_index[MAXSIZE]; // 值代表出发点，下标代表到达点

    for(i = 0; i < G->vertex_num; i++) {
        weighted[i] = G->arc[st][i];
        vex_index[i] = st;
    }

    for(i = 1; i < G->vertex_num; i++) {
        // 循环总顶点数减一次以找出所有顶点
        k = st; // 使用k来记录上一个(待选)节点信息
        min = MAX;
        for(j = 0; j < G->vertex_num; j++) {
            if(weighted[j] != 0 && weighted[j] < min) {
                min = weighted[j];
                k = j; // 当当前边小于最小权重时，更新待选节点并记录值
            }
        }
        printf("(%c, %c) %d\n", G->vertex[vex_index[k]], G->vertex[k], min);
        weighted[k] = 0; // 将访问过的节点标记为不可访问
        // 更新上个节点对应的所有权重至weighted
        for(j = 0; j < G->vertex_num; j++) {
            if(weighted[j] != 0 && G->arc[k][j] < weighted[j]) {
                weighted[j] = G->arc[k][j];
                vex_index[j] = k;
            }
        }
    }
}

int compare_weight(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void init_parent(int *parent, int len) {
    for(int i = 0; i < len; i++) {
        parent[i] = -1; // 负值表示根节点，同时高度为1
    }
}

int find_set(int *parent, const int x) {
    if(parent[x] < 0) {
        return x;
    } else {
        return parent[x] = find_set(parent, parent[x]); // 路径压缩
    }
}

void union_set(int *parent, const int x, const int y) {
    int root_x = find_set(parent, x);
    int root_y = find_set(parent, y);
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

void Kruskal(Mat_Graph *G) {
    Edge *edges = (Edge *)malloc(sizeof(Edge) * G->edge_num);
    int *parent = (int *)malloc(sizeof(int) * G->edge_num);
    int k = 0;
    for(int i = 0; i < G->vertex_num; i++) {
        for(int j = i + 1; j < G->vertex_num; j++) {
            if(G->arc[i][j] < MAX) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G->arc[i][j];
                k++;
            }
        }
    }
    qsort(edges, k, sizeof(Edge), compare_weight);
    init_parent(parent, G->vertex_num);
    int sl_edges = 0;

    for(int i = 0; i < k && sl_edges < G->vertex_num - 1; i++) {
        int start = edges[i].begin;
        int end = edges[i].end;
        if(find_set(parent, start) != find_set(parent, end)) {
            union_set(parent, start, end);
            printf("(%c,%c) %d\n", G->vertex[start], G->vertex[end],
                   edges[i].weight);
            sl_edges++;
        }
    }
    free(edges);
    free(parent);
}

int main() {
    Mat_Graph G;

    create_graph(&G);
    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    prim(&G, 8);
    Kruskal(&G);
    return 0;
}