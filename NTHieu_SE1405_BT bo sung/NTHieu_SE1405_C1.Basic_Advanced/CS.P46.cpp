#include <stdio.h>
#include <math.h>
#define max 100
int menu(){
	int choice;
	printf("\n1- The first primes\n");
	printf("2- Fibonacci element\n");
	printf("3- Sum of digits\n");
	printf("Choose an option: ");
	scanf("%d",&choice);
	return choice;
}

int isPrimeNumber(int n){
	if (n<0){
		return 0;
	}
	int i;
	int sq= sqrt(n);
	for (i=2; i<= sq; i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

int func1(int n){
	int dem=0;
	int i=2;
	while (dem<n){
		if(isPrimeNumber(i)){
			printf("%d  ",i);
			dem++;
		}
		i++;
	}
	
}

int func2(int n){
	int t1=1, t2=1, f=1;
	if (n==1) return 1;
	while (f<n)
	{ f=t1+t2;
		t1=t2;
		t2=f;
	} 
	return n==f;
}

int sum(int n){
	int i,sum=0;
	while(n!=0) {
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
	int userChoice;
	int n;
	do
	{	
		userChoice= menu();
		switch(userChoice){
			case 1: 
			    do{
					printf("Number of primes: ");
			    	scanf("%d",&n);
			    	fflush(stdin);
				} while (n<0||n>=50);
				func1(n);
				break;
			
			case 2:
				do{	
					printf("Number tested: ");
					scanf("%d",&n);
					fflush(stdin);
				} while (n<0|| n>=1000);
				if (func2(n)==1) printf("It is a Fibonacci element");
				else printf("It is not a Fibonacci element");
				break;
			
			case 3:
			do {
				printf("Enter an integer: ");
				scanf("%d",&n);
			} while(n<0);
			printf("Sum of it's digits: %d",sum(n));
			break;	
			default: printf("Quit.\n");
		}
	} while (userChoice>0 && userChoice<4);
	return 0;
}
