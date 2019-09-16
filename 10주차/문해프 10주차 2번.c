#include <stdio.h>
#include <math.h>
#define BUFFSIZE 905
#define MAXBUFFSIZE 5005
int arr[BUFFSIZE];
int arrC[MAXBUFFSIZE][2] = { 0, };
int output[60] = { 0, };
int rflag = 0;
int flag = 0;

int have(int a, int b) {
	int i;
	for (i = 0; arrC[i][0]; i++) {
		if (arrC[i][0] == a && arrC[i][1] == b) {
			return 1;
		}
	}
	return 0;
}

int backTrack(int n, int size, int maxSize) {
	int i, j;
	if (size == maxSize) {
		for (i = 0; i < size; i++) {
			for (j = i + 1; j < size; j++) {
				if (!have(output[i], output[j])) {
					return 0;
				}
			}
		}
		for (i = 0; i < size; i++) {
			printf("%d\n", output[i]);
		}
		flag = 1;
		rflag = 1;
		return 1;
	}
	for (i = 1; i <= BUFFSIZE; i++) {
		if (!flag) {
			if (arr[i]) {
				if (i < output[size - 1]) continue;
				if(size > 0 && !have(output[size-1], i)) continue;
				else if(size > 1 && !have(output[0], i)) continue;
				output[size++] = i;
				arr[i]--;
				backTrack(n, size, maxSize);
				output[size--] = 0;
				arr[i]++;
			}
		}
	}
	return 0;
}


int main(void)
{
	int K, N, M;
	int i;
	int temp1, temp2;
	int cCount = 0;

	scanf("%d %d %d", &K, &N, &M);

	for (i = 0; i < BUFFSIZE; i++) {
		arr[i] = 0;
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &temp1, &temp2);
		arrC[cCount][0] = temp1;
		arrC[cCount++][1] = temp2;
		arr[temp1] = 1;
		arr[temp2] = 1;
	}

	backTrack(0, 0, K);

	if (!rflag)
		printf("-1");

	getchar();
	getchar();

	return 0;
}