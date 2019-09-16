#include <stdio.h>
#include <string.h>

#define BUFSIZE 1025

int main(void)
{
    char line[BUFSIZE];

    while (fgets(line, BUFSIZE, stdin) != NULL) {
        int words = 1, letters = 0;
        int i;

		for(i = strlen(line)-2; line[i] == ' '; i--)
			line[i] = '\n';

		for(i = 0; line[i] != '\n'; i++) {
			if (line[i] == ' ') words++;
			else letters++;
		}

        printf("%d %d\n", words, letters);
    }
    return 0;
}
