#include <stdio.h>
#include <stdlib.h>
 
#define MAXV 1000
#define MAXINT 999
 
typedef struct {
    int weight[MAXV + 1][MAXV + 1];
    int nvertices;
} adjacency_matrix;
 
void initialize_adjacency_matrix(adjacency_matrix *g)
{
    int i, j;
    g->nvertices = 0;
    for (i = 1; i <= MAXV; i++)
        for (j = 1; j <= MAXV; j++)
            g->weight[i][j] = MAXINT;
}
 
void floyd(adjacency_matrix *g)
{
    int i, j;
    int k;
    int through_k;
    for (k = 1; k <= g->nvertices; k++)
        for (i = 1; i <= g->nvertices; i++)
            for (j = 1; j <= g->nvertices; j++) {
                through_k = g->weight[i][k] + g->weight[k][j];
                if (through_k < g->weight[i][j])
                    g->weight[i][j] = through_k;
            }
}
 
int main() {
    int N, M;
    adjacency_matrix* adjm;
    int i, j;
    int temp;
    int x, y;
 
    adjm = (adjacency_matrix *)malloc(sizeof(adjacency_matrix));
    initialize_adjacency_matrix(adjm);
 
    scanf("%d", &N);
    adjm->nvertices = N;
 
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%d", &temp);
            adjm->weight[i][j] = temp;
        }
        
    }
 
    floyd(adjm);
 
    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", adjm->weight[x][y]);
    }
 
    printf("\n");
 
    getchar();
    getchar();
    return 0;
}