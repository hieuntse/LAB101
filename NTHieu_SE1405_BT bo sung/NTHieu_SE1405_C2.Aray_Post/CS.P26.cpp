#include<stdio.h>    
#include<stdlib.h> 
#include <conio.h> 
int main(){ 
char c; 
int a[10];
int n,i;

do { 
		system ("cls");
			printf("Convert Decimal to Binary program.\n");
		do {
			printf("	Enter a positive number: ");    
			scanf("%d",&n);
		}while (n<0);
		for(i=0;n>0;i++)    
		{    
			a[i]=n%2;    
			n=n/2;    
		}    
		printf("	Binary number: ");    
		for(i=i-1;i>=0;i--)    
		{    
			printf("%d",a[i]);  
		} 
		printf("\nPress any key to do another conversion.\n");
		printf("\n\n"); 
	
	}
	while (c=getch());  
	return 0;
}
