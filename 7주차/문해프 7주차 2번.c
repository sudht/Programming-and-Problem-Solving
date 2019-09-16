#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 5050
 
char output[BUFFERSIZE];
char dictionary[BUFFERSIZE][BUFFERSIZE];
int dicCount = 0;
int alphabet[26] = { 0, };
char priority[BUFFERSIZE] = { 0, };
int len;
char tempArr[100][BUFFERSIZE];
int tempCount = 0;
 
void makeDic(int d) {
    int i;
 
    if (d == len) {
        if (dicCount < BUFFERSIZE) {
            for (i = 0; i < len; i++) {
                dictionary[dicCount][i] = output[i];
            }
            dicCount++;
        }
        return;
    }
 
    for (i = 0; i < 26; i++) {
        if (0 < alphabet[i]) {
            alphabet[i]--;
            output[d] = 'a' + i;
            makeDic(d + 1);
            alphabet[i]++;
        }
    }
}
 
void deleteOverlap() {
    int  i, j, k;
 
    for (i = 0; i < dicCount; i++) {
        for (j = 0; j < dicCount; j++) {
            if (!strcmp(dictionary[i], tempArr[j])) {
                break;
            }
        }
        if (j == dicCount) {
            for (k = 0; k < len; k++) {
                tempArr[tempCount][k] = dictionary[i][k];
            }
            tempCount++;
        }
    }
}
 
int main(void)
{
    int i, j, count;
    char arr[BUFFERSIZE];
 
    while (fgets(arr, BUFFERSIZE, stdin) != NULL) {
        count = 0;
        arr[strlen(arr) - 1] = '\0';
        len = (signed)strlen(arr);
 
        for (i = 0; i < 26; i++) {
            alphabet[i] = 0;
        }
 
        for (i = 0; i < len; i++) {
            alphabet[i] = 1;
        }
 
        for (i = 0; i < len; i++) {
            priority[i] = arr[i];
        }
 
        makeDic(0);
 
        for (i = 0; i < dicCount; i++) {
            for (j = 0; j < len; j++) {
                dictionary[i][j] = priority[dictionary[i][j] - 97];
            }
        }
 
        deleteOverlap();
 
        //printf("%d %d\n", dicCount, tempCount);
 
        for (i = 0; i < 100; i++) {
            printf("%s ", tempArr[i]);
        }
 
        printf("\n");
    }
 
    return 0;
}