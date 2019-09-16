#include <stdio.h>
#include <string.h>

#define MAX_M 55
#define MAX_N 55

static char a[MAX_M][MAX_N];
static char b[MAX_M][MAX_N];
static int m, n;

int find_match(char word[], int start_i, int start_j)
{
	static int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	static int dj[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	int i, j, k, t, dir, count, flag;
	for (dir = 0; dir < 8; dir++) {
		i = start_i;
		j = start_j;
		t = 0;
		count = 2;
		flag = 999;
		while (i >= 0 && i < m && j >= 0 && j < n && word[t] != '\0') {
			if (word[t] == a[i][j]) {
				i += di[dir];
				j += dj[dir];
				t++;
			}
			else if (word[t] != a[i][j]) {
				if (t - flag == 1) {
					break;
				}

				flag = t;
				count = count - 1;
				if (count < 0) {
					break;
				}

				i += di[dir];
				j += dj[dir];
				t++;
			}
		}
		if (word[t] == '\0') {
			for (k = 0; k < t; k++) {
				i -= di[dir];
				j -= dj[dir];
				b[i][j] = '#';
				
			}
		}
	}
	return 0;
}

int main(void)
{
	char arr[MAX_N];
	char word[6] = "teemo";
	int i, j;

	//while (1) {
		for (i = 0; i < MAX_N; i++)
			arr[i] = 0;

		fgets(arr, MAX_N, stdin);
		arr[strlen(arr) - 1] = '\0';

		m += arr[0] - 48;
		for (i = 1; arr[i] != 32; i++) {
			m *= 10;
			m += arr[i] - 48;
		}

		n = arr[++i] - 48;
		i++;
		for (; arr[i] !='\0'; i++) {
			n *= 10;
			n += arr[i] - 48;
		}

		for (i = 0; i < m; i++) {
			fgets(arr, MAX_N, stdin);
			arr[strlen(arr) - 1] = '\0';
			for (j = 0; arr[j] != NULL; j++) {
				a[i][j] = arr[j];
				b[i][j] = a[i][j];
				if (a[i][j] >= 'A' && a[i][j] <= 'Z')
					a[i][j] += ('a' - 'A');
			}
		}

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				find_match(word, i, j);
			}
		}
		printf("\n");
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%c", b[i][j]);
			}
			printf("\n");
		}
	//}
	return 0;
}
