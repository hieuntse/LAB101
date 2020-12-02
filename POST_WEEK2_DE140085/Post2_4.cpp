#include <stdio.h>
#include <stdlib.h>
#define max 100
//	Enter an integer array
void input(int *A, int n){
	int i;
	for (i=0; i<n; i++){
		
	printf("Enter element[%d]: ",i);
	scanf("%d", &A[i]);
	}
}
// Display array on the screen
void print(int *A, int n){
	int i;
	for (i=0; i<n; i++){
		printf("%d\t",A[i]);
	}
}
/*Sort array in ascending 
and display the sorted array on the screen*/
int sortAsc(int *A, int n){
	int i,j,t;
	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++)
		if (A[i]>A[j]){
			t = A[i];
			A[i]= A[j];
			A[j]= t;	
		}	
	}
	printf("\n  The array after sorting: \n");
	print(A, n);
}
/*Add new value entered to the sorted array in ascending order
 and then display new array on the screen*/
int addValue_sort(int *A, int n){
	int add,p,i;
	printf("\nPlease enter new value: ");
	scanf("%d", &add);
	for (i=0; i<n; i++)
	if (add<A[i])
	{ 
		p= i;
		break;		
	}
	for (i=n; i>=p; i--)
		A[i]= A[i-1];
		A[p]= add;
		n++;
		printf("New array: \n");
		print(A,n);
	//	for (i=0; i<=n; i++)
	//	printf("%d\t",A[i]);
		printf("\n");	
}

int main(){
	int Arr[max];
	int n;
	do {
		printf("Please enter size of array: ");
		scanf("%d",&n);
	}
	while (n<0 || n> max);
	input(Arr, n);
	sortAsc(Arr, n);
	addValue_sort(Arr, n);
	return 0;	
}


