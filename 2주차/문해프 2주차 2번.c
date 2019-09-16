#include <stdio.h>
#define BUFFERSIZE 1000
 
typedef struct {            
    int count;             
    int size;  
} mushroom;
 
mushroom mush[BUFFERSIZE + 5];
int mushCount;
 
void bindMushroom(int x) {
    int i;
    int checkCount = 0;
 
    for(i = 1 ; i<mushCount; i++) {
        if(mush[i].size == x) {
            checkCount = i;
            break;
        }
    }
 
    if(checkCount)
        mush[checkCount].count++;
 
    else {
        mush[mushCount].size = x;
        mush[mushCount].count++;
        mushCount++;
    }
}
 
int findMaxCount() {
    int i, max = 0;
    for(i = 1; i<mushCount; i++)
        if(mush[i].count > max) 
            max = mush[i].count;
    return max;
}
 
void printMushroom() {
    int i, j;
    int max = findMaxCount();
 
    while(max) {
        for(i = 1; i<mushCount; i++) {
            if(mush[i].count == max) {
                for(j=0; j<max; j++)
                    printf("%d ", mush[i].size);
            }
        }
        max--;
    }
}
 
int main(void)
{
    int M, N;
    int i;
    int x;
    mushCount = 1;
 
    while (scanf("%d %d", &N, &M) == 2) {
 
        for(i = 1; i<mushCount; i++) {
            mush[i].count = 0;
            mush[i].size = 0;
        }
        mushCount = 1;
        for(i = 0; i<N; i++) {
            scanf("%d", &x);
            if(x<=M)
                bindMushroom(x);
        }
        printMushroom();
        printf("\n");
    }
 
    return 0;
}