#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int* Pointer1(int x, int y){
	int *a= (int*) malloc(x* y* sizeof(int));
	
	if (a==NULL){
		printf("Could not allocate memory.");
		exit(0);
	}
	return a;
}

int* Pointer2(int x, int y){
	int *b= (int*) malloc(x* y* sizeof(int));
	if (b==NULL){
		printf("Could not allocate memory.");
		exit(0);
	}
}

void matrix1(int *a,int x, int y){
	int i,j;
	printf("Accept matrix m1: \n");
	for (i=0;i<x; i++){
		for (j=0;j<y; j++){
			scanf("%d",(a+ i*y +j));
		}
	}
}

void matrix2(int *b, int x, int y){
	int i,j;
	printf("Accept matrix m2: \n");
	for (i=0;i<x; i++){
		for (j=0;j<y; j++){
			scanf("%d",(b+ i*y +j));
		}
	}
}

int sum(int *a, int *b, int x, int y){
	int i,j;
	printf("m= m1 + m2: \n");
	for (i=0;i<x; i++){
		for (j=0;j<y; j++){
			printf("%d\t",*(a+ i*y +j) + *(b+ i*y +j));
		}
	printf("\n");
	}
}

int main(){
	int x,y;
	char c;
	do {
		//Accept row and collumn
		printf("\nMatrix Add\n");
		printf("Accept size: ");
		scanf("%d %d",&x,&y);
		fflush(stdin);
		//allocate memory and input matrix
		int *a= Pointer1(x,y);
		matrix1(a,x,y);
		int *b= Pointer2(x,y);
		matrix2(b,x,y);
		//Calculator sum
		sum(a,b,x,y);
		printf("Press any key to continue(ESC to exit).\n");
		//free the memory
		free(a);
		free(b);
		c= getch();
	}
	while(c!=27);
return 0;
}



