#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>


int menu()
{	int choice ;
	printf("\n1- Convert binary numbers to decimal number");
	printf("\n2- Convert octal numbers to decimal number");
	printf("\n3- Convert hexadecimal number convert to decimal number");
	printf("\n4- Exit");
	printf("\nPlease choose number (1 - 4): ");
	scanf("%d",&choice); 
	return choice;
}

void func1(){
	int bin, x, dec=0;
	char c;
	do{
		printf("\nEnter a Binary Value:"); 
		scanf("%d",&bin); 
		for (x=0; bin>0; x++)
		{	 dec+=pow(2,x)*(bin%10);
		 	 bin=bin/10;
		}
		printf("Decimal Equivalent of Binary Number: %d\n", dec);
		dec=0;
		printf("Press enter to continue, Esc to return the main menu"); 
		c=getch();
	}
	while(c!=27);
}

void func2(){
	int x;
	char c;
	do{
    	printf("Enter a Octal value: "); scanf("%o",&x);
    	printf("Decimal Equivalent of Octal Number: %d\n",x);
    	x=0;
		c=getch();
	} while (c!=27);
}

void func3(){
	int n;
	char c;
	do{
		printf("Enter a Hexa value: "); scanf("%x",&n);
		printf("Decimal Equivalent of Hexa Number: %d\n",n);
		n=0;
		c=getch();
	} while (c!=27);
}


int main()
{	
int userChoice;
do 
	{	
	userChoice = menu();
	system("cls"); 
		switch (userChoice)
		{ case 1:
				 func1();
				 system("cls");
		         break; 
                
                 
		  case 2:
		        func2();
		        system("cls");
		  	 	break;
		  
		  case 3:
		        func3(); 
		        system("cls");
		  	    break;
				   
		
		  default: printf("Exit");
		} 
	} 
	while (userChoice>=1 && userChoice <4);
	getchar();
    return 0;
}

