#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int input(){
	int s;
		printf("	Number of element s= ");
	scanf("%d",&s);
  	fflush(stdin);
  	return s;
}

int* CreatPointer(int s){
	int* a = (int*) malloc(s* sizeof(int));
	if (a==NULL){
		printf("Could not allocate memory.");
	exit(0);
	}
	return a;
}

int Sum(int *a, int s){
	int i,sum=0;
	for (i=0; i<s; i++){
		printf("Enter an integer: ");
		scanf("%d",&a[i]);
		sum+= a[i];
	}
	printf("Sum= %d\n",sum);	
}

int main(){
	int s;
	char c;
	do {
		printf("\nDynamic memory allocation\n");
		//input s
		s= input();
		//allocate memory
		int *a= CreatPointer(s);
		//calcutator sum
		Sum(a,s);
		printf("Press any key to continue(ESC to exit).\n");
		//free the memory
		free(a);
		c= getch();
	} while (c!=27);
	  return 0;
}




