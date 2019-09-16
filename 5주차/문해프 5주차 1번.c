#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 1005
#define HanBase 65
#define HanLast  122

char *trimwhitespace(char *str)
{
	char *end;

	// Trim leading space
	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	// Write new null terminator character
	end[1] = '\0';

	return str;
}

int main(void)
{
	int i, Hcount, Ecount, temp;
	char arr[BUFFERSIZE];
	char Harr[BUFFERSIZE][2];
	char Earr[BUFFERSIZE];

	while (fgets(arr, BUFFERSIZE, stdin) != NULL) {
		arr[strlen(arr) - 1] = '\0';
		Hcount = 0;
		Ecount = 0;
		temp = 0;

		for (i = 0; i < BUFFERSIZE; i++) {
			Harr[i][0] = 0;
			Harr[i][1] = 0;
			Earr[i] = 0;
		}

		trimwhitespace(arr);

		for (i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == ' ')
				;
			else if (arr[i] > 0) {
				Earr[Ecount++] = arr[i];
			}
			else {
				Harr[Hcount][0] = arr[i++];
				Harr[Hcount++][1] = arr[i];
			}
		}

		for (i = 0; i < Ecount; i++) {
			printf("%c", Earr[i]);
		}

		for (i = 0; i < Hcount; i++) {
			printf("%c%c", Harr[i][0], Harr[i][1]);
		}

		printf("\n%d %d %d \n", Ecount, Hcount, Ecount + Hcount);

	}
	return 0;
}