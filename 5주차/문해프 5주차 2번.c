#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 1005

int map[26] = { 0, };
int mapTemp[26] = { 0, };

void checkWord(char *FirstTemp, char *SecondTemp) {
	int i = 0, j = 0, index;
	for (i = 0; i < 26; i++) {
		mapTemp[i] = map[i];
	}
	if (((signed)strlen(FirstTemp) == (signed)strlen(SecondTemp))) {
		for (j = 0; j < (signed)strlen(FirstTemp); j++) {
			index = FirstTemp[j] - 'a';
			for (i = 0; i < 26; i++) {
				if (mapTemp[i] == SecondTemp[j])
					break;
			}
			if (mapTemp[index] == 0 && i == 26)
				mapTemp[index] = SecondTemp[j];
			else if (mapTemp[index] == SecondTemp[j])
				continue;
			else
				goto end_of_loop_i;
		}
	}
	for (j = 0; j < 26; j++) {
		if (map[j] == 0) {
			map[j] = mapTemp[j];
		}
	}
end_of_loop_i:;
}

int main(void)
{
	char Foxarr[BUFFERSIZE];
	char Firstarr[BUFFERSIZE];
	char Secondarr[BUFFERSIZE];
	int i = 0, j = 0, k = 0, l = 0, m = 0;

	char pltxt[] = "the quick brown fox jumps over the lazy dog";

	char * context = NULL;
	char *FisrstWord[BUFFERSIZE] = { NULL, };
	char *SecondWord[BUFFERSIZE] = { NULL, };
	char *tempToken;
	char *FirstTemp;
	char *SecondTemp;

	fgets(Foxarr, BUFFERSIZE, stdin);
	fgets(Firstarr, BUFFERSIZE, stdin);
	fgets(Secondarr, BUFFERSIZE, stdin);

	Foxarr[strlen(Foxarr) - 1] = '\0';
	Firstarr[strlen(Firstarr) - 1] = '\0';
	Secondarr[strlen(Secondarr) - 1] = '\0';

	for (i = 0; i < (signed)strlen(Foxarr); i++) {
		if ((Foxarr[i] != '?') && (Foxarr[i] != ' ')) {
			map[pltxt[i] - 'a'] = Foxarr[i];
		}
	}

	tempToken = strtok(Firstarr, " ");
	for (i = 0; tempToken != NULL; i++)
	{
		FisrstWord[i] = tempToken;
		tempToken = strtok(NULL, " ");
	}

	tempToken = strtok(Secondarr, " ");
	for (j = 0; tempToken != NULL; j++)
	{
		SecondWord[j] = tempToken;
		tempToken = strtok(NULL, " ");
	}

	for (k = 0; k < i; k++) {
		FirstTemp = FisrstWord[k];
		for (l = 0; l < j; l++) {
			SecondTemp = SecondWord[l];
			checkWord(FirstTemp, SecondTemp);
		}

	}

	for (i = 0; i < (signed)strlen(pltxt); i++) {
		if (pltxt[i] == ' ')
			printf(" ");
		else if (map[pltxt[i] - 'a'] == 0)
			printf("?");
		else
			printf("%c", map[pltxt[i] - 'a']);
	}
	printf("\n");
	getchar();
}