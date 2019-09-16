#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 100005

int numArr[BUFFERSIZE] = { 0, };
int haveNum[BUFFERSIZE] = { 0, };
int count;
int before;

void tokenizer(char arr[]) {
	int i, j, num;
	char *tempToken;
	char *context = NULL;
	char tempArr[BUFFERSIZE] = { NULL, };
	char *Word[BUFFERSIZE] = { NULL, };

	for (i = 0; i < (signed)strlen(arr); i++) {
		tempArr[i] = arr[i];
	}

	tempToken = strtok(tempArr, " ");
	for (i = 0; tempToken != NULL; i++)
	{
		Word[i] = tempToken;
		tempToken = strtok(NULL, " ");
	}

	i = i - 1;
	for (; i >= 0; i--) {
		num = 0;
		for (j = 0; j < (signed)strlen(Word[i]); j++) {
			num = 10 * num + (Word[i][j] - '0');
		}
		numArr[num]++;
	}
}

void printNum(int c, int num) {
	int i = 0;
	for (; i < c; i++) {
		printf("%d ", num);
		numArr[num]--;
	}
}

int checkAble(int minNum) {

	if (numArr[minNum + 1] != 0) {
		return 1;
	}
	else
		return 2;
}

int main(void)
{
	int i, j, n, temp, minIndex, check;
	char arr[BUFFERSIZE];

	while (fgets(arr, BUFFERSIZE, stdin) != NULL) {
		count = 0;
		for (i = 0; i < BUFFERSIZE; i++) {
			numArr[i] = 0;
			haveNum[i] = 0;
		}
		arr[strlen(arr) - 1] = '\0';
		n = 0;
		for (j = 0; j < (signed)strlen(arr); j++) {
			n = 10 * n + (arr[j] - '0');
		}

		fgets(arr, BUFFERSIZE, stdin);
		arr[strlen(arr) - 1] = '\0';


		tokenizer(arr);

		for (i = 0; i < BUFFERSIZE; i++) {
			if (numArr[i])
				haveNum[count++] = i;
		}

		for (i = 0; i < count; i++) {
			for (j = 1; j < count; j++) {
				if (haveNum[j] < haveNum[j - 1]) {
					temp = haveNum[j - 1];
					haveNum[j - 1] = haveNum[j];
					haveNum[j] = temp;
				}
			}
		}

		minIndex = 0;
		before = -10;
		for (i = 0; i < n; i++) {
			while (numArr[haveNum[minIndex]] == 0) {
				minIndex++;
			}
			check = checkAble(haveNum[minIndex]);

			if ((before + 1) == haveNum[minIndex]) {
				printNum(1, haveNum[minIndex + 1]);
				before = before + 1;
				continue;
			}

			if (check == 1) {
				if (haveNum[minIndex + 2] != 0) {
					printNum(1, haveNum[minIndex]);
				}
				else {
					printNum(1, haveNum[minIndex + 1]);
				}
			}
			else if (check == 2) {
				printNum(1, haveNum[minIndex]);
			}
			before = haveNum[minIndex];
		}
		printf("\n");
	}

	return 0;
}