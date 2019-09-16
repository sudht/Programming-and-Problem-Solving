#include <stdio.h>
#define BUFFERSIZE 1005
 
int main(void)
{
    int i, count;
    char arr[BUFFERSIZE];
    char arr1[BUFFERSIZE];
 
    int one[26] = { 0, };
    int two[26] = { 0, };
    while (fgets(arr, BUFFERSIZE, stdin) != NULL) {
        fgets(arr1, BUFFERSIZE, stdin);
        count = 0;
 
        for (i = 0; i < 26; i++) {
            one[i] = 0;
            two[i] = 0;
        }
 
        for (i = 0; arr[i] != NULL; i++) {
            one[arr[i] - 97]++;
        }
        
        for (i = 0; arr1[i] != NULL; i++)
            two[arr1[i] - 97]++;
 
        for (i = 0; i < 26; i++) {
            if (one[i] != two[i]) {
                if (one[i] > two[i])
                    count += one[i] - two[i];
                else
                    count += two[i] - one[i];
            }
        }
        printf("%d\n", count);
    }
    return 0;
}