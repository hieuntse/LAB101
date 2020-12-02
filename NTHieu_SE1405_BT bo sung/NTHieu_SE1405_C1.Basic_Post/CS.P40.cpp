#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int menu(){
	int choice;
	printf("\nMENU\n");
	printf("-------------------------------\n");
	printf("1- Quadratic equation\n");
	printf("2- Bank deposit problem\n");
	printf("3- Quit!\n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);
	return choice;
}

void equation(float a, float b, float c){
	float x1, x2;
    float delta = b*b - 4*a*c;
    if(delta<0){
        x1=x2=0.0;
        printf("No solution.");
    }
    else if(delta==0){
        x1 = x2 = -b/(2*a);
        printf("Phuong trinh da cho co nghiem kep x=%.4f",x1);
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta) / (2*a);
        x2 = (-b - delta) / (2*a);
        printf("Phuong trinh da cho co hai nghiem phan biet\nx1=%.4f \nx2=%.4f",x1,x2);
    }
}

void bank(int Deposits, float rates, int months){
	float total;
	total = Deposits*rates*months;	
	printf("Total amounts received %.2f",total);
}

int main(){
	float a,b,c;
    float x1,x2, money,rates;
	int userChoice, numNo;
	int Deposit, months;
	do{	
		userChoice=menu();
		switch(userChoice){
			case 1: 
					do{
        					printf("Nhap a (a!=0): ");
        					scanf("%f",&a);
       						printf("Nhap b: ");
        					scanf("%f",&b);
        					printf("Nhap c: ");
       						scanf("%f",&c);
   					  }
    				while(a==0);
    				equation(a,b,c);
        			break;
    		case 2:printf("Deposit: \n"); 
					scanf("%d",&Deposit);
	
					do{	
						printf("Deposits interest rates(a positive number <= 0.1): \n");
						scanf("%f",&rates);
					} while (rates<0||rates>0.1);
	
					printf("Number of deposit months: ");
					scanf("%d",&months);
					bank(Deposit, rates, months);
					break;
					
			default: printf("Quit!\n");
			
	}
		}while(userChoice>0 && userChoice<3);
		return 0;
}
