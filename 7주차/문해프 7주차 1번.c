#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 10005
 
int antArray[BUFFERSIZE] = { 0, };
 
void makeArray() {
    int i, num, count, index;
    int tempArray[BUFFERSIZE] = { 0, };
 
    num = antArray[0];
    count = 0;
    index = 0;
    for (i = 0; ; i++) {
        if (antArray[i] == num) {
            count++;
        }
        else if (antArray[i] == 0) {
            tempArray[index] = num;
            index++;
            tempArray[index] = count;
            index++;
            break;
        }
        else {
            tempArray[index] = num;
            index++;
            tempArray[index] = count;
            index++;
            num = antArray[i];
            count = 1;
        }
    }
 
    for (i = 0; tempArray[i]; i++) {
        antArray[i] = tempArray[i];
    }
 
    while (antArray[i]) {
        antArray[i++] = 0;
    }
}
 
void antProgression(int n) {
    int i;
 
    for (i = 0; i < n; i++) {
        makeArray();
    }
}
 
int main(void)
{
    int i, n;
    char arr[BUFFERSIZE];
 
    antArray[0] = 1;
 
    while (fgets(arr, BUFFERSIZE, stdin) != NULL) {
        arr[strlen(arr) - 1] = '\0';
        n = 0;
        for (i = 0; i < (signed)strlen(arr); i++) {
            n = 10 * n + (arr[i] - '0');
        }
 
        antProgression(n-1);
 
        for (i = 0; antArray[i]; i++) {
            printf("%d", antArray[i]);
        }
 
        printf("\n");
    }
 
    return 0;
}