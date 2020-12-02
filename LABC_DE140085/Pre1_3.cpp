#include <stdio.h>
#define MAXN 100
//input an array
void input(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
//print out an array
void output(int a[],  int n){

	for (int i=0; i<n; i++)
	printf("%d\t",a[i]);
	
}
void Loopup(int a[],int *n){
	int i,j,k;
	for(i=0; i<*n; i++)
    {
        for(j=i+1; j<*n; j++)
        {
            if(a[i] == a[j])
            {
                for(k=j; k<*n; k++)
                {
                    a[k] = a[k + 1];
                }
                (*n)--;
                j--;
            }
        }
    }
}
int main(){
	int a[MAXN];
	int n;
	do{
		printf("Enter an integer array: ", MAXN);
		scanf("%d",&n);
	} while (n<0||n>MAXN);
	input(a,n);
	printf("The original array: \n");
	output(a,n);
	printf("\nThe array after removing duplicate elements: \n");
	Loopup(a,&n);
	output(a,n);
	getchar();
}

