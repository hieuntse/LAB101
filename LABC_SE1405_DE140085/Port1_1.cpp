#include<stdio.h>
#define max 100

void input(int A[], int n){
	printf("Input elements: \n");
	for(int i=1; i<=n; i++){
		printf("\t Element %d= ",i);
		scanf("%d",&A[i]);
	}	
}

int SumOdd(int A[], int n){
	int sum =0;
	for (int i=1; i<=n; i++)
	{	if (A[i]%2 != 0){
			sum+=A[i];
		}
	}
	return sum;
}

int SumEven(int A[], int n){
	int sum1 =0;
	for (int i=1; i<=n; i++)
	{	if (A[i]%2 == 0){
			sum1+=A[i];	
		}
	}
	return sum1;
}

int main(){
	int arr[max],n;
	do
	{
		printf("Enter a number of element n= ",max);
		scanf("%d",&n);
	} while (n<0||n>max);
	input(arr,n);
	printf("\nSum of Odd = %d ",SumOdd(arr, n));
	printf("\nSum of Even = %d",SumEven(arr,n));
}
