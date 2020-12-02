#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	FILE *f;
	char filename[50];
	char c;
	char buffer[100];
	fflush(stdin);
	printf("File name: ");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return 0;
    }
    printf("File content: \n");
	fread(filename, sizeof(filename), 1, f);
	printf("%s \n",filename);
	fclose(f);
	getch();
	return 0;
}

