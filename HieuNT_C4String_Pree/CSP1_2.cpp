#include <stdio.h>
#include <string.h>

int main(){
	int index= 0;
	int i;
	char a[50];
	char b[10][10];
	char *p;
	printf("Input the string: ");
	gets(a);
	printf("The old string: %s\n", a);
	p= strtok(a,"_");//cat chuoi bang ki tu _
	while (p!= NULL){
		strcpy(b[index], p);
		index++;
		p= strtok(NULL, "_");//cat chuoi tu vi tri dung lai truoc do
		
	}
	printf("The reserved string: ");
	for (i= index-1; i>0; i--)// display reserved string
			printf("%s_",b[i]);
	printf("%s", b[i]);
	
	return 0;
}
