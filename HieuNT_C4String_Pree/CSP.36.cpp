#include <stdio.h>
#include <conio.h>	
#include <string.h>
#include <ctype.h>

//input string
void input(char a[]){
	printf("Enter a string: ");
    fflush(stdin);
    gets(a);
}

//Use isalpha to check if a character is a letter (ctype.h)
int checkinput(char a[]){
	for(int i=0;i<strlen(a);i++){
		if(isalpha(a[i])) {
	    	return 1;
	   } else {
	    	return 0;
	   }
	}
}

//check if a letter is uppercase and Convert uppercase to lowercase
void toLower(char a[]){
	int i;
  	for (i = 0; i < strlen(a); i++)
        {
            if (a[i] >= 65 && a[i] <= 90)
                a[i] += 32;
        }
}

void lookUp(char a[],int num[],int &count){
	count=0;
    for(int i=0;i<26;i++){
		num[i]=0;
	}
	for(int i=0;i<strlen(a);i++) {
		if(a[i]>='a' && a[i]<='z') {
			num[(int)a[i]-'a']++;
		}
	}
    
}
void display(int num[]){ 
    for(int i=0;i<26;i++){
		if(num[i]!=0)
		printf(" %c : %d \n",(char)(i+'a'),num[i]);
	}
}

int main(){
    char a[50],b[50];
    int num[50],count;
    char c;
    do{
        input(a);
        checkinput(a);
        toLower(a);
        lookUp(a,num,count);
        display(num);
        printf("\nPress Enter to continue! Press ESC to exit!\n");
        do{
        	c=getch();
        	if (c ==13) break;
        	else if (c==27) return 1;
    	} while(1);
   	}while(1);
}


 
