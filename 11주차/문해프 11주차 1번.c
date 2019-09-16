#include <stdio.h>
 
#define BUFFERSIZE 10000
#define TRUE 1
#define FALSE 0
 
typedef struct vertex {
    int vote;
    int count;
    int visited;
} vertex;
 
vertex arr[BUFFERSIZE];
int countMafia = 0;
 
int checkMafia(int x, int isMafia) {
    int nextX;
 
    if (arr[x].visited) return 0;
 
    arr[x].visited = TRUE;
    nextX = arr[x].vote;
    arr[nextX].count = arr[nextX].count - 1;
    countMafia = countMafia + isMafia;
 
    if (isMafia == TRUE || arr[nextX].count == 0) {
        if (isMafia == FALSE) {
            checkMafia(nextX, TRUE);
        }
        else {
            checkMafia(nextX, FALSE);
        }
    }
    return 0;
}
 
int main() {
    int N;
    int i;
 
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &arr[i].vote);
        arr[i].vote = arr[i].vote;
        arr[arr[i].vote].count++;
    }
    for (i = 1; i <= N; i++) {
        if (arr[i].count == 0) {
            checkMafia(i, TRUE);
        }
    }
 
    for (i = 1; i <= N; i++) {
        checkMafia(i, FALSE);
    }
 
    printf("%d\n", countMafia);
 
    getchar();
    getchar();
    return 0;
}