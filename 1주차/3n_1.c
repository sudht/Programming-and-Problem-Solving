#include <stdio.h>

int main(void)
{
	long x, y;

	while (scanf("%d %d", &x, &y) == 2) {
		if(x == y) {
			printf("Y\n");
			x = 1;
		}

		while(x != 1) {
			if(x%2)
				x = x * 3 + 1;
			else
				x /= 2;
			if(x == y) {
				printf("Y\n");
				break;
			}
		}
		if(x != y)
			printf("N\n");
	}

	return 0;
}
