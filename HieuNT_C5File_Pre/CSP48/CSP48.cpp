#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(){
	FILE *f;
	char filename[50];
	char c[50];
	printf("=============================Text management===========================\n");
	printf("Enter file name to save the content: ");
	fflush(stdin);
	gets(filename);
   	f = fopen(filename, "a+");
   		printf("Enter content: ");
    	fflush(stdin);
    	gets(c);
        fwrite(c,strlen(c)+1, 1,f);
        fseek(f, SEEK_SET, 0);
  	printf("\n File content: \n");
    	fread(filename, sizeof(filename), 1, f);
		printf("%s \n",filename);
	fclose(f);
	getch();
    return 0;
}
