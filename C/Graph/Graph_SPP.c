#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef int VertexType;
typedef int EdgeType;
typedef int DataType;

#define MAX 0x10000
#define MAXSIZE 100
#define MAXEDGE 200

typedef struct {
    DataType *dist;
    DataType *path;
    int rows;
    int cols;
} Path_Dist;

// 返回i，j索引对应的数据
DataType re_dist(Path_Dist mat, int row, int col) {
    return mat.dist[row * mat.cols + col];
}
DataType re_path(Path_Dist mat, int row, int col) {
    return mat.path[row * mat.cols + col];
}
// 写入数据至i，j
void set_dist(Path_Dist *mat, int row, int col, DataType data) {
    mat->dist[row * mat->cols + col] = data;
}

void set_path(Path_Dist *mat, int row, int col, DataType data) {
    mat->path[row * mat->cols + col] = data;
}

typedef struct {
    VertexType vertex[MAXSIZE];     // 节点
    EdgeType arc[MAXSIZE][MAXSIZE]; // 权重
    int vertex_num;                 // 节点数
} Mat_Graph;

void creatGraph(Mat_Graph *G) {
    G->vertex_num = 9;
    for(int i = 0; i < G->vertex_num; i++) {
        G->vertex[i] = i;
    }
    for(int i = 0; i < G->vertex_num; i++) {
        for(int j = 0; j < G->vertex_num; j++) {
            if(i == j) {
                G->arc[i][j] = 0;
            } else {
                G->arc[i][j] = MAX;
            }
        }
    }
    G->arc[0][1] = 1;
    G->arc[0][2] = 5;

    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;

    G->arc[3][4] = 2;
    G->arc[3][6] = 3;

    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;

    G->arc[5][7] = 5;

    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4;
    for(int i = 0; i < G->vertex_num; i++) {
        for(int j = 0; j < i; j++) {
            G->arc[i][j] = G->arc[j][i];
        }
    }
}

int choose_min(int *dist, int vertex_num) {
    int min = MAX;
    int minPos = -1;
    for(int i = 0; i < vertex_num; i++) {
        if(dist[i] > 0 && dist[i] < min) {
            min = dist[i];
            minPos = i;
        }
    }
    return minPos;
}

void dijkstra(Mat_Graph *G, int begin) {
    int path[MAXSIZE];
    int dist[MAXSIZE];
    for(int i = 0; i < G->vertex_num; i++) {
        dist[i] = G->arc[begin][i];
        path[i] = (dist[i] < MAX) ? begin : -1;
    }
    dist[begin] = 0;
    int next;
    for(int i = 0; i < G->vertex_num - 1; i++) {
        next = choose_min(dist, G->vertex_num);
        dist[next] = 0 - dist[next];
        for(int j = 0; j < G->vertex_num; j++) {
            if(dist[j] > 0) {
                if(abs(dist[next]) + G->arc[next][j] < dist[j]) {
                    dist[j] = abs(dist[next]) + G->arc[next][j];
                    path[j] = next;
                }
            }
        }
    }
    printf("The shortest path of %d is:\n", begin);
    for(int i = 0; i < G->vertex_num; i++) {
        printf("The distance of V%d to begin is: ", i);
        if(abs(dist[i]) == MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", abs(dist[i]));
        }
    }
}

void floyd(Mat_Graph G, Path_Dist *pd) {
    for(int i = 0; i < G.vertex_num; i++) {
        for(int j = 0; j < G.vertex_num; j++) {
            set_dist(pd, i, j, G.arc[i][j]);
            if(G.arc[i][j] < MAX && i != j) {
                set_path(pd, i, j, i);
            } else {
                set_path(pd, i, j, -1);
            }
        }
    }
    for(int k = 0; k < G.vertex_num; k++) {
        for(int i = 0; i < G.vertex_num; i++) {
            for(int j = 0; j < G.vertex_num; j++) {
                if(re_dist(*pd, i, j) >
                   re_dist(*pd, i, k) + re_dist(*pd, k, j)) {
                    set_dist(pd, i, j, re_dist(*pd, i, k) + re_dist(*pd, k, j));
                    set_path(pd, i, j, re_path(*pd, i, k));
                }
            }
        }
    }
}

int main() {
    Mat_Graph test;
    creatGraph(&test);
    Path_Dist pd;
    pd.rows = test.vertex_num;
    pd.cols = test.vertex_num;
    pd.dist = (DataType *)malloc(pd.rows * pd.cols * sizeof(DataType));
    pd.path = (DataType *)malloc(pd.rows * pd.cols * sizeof(DataType));
    floyd(test, &pd);

    // 打印结果示例：顶点0到其他顶点的最短路径
    printf("The shortest length from 0 to others:\n");
    for(int j = 0; j < test.vertex_num; j++) {
        printf("The shortest length from 0 to %d: ", j);
        if(re_dist(pd, 0, j) == MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", re_dist(pd, 0, j));
        }
    }
    free(pd.dist);
    free(pd.path);
    return 0;
}