#include <stdio.h>
#define max 100
//Enter a array
int Input(int *A,int  &n){
	int i;
	printf("Please enter size of array: ");
	scanf("%d",&n);
	for (i=0; i<n; i++){
		printf("Element[%d]: ",i);
		scanf("%d",&A[i]);
	}
}

/*Loop up the smallest element position in the array
 Display the smallest element and its position*/
int Smallest(int *A,int n){
	int i;
	int Smallest, Position;
	Smallest = A[0];
  	for(i=0; i<n; i++)
   	{
    	if(Smallest > A[i])
     	{
      		Smallest = A[i];
      		Position = i;
	 	}  
	
	}
printf("\nThe smallest element: %d - Its position: %d ", Smallest, Position+1);

}

int main(){
	
	int a[max], n, i;

  	Input(a,n);
  	Smallest(a, n);
    return 0;
    getchar();
 
}

