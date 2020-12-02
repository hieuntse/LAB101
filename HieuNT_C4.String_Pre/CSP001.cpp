#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Nhap chuoi cach nhau boi dau " _ " va in ra man hinh
char input (char a[]){
	printf("\nPlease enter string: "); 
	fflush(stdin);
	gets(a);
	printf("The old string: %s\n",a);
	return *a;
}

//Dao nguoc chuoi va in ra man hinh
void reserve (char a[]){
	int i,j;
	printf("The reversed string: ");
		i = strlen(a) - 1;
		while(i >= 0)
		{
			if(a[i] == '_' )
				{
					j = i + 1;
					while(a[j] != '_' && a[j] != '\0') 
    				{
    					printf("%c", a[j]);
    					j++;
    				}
    			printf("_");
    			}
    		else if(i == 0)
    			{
    				j = i;
    				while(a[j] != '_')
    					{
    					printf("%c", a[j]);
    					j++;
    				}
    			}
    		i--;
    	} 
}

int main(){
	char c;
	char a[100];
	do{
		input(a);
		reserve(a);
		printf("\nPress enter to continue another reverse, ESC to exit\n");
		c=getch();
	} while (c != 27);
	return 0;
	
}
