#include <stdio.h>
#define BUFFERSIZE 105
 
int arr[BUFFERSIZE][BUFFERSIZE];
int temp[BUFFERSIZE][BUFFERSIZE];
 
int move[8][2] = { {-2, 1} , {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
int count = 1;
 
 
int checked(int a, int b) {
    if (arr[a][b] != -1) return 1;
    else return 0;
}
 
void backTrack(int x, int y, int N) {
    int i;
 
    for (i = 0; i < 8; i++) {
        if ((x + move[i][0] < N) && (x + move[i][0] >= 0) && (y + move[i][1] < N) && (y + move[i][1] >= 0)) {
            if (checked(x + move[i][0], y + move[i][1])) {
                continue;
            }
 
            x = x + move[i][0];
            y = y + move[i][1];
            arr[x][y] = count;
            temp[x][y] = count;
            count++;
 
 
            backTrack(x, y, N);
            if (count == N * N + 1) return;
 
            arr[x][y] = -1;
            count--;
            x = x - move[i][0];
            y = y - move[i][1];
        }
    }
}
 
int main(void)
{
    int N;
    int x, y;
    int i, j, k;
 
    scanf("%d", &N);
    scanf("%d %d", &x, &y);
 
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            arr[i][j] = -1;
            temp[i][j] = -1;
        }
    }
 
    arr[x][y] = count;
    temp[x][y] = count;
    count++;
    backTrack(x, y, N);
 
    if (count == N * N + 1) {
        for (i = 0; i <= N * N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < N; k++) {
                    if (temp[j][k] == i) {
                        printf("%d %d\n", j, k);
                    }
                }
            }
        }
    }
    else
        printf("-1 -1");
 
    printf("\n");
    getchar();
    getchar();
 
    return 0;
}