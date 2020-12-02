#include <stdio.h>
#define maxn 100

void input(int *a, int &n){
	int i;
	printf("Please enter size of array: ");
	scanf("%d",&n);
	for (i=0; i<n; i++){
		printf("Element [%d]= ",i);
		scanf("%d",&a[i]);	
	}
}

int smallest(int *a, int n){
	int i, min, pos;
	min=a[0];
	for (i=0; i<n; i++){
		if (min>a[i])
		min= a[i];
		pos=i;
	}
	printf("\n\nThe smallest element: %d - Its position: %d",min, pos);
}

int main(){
	int a[maxn];
	int n;
	input(a,n);
	smallest(a,n);
	return 0;
	getchar();
}
