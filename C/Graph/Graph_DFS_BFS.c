#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct {
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} Mat_Graph;

int visited[MAXSIZE];

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
            G->arc[i][j] = 0; // Initialize all edges to 0
        }
    }
    // A-B A-F B-C B-G B-I C-D C-I D-E D-G D-H D-I E-F E-H F-G G-H
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[6][7] = 1;
}

void DFS(Mat_Graph G, int i) {
    visited[i] = 1;              // Mark the vertex as visited
    printf("%c\n", G.vertex[i]); // Print the vertex
    for(int j = 0; j < G.vertex_num; j++) {
        if(G.arc[i][j] != 0 && !visited[j]) {
            DFS(G, j); // Recursive call to visit the next vertex
        }
    }
}

void BFS(Mat_Graph G) {
    int queue[MAXSIZE];
    int front = 0, rear = 0;
    int i = 0;
    visited[i] = 1;
    printf("%c\n", G.vertex[i]);
    queue[rear++] = i; // 将顶点i入队
    while(front < rear) {
        i = queue[front++]; // 出队顶点i
        for(int j = 0; j < G.vertex_num; j++) {
            if(G.arc[i][j] != 0 && !visited[j]) {
                visited[j] = 1;              // Mark the vertex as visited
                printf("%c\n", G.vertex[j]); // Print the vertex
                queue[rear++] = j;           // Enqueue the vertex
            }
        }
    }
}
int main() {
    Mat_Graph G;
    create_graph(&G);

    for(int i = 0; i < G.vertex_num; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }
    printf("Depth First Search starting from vertex A:\n");
    DFS(G, 0); // Start DFS from vertex A (index 0)
    for(int i = 0; i < G.vertex_num; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }
    printf("Wide First Search starting from vertex A:\n");
    BFS(G); // Start BFS from vertex A (index 0)
    return 0;
}
