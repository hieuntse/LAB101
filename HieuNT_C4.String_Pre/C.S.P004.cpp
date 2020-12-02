#include <stdio.h>
#include <conio.h>	
#include <string.h>
void input(char a[]){
	printf("Enter a string: ");
    fflush(stdin);
    gets(a);
}
void lookUp(char a[],char b[],int num[],int &count){
	count=0;
    b[count++]=a[0];
    int i, n=strlen(a);   
    for(int i=1; i<n; i++){
        int x = 0;
        for(int j=0; j<i; j++){
            if(a[i]==a[j]) x++;
        }
    	if (a[i]==' '){
        	continue;
		}
        if(x==0) b[count++]=a[i];     
    }
    
    for(int i=0; i<count; i++){
        num[i]=0;
        for(int j=0; j<strlen(a); j++)
            if(a[j]==b[i]) (num[i])++;
    }
    
     
   
}
void display(char b[],int num[],int &count){
	printf("Time of appearance for each charater: \n"); 
    for(int i=0; i<count; i++) printf("%c\t",b[i]);
    printf("\n");
    for(int i=0; i<count; i++) printf("%d\t",num[i]);
    printf("\n---------------------------------------------------------\n");
    printf("Characters that appear the most: \n");
    int n = num[0];
    for(int i=1; i<count; i++)
        if(num[i]>n) n = num[i];
    for (int i=0; i<count; i++){
        if(num[i]==n) printf("%c\t",b[i]);
    }
     printf("\n");
    for (int i=0; i<count; i++){
    if(num[i]==n) printf("%d\t",num[i]);
	}
}
int main(){
    char a[100],b[100];
    int num[100],count;
    char c;
    do{
        input(a);
        lookUp(a,b,num,count);
        display(b,num,count);
        printf("\nPress Enter to continue! Press ESC to exit!\n");
        do{
        	c=getch();
        	if (c ==13) break;
        	else if (c==27) return 1;
    	} while(1);
   	}while(1);
}

