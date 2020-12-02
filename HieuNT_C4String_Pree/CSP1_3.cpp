#include <stdio.h>
#include <string.h>
#include <conio.h>

void inputString(char a[]){
	printf("Input the string: ");
	gets(a);
	printf("The old string: ");
	puts(a);
}

void reversed(char a[]){
	int i;
	printf("The reversed string: ");
	for (i= strlen(a); i>=0; i--){
		if (a[i]=='_'){
			a[i]=NULL;
			printf("%s_", &a[i]+1);
		}
	}
	printf("%s\n",a);
}

int main(){
	char a[50];
	char c;
	do{
		inputString(a);
		reversed(a);
		printf("\nPress anykey to continue, Esc to exit.\n");
		c=getch();
	} while (c!= 27);
}
