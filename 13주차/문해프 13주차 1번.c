#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 2000
#define BUFFERSIZE 1000
#define MAXINT 999

char map[BUFFERSIZE][BUFFERSIZE];

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
	int row, col;
	char arr[BUFFERSIZE];
	adjacency_matrix* adjm;
	int i, j, k;
	int nextX, nextY;
	int nowPos, nextPos;
	int time;
	int startpos, endpos;
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0},  {0, -1} };

	while (scanf("%d %d", &row, &col) == 2) {
		adjm = (adjacency_matrix *)malloc(sizeof(adjacency_matrix));
		initialize_adjacency_matrix(adjm);
		adjm->nvertices = row * col;

		for (i = 0; i < row; i++) {
			do {
				fgets(arr, BUFFERSIZE, stdin);
			} while (arr[0] < '#' || arr[0] > 'Z');
			arr[strlen(arr) - 1] = '\0';
			for (j = 0; j < col; j++) {
				map[i][j] = arr[j];
			}
		}

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				nowPos = col * i + j;
				for (k = 0; k < 4; k++) {
					nextX = i + dir[k][0];
					nextY = j + dir[k][1];
					if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue;
					nextPos = col * nextX + nextY;

					if (map[nextX][nextY] == '#') {
						continue;
					}
					else if (map[nextX][nextY] == '$') {
						startpos = nextPos;
						continue;
					}
					else {
						if (map[nextX][nextY] == '&') {
							adjm->weight[nowPos][nextPos] = 0;
							endpos = nextPos;
						}
						else {
							adjm->weight[nowPos][nextPos] = map[nextX][nextY] - 'A';
						}
					}
				}
			}
		}

		floyd(adjm);


		time = adjm->weight[startpos][endpos];


		printf("%d\n", time);
		free(adjm);

	}

	printf("\n");
	getchar();
	getchar();
	return 0;
}