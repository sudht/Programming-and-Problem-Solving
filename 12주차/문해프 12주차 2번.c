#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXV 1000
#define BUFFERSIZE 2000
#define MAXINT 999999999
 
int map[BUFFERSIZE][BUFFERSIZE];
 
typedef struct {
    int weight[MAXV][MAXV];
    int nvertices;
} adjacency_matrix;
 
void initialize_adjacency_matrix(adjacency_matrix *g)
{
    int i, j;
    g->nvertices = 0;
    for (i = 0; i < MAXV; i++)
        for (j = 0; j < MAXV; j++)
            g->weight[i][j] = MAXINT;
}
 
void floyd(adjacency_matrix *g)
{
    int i, j;
    int k;
    int through_k;
    for (k = 0; k < g->nvertices; k++)
        for (i = 0; i < g->nvertices; i++)
            for (j = 0; j < g->nvertices; j++) {
                through_k = g->weight[i][k] + g->weight[k][j];
                if (through_k < g->weight[i][j])
                    g->weight[i][j] = through_k;
            }
}
 
int main(void)
{
    int row, col, timeLimit, maxJump;
    adjacency_matrix* adjm;
    int i, j, k;
    int nextX, nextY;
    int nowPos, nextPos;
    char temp;
    int time;
    int top;
    int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
 
    while (scanf("%d %d %d %d", &row, &col, &maxJump, &timeLimit) == 4) {
 
        adjm = (adjacency_matrix *)malloc(sizeof(adjacency_matrix));
        initialize_adjacency_matrix(adjm);
        // scanf("%c", &temp);
        adjm->nvertices = row * col;
 
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                do {
                    scanf("%c", &temp);
                } while (temp < 'A' || temp > 'Z');
                map[i][j] = temp - 'A';
            }
            // scanf("%c", &temp);
        }
 
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                nowPos = col * i + j;
                for (k = 0; k < 8; k++) {
                    nextX = i + dir[k][0];
                    nextY = j + dir[k][1];
                    if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue;
                    nextPos = col * nextX + nextY;
                    if (map[nextX][nextY] - map[i][j] > maxJump || map[i][j] - map[nextX][nextY] > maxJump) {
                        continue;
                    }
                    else if (map[nextX][nextY] - map[i][j] <= 0) {
                        adjm->weight[nowPos][nextPos] = 1;
                    }
                    else {
                        adjm->weight[nowPos][nextPos] = (map[nextX][nextY] - map[i][j]) * (map[nextX][nextY] - map[i][j]);
                    }
                }
            }
        }
 
        floyd(adjm);
        top = 0;
 
        for (i = 0; i < row*col; i++) {
            time = adjm->weight[0][i] + adjm->weight[i][0];
            if (time <= timeLimit) {
                nextX = i / row;
                nextY = i % row;
                if (top < map[nextX][nextY]) {
                    top = map[nextX][nextY];
                }
            }
        }
 
        printf("%d\n", top);
        free(adjm);
    }
 
    printf("\n");
    getchar();
    getchar();
    return 0;
}