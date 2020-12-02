#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<conio.h>

void check(int n)
{
    double temp = sqrt(n);

    if ((pow((int)temp, 2) == n) && (n != 0))
    {
        printf("%d is a square number ", n);
        printf("%d = %d x %d\n", n, (int)temp, (int)temp);
    }
    else
        printf("%d is not a square number !\n", n);
}
int main()
{
    char c;
    int n;
    do{
    	
    	while(n)
    	{	
    		printf("Check Square Number Program \n");
        	printf("Enter a positive number(0 to exit): ");
        	scanf("%d", &n);
        	if (n < 0)
            	printf("Please input a possitive number\n");
        	if (n > 0)
            check(n);
       			 printf("Press any key to continue.\n\n");
    		
		 getch();
		}	
    }	
	while(c=getch());
    return 0;
}

