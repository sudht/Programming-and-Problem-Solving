#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
 
#define MAX 200
 
int jump, row, col;
int arr[MAX][MAX];
int visited[MAX][MAX][32];
 
typedef struct pos {
    int x;
    int y;
    int k;
    int count;
}pos;
 
typedef struct QNode {
    pos data;
    struct QNode *link;
} QNode;
 
typedef struct {
    QNode *front, *rear;
} LQueueType;
 
LQueueType *createLinkedQueue() {
    LQueueType *LQ;
    LQ = (LQueueType *)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}
 
int isEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        return 1;
    }
    else return 0;
}
 
void enQueue(LQueueType *LQ, pos item) {
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}
 
void deQueue(LQueueType *LQ) {
    QNode *old = LQ->front;
    pos item;
    if (isEmpty(LQ)) return;
    else {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        free(old);
        return;
    }
}
 
typedef struct {
    int y, x;
}Dir;
 
int moveOne[2][2] = { { 1, 0 },{ 0, 1 }};
// int moveOne[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int moveKnight[2][2] = { { 2, 1 },{ 1, 2 } };
// int moveKnight[8][2] = { { -1, -2 },{ -2, -1 },{ -2, 1 },{ -1, 2 },{ 2, 1 },{ 1, 2 },{ 2, -1 },{ 1, -2 } };
 
int BFS(int y, int x) {
    int curX, curY, nextX, nextY;
    int knight;
    int count;
    int i;
    LQueueType* Q;
    pos a = { y, x, 0, 0 };
 
    Q = createLinkedQueue();
    enQueue(Q, a);
    visited[y][x][0] = 1;
 
    while (!isEmpty(Q)) {
        curY = Q->front->data.y;
        curX = Q->front->data.x;
        knight = Q->front->data.k;
        count = Q->front->data.count;
        deQueue(Q);
 
        if (curX == col - 1 && curY == row - 1 )
            return count;
 
        if (knight < jump) {
            for (i = 0; i < 2; i++) {
 
                nextY = curY + moveKnight[i][0];
                nextX = curX + moveKnight[i][1];
 
                if (nextY < row && nextX < col)
                    if (!visited[nextY][nextX][knight + 1] && !arr[nextY][nextX]) {
                        visited[nextY][nextX][knight + 1] = 1;
                        a.y = nextY;
                        a.x = nextX;
                        a.k = knight + 1;
                        a.count = count + 1;
                        enQueue(Q, a);
                    }
            }
        }
 
        for (i = 0; i < 2; i++) {
            nextY = curY + moveOne[i][0];
            nextX = curX + moveOne[i][1];
 
            if (nextY < row && nextX < col)
                if (!visited[nextY][nextX][knight] && !arr[nextY][nextX]) {
                    visited[nextY][nextX][knight] = 1;
                    a.y = nextY;
                    a.x = nextX;
                    a.k = knight;
                    a.count = count + 1;
                    enQueue(Q, a);
                }
        }
    }
    return -1;
}
 
int main(void) {
    int K;
    int W, H;
    int i, j;
 
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
 
    jump = K;
    row = H;
    col = W;
 
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
 
    printf("%d", BFS(0, 0));
 
    printf("\n");
    getchar();
    getchar();
 
    return 0;
}