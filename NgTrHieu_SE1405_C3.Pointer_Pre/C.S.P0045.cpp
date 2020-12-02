#include<stdio.h>
#include<string.h>


void swap(char a[], char b[]){
	char c[20];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}

int main(){
	char Arr[20][20];
	int n;
	int i,j;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter %d name\n",n);
	fflush(stdin);
	for (i=0; i<n; i++){
	gets(Arr[i]);
	}
	printf("List input name: \n");
	
	for (i=0; i<n; i++){
		printf("%d . ",i+1);
		puts(Arr[i]);
	}
	swap(Arr[0], Arr[1]);
	for (i=0; i< n-1; i++){
		for (j=i+1; j<n; j++){
			if (strcmp(Arr[i],Arr[j])>0) swap(Arr[i],Arr[j]);
		}
	}
	printf("List sort name:\n");
	for (i=0; i<n; i++){
		printf("%d . ",i+1);
		puts(Arr[i]);
	
}
}

