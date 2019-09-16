#include <stdio.h>
#define BUFFERSIZE 1005
 
int card[10];
int output[BUFFERSIZE];
int size;
int prime[BUFFERSIZE];
int pCount = 0;
 
int checkPrime(int);
 
int checkPrime(int n) {
    int i;
 
    if (n < 2) return 0;
 
    for (i = 2; i < n; i++) {
        if (n%i == 0)
            return 0;
    }
 
    for (i = 0; i < pCount; i++) {
        if (prime[i] == n) return 0;
    }
 
    return 1;
}
 
void makeNum(int d) {
    int i, temp = 0;
 
    if (d == size) {
        for (i = 0; i < size; i++) {
            temp = temp * 10;
            temp = temp + output[i];
        }
        if (checkPrime(temp)) {
            prime[pCount++] = temp;
        }
    }
 
 
    for (i = 0; i < 10; i++) {
        if (0 < card[i]) {
            card[i]--;
            output[d] = i;
            makeNum(d + 1);
            card[i]++;
        }
    }
}
 
int main(void)
{
    int i, n, temp;
 
    scanf("%d", &n);
    size = n;
 
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        card[temp]++;
    }
 
    for (i = 1; i <= n; i++) {
        size = i;
        makeNum(0);
    }
 
 
    if (pCount == 0 || prime[0] == 0) printf("No Prime!");
    else
        for (i = 0; i < pCount; i++) {
            printf("%d ", prime[i]);
        }
 
    printf("\n");
    getchar();
    getchar();
 
    return 0;
}