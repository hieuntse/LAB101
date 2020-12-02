#include<stdio.h>
#define MAX 100
//input an array
int input(int *arr, int n=0){
	int x;
	printf("Enter the elements of the array \n");
	do{
		scanf("%d", &x);
		arr[n]=x;
		n++;
	}
	while (x!=0);
	return n;
}
//print out an array
void outPutArr(int *arr, int n){
	int i;
	printf("Array elements: \n");
    for( i = 0;i < n; i++){
        printf(" %d\t", arr[i]);
    }
}
//find value max of element
int max(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (max < arr[i])   max = arr[i];
    return max;
}
//Even element
int Even(int arr[], int n){
	for (int i=0; i<n; i++)
	{	if (arr[i] % 2==0)
		printf(" %d\t",arr[i]);
	}
}

int main(){
	int arr[MAX],temp,n, Maximum;
	temp= input(arr, n);
	outPutArr(arr, temp-1);
	Maximum= max(arr, temp-1);
	printf("\n\nArray maximum value:\n");
	printf(" The max is %d\t",Maximum);
	printf("\n\nArray even values: \n");
	Even(arr, temp-1);
	getchar();
	}
