#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 1000
#define STACK_SIZE 1000

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull()) {
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;	
}

element pop() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];	 
}

void printStack() {
	int i, num = stack[0];
	for (i = 1; i <= top; i++) {
		if(stack[i] == '+') {
			num = num + stack[i+1];
			i++;
		}
		else if(stack[i] == '-'){
			num = num - stack[i+1];
			i++;
		}
		else if(stack[i] == '*'){
			num = num * stack[i+1];
			i++;
		}
		else if(stack[i] == '/'){
			num = num / stack[i+1];
			i++;
		}
	}
	printf("%d\n", num);
}

int main(void)
{
	int i, num, flag, errorFlag;
	char arr [BUFFERSIZE];

	while (fgets(arr, BUFFERSIZE, stdin)!= NULL) {
		num = 0;
		errorFlag = 0;
		flag = 0;

		for(i = 0; !(isEmpty()); i++)
			pop();

		if(arr[0] == 80 || arr[0] == 83 || arr[0] == 84 || arr[0] == 86)
			errorFlag = 1;

		for(i = 0; arr[i]; i++) {
			if(arr[i] > 64 && arr[i] < 75) {
				flag = 0;
				num *= 10;
				num += arr[i] - 65;
			}
			else if(arr[i] == 80 && !flag) {
				flag = 1;
				push(num);
				push('+');
				num = 0;
			}
			else if(arr[i] == 83 && !flag) {
				flag = 1;
				push(num);
				push('-');
				num = 0;
			}
			else if(arr[i] == 84 && !flag) {
				flag = 1;
				push(num);
				push('*');
				num = 0;
			}
			else if(arr[i] == 86 && !flag) {
				flag = 1;
				push(num);
				push('/');
				num = 0;
			}
			else if(arr[i] == 10) {
				push(num);
				break;
			}
			else {
				for(i = 0; !(isEmpty()); i++)
					pop();
				errorFlag = 1;
				break;
			}
		}
		if(!errorFlag && !flag)
			printStack();
		else
			printf("Error\n");

	}
	return 0;
}
