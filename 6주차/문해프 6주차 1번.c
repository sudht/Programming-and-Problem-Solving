#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 105

typedef struct {
	float K;
	float D;
	float A;
	float KDA;
	char name[BUFFERSIZE];
} champ;

champ returnChamp(char arr[]) {
	champ tempChamp;
	char tempArr[BUFFERSIZE] = { NULL, };
	char *tempToken;
	char *Word[BUFFERSIZE] = { NULL, };
	char *context = NULL;
	float K, D, A;
	int i;

	for (i = 0; i < (signed)strlen(arr); i++) {
		tempArr[i] = arr[i];
	}

	tempToken = strtok(tempArr, " ");
	for (i = 0; tempToken != NULL; i++)
	{
		Word[i] = tempToken;
		tempToken = strtok(NULL, "/");
	}

	K = 0;
	for (i = 0; i < (signed)strlen(Word[1]); i++) {
		K = 10 * K + (Word[1][i] - '0');
	}

	D = 0;
	for (i = 0; i < (signed)strlen(Word[2]); i++) {
		D = 10 * D + (Word[2][i] - '0');
	}

	A = 0;
	for (i = 0; i < (signed)strlen(Word[3]); i++) {
		A = 10 * A + (Word[3][i] - '0');
	}
	tempChamp.K = K;
	tempChamp.D = D;
	tempChamp.A = A;
	for (i = 0; i < (signed)strlen(Word[0]); i++) {
		tempChamp.name[i] = Word[0][i];
	}
	tempChamp.name[i] = '\0';
	if (D)
		tempChamp.KDA = (K + A) / D;
	else
		tempChamp.KDA = 9999.0;

	return tempChamp;
}

int main(void)
{
	int n, i, j;
	char arr[BUFFERSIZE];
	char *stringChamp[BUFFERSIZE] = { NULL, };
	char arrTemp[BUFFERSIZE][BUFFERSIZE] = { NULL, };
	champ arrChamp[BUFFERSIZE];
	champ tempChamp;

	scanf("%d", &n);
	fgets(arr, BUFFERSIZE, stdin);
	for (i = 0; i < n; i++) {
		fgets(arr, BUFFERSIZE, stdin);
		arr[strlen(arr) - 1] = '\0';
		arrChamp[i] = returnChamp(arr);
		if (arrChamp[i].KDA < 1)
			arrChamp[i].KDA = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (arrChamp[j].KDA < arrChamp[j-1].KDA) {
				continue;
			}

			if (arrChamp[j].KDA > arrChamp[j-1].KDA) {
				tempChamp = arrChamp[j];
				arrChamp[j] = arrChamp[j - 1];
				arrChamp[j - 1] = tempChamp;
			}
			else if (arrChamp[j].D < arrChamp[j - 1].D) {
				tempChamp = arrChamp[j];
				arrChamp[j] = arrChamp[j - 1];
				arrChamp[j - 1] = tempChamp;
			}
			else if ((arrChamp[j].D == arrChamp[j - 1].D) && (strcmp(arrChamp[j].name, arrChamp[j-1].name) < 0)) {
				tempChamp = arrChamp[j];
				arrChamp[j] = arrChamp[j - 1];
				arrChamp[j - 1] = tempChamp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (arrChamp[j].KDA == arrChamp[j - 1].KDA && arrChamp[j].KDA == 9999.0) {
				if ((arrChamp[j].K+ arrChamp[j].A) > (arrChamp[j - 1].K + arrChamp[j-1].A)) {
					tempChamp = arrChamp[j];
					arrChamp[j] = arrChamp[j - 1];
					arrChamp[j - 1] = tempChamp;
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (arrChamp[i].KDA) {
			printf("%s ", arrChamp[i].name);
			printf("%.0f/", arrChamp[i].K);
			printf("%.0f/", arrChamp[i].D);
			printf("%.0f\n", arrChamp[i].A);
		}
	}

	getchar();
	return 0;
}