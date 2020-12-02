#include <stdio.h>
#include <conio.h>

int main(){
	int n,i;
	char c;
	do{
		do{
			printf("\nPlease enter a number (1 - 9): ");
			scanf("%d",&n);
		}
		while (n>10||n<1);
		printf("Multiplication table for 8 number: \n");
		for (i=1; i<=10; i++){
			printf("%d x %d = %d\n",n,i,n*i);
		}
		printf("--------------------------------\n");
		printf("Press any key to continue, Esc to exit.\n");
		getchar();
		c=getch();
	}
	while (c!=27);
	return 0;
}
