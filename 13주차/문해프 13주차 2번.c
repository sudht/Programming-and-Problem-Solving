#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFFERSIZE 10005
#define MAXHEIGHT 505
 
int checked[BUFFERSIZE];
int sandCastle[BUFFERSIZE][MAXHEIGHT] = { 0, };
 
int numOfCase(int N) {
    int i, j;
    int sum;
    sandCastle[0][0] = 1;
 
    for (i = 1; i < N; i++) {
 
        if (checked[i] != -1) {
            sum = 0;
            j = checked[i] - 1;
            sum += sandCastle[i - 1][j - 1] + sandCastle[i - 1][j] + sandCastle[i - 1][j + 1];
            sandCastle[i][j] = sum;
            continue;
        }
 
        for (j = 0; j < N / 2; j++) {
            sum = 0;
            sum += sandCastle[i - 1][j] + sandCastle[i - 1][j + 1];
            if (j != 0) {
                sum += sandCastle[i - 1][j - 1];
            }
            sandCastle[i][j] = sum;
        }
    }
 
    return 0;
}
 
int main(void)
{
    int N;
    int i;
 
    scanf("%d", &N);
 
    for (i = 0; i < N; i++) {
        scanf("%d", &checked[i]);
    }
 
    numOfCase(N);
    printf("%d", sandCastle[N - 1][0]);
    
    printf("\n");
    getchar();
    getchar();
    return 0;
}