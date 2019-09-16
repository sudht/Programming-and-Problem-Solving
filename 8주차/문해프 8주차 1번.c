#include <stdio.h>
#include <math.h>
 
int checkPrime(int n) {
    int i;
 
    if (n < 2) return 0;
 
    for (i = 2; i <= (int)sqrt(n); i++) {
        if (n%i == 0)
            return 0;
    }
 
    return 1;
}
 
int makePrime(int n, int size, int maxSize) {
    int i;
    if (size == maxSize) {
        printf("%d\n", n);
        return 0;
    }
    for (i = 1; i < 10; i++) {
        n = n * 10;
        n = n + i;
        size++;
        if (checkPrime(n)) {
            makePrime(n, size, maxSize);
            n = n / 10;
            size--;
        }
        else {
            n = n / 10;
            size--;
        }
    }
 
    return 0;
}
 
 
int main(void)
{
    int n;
 
    scanf("%d", &n);
 
    makePrime(0, 0, n);
    
 
    printf("\n");
    getchar();
    getchar();
 
    return 0;
}