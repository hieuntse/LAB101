#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
int fi;


typedef struct Item
{
	int ID;
	char name[50];
	float cost;
	char category[5];
} Item;

 Item List[MAX];
 
 int isExists(char filename[]){
 	FILE *fp;
 	fp= fopen(filename, "r+");
 	if (fp!= NULL){
 		fclose(fp);
 		return 1;
	 }
	 else
	 {
	 	fclose(fp);
	 	return 0;
	 }
 }
 
 void Addnew (int x){
 	int status = TRUE;
 	int i;
 	printf("What is the ID number of the item to add?\n");
 	scanf("%d",&List[x].ID);
 	printf("What is the name if item to be add?\n");
 	fflush(stdin);
	scanf("%s",List[x].name);
	printf("What is the cost of the item to be add?\n");
	scanf("%f",&List[x].cost);
	printf("What is the product category of the item to be added?\n");
	fflush(stdin);
	scanf("%s",&List[x].category);
	for(i=0; i<fi; i++){
		if (List[x].ID == List[i].ID){
			printf("\nSorry, an item with ID number %d is already in database. ",List[x].ID);
			status = FALSE;
			break;
		}
	}
	if(status == TRUE) {
			printf("%s has been added in database. \n",List[x].name);
			fi++;
	}
}

void loadData(char filename[]){
	int i;
	FILE *f= fopen(filename,"r");
	if (f== NULL){
		fflush(stdin);
		printf("Can not open this file!\n");
		return ;
	}
	for (i=0; i< MAX; i++){
		fscanf(f,"%d %s %f %s",&List[i].ID, List[i].name, &List[i].cost, &List[i].category);
		if (List[i].ID==0 || List[i].name ==NULL){
			fi=i;
			break;
		}	
	}
	printf("%s has been property loaded into the database!\n",filename);
	fclose(f);
}
 
void Del(){
	int i, Local, value, status=0;
	printf("What is the ID number of the product to delete?\n");
	scanf("%d",&value);
	for (i=0; i< fi; i++){
		if (List[i].ID == value){
			Local= i;
			status= TRUE;
			break;
		}
	}
	if (status == TRUE){
		printf("\n%s have been deleted form the database.",List[Local].name);
		for (; Local< fi -1; Local++){
			List[Local]= List[Local +1];
		}
		fi--;
	}
	else 
	{
		printf("\n Sorry, there is no item in the database with that ID number.");
	}
}

void changeCost(){
	int i, value;
	printf("What is the ID number of the item in question?\n");
	scanf("%d", &value);
	for (i=0; i<fi; i++){
		if (List[i].ID== value)
		{
			printf("What is the new price for %s?\n",List[i].name);
			scanf("%f", &List[i].cost);
			printf("%s now costs %f",List[i].name, List[i].cost);
			return;
		}
	}
	printf("Sorry, an item with ID number %f is not in the database.", value);
}

void SearchItem(){
	int i=0;
	char item[20];
	printf("\nWhich item would you like to search for? \n");
	scanf("%s", &item);
	for (i =0; i< fi; i++){
		if (strcmp(item, List[i].name)==0){
			printf("Here is the product information: \n");
			printf("%-6d %-6s %-5.2f %-6s",List[i].ID, List[i].name, List[i].cost, List[i].category);
			return;
		}	
	}
	printf("Sorry, we don't have %s in the store. \n",item);	
}
 
 void display(){
 	int i;
 	printf("Here is a listing of all the products in stock: \n");
 	printf("%-6s %-10s %-15s %-5s","ID", "Product", "Price", "Category");
 	for (i=0; i<fi; i++){
 		printf("\n%-6d %-10s %-15f %-5s",List[i].ID, List[i].name, List[i].cost, List[i].category);
	 }
 }

void Quit(){
	char s[5];
	char filename[20];
	FILE *f;
	do{
		printf("Would you like to save the changes made to the database?\n");
		fflush(stdin);
		scanf("%s",&s);
		s[0]= toupper(s[0]);
	} while (!(s[0] == 'Y') && s[0] == 'N');
	if (strcmp(s, "Y")== 0|| strcmp(s, "Yes")==0)
	{
		printf("What file would you like to save the new database?");
		fflush(stdin);
		gets(filename);
		f = fopen(filename, "w");
        for (int i = 0; i < fi; i++)
            fprintf(f, "%-6d %-10s %-15.2f %-5s\n", List[i].ID, List[i].name, List[i].cost, List[i].category);
        fclose(f);
		printf("The file has been saved. Thanks for shopping!\n");
	}		
}	
	
	
int menu(){
	int choice;
	printf("\n\n________________________________________________________________________________");
	printf("\nPlease make one of the following seclections: \n");
	printf("1. Add new item.\n");
	printf("2. Delete item.\n");
	printf("3. Change the cost of an item.\n");
	printf("4. Search for item.\n");
	printf("5. Display inventory details.\n");
	printf("6. Quit.\n");
	printf("Please choose: ");
	scanf("%d",&choice);
	return choice;
}



int main(){
	int choice;
	char filename[20];
	printf("Welcome to the grocery store!\n");
	do{
		printf("Please input the file you'd like to load into stock.\n");
		fflush(stdin);
		gets(filename);		
		if (isExists(filename)==0)
			printf("This file doesn't exist. Enter again!\n");
	} 	while (isExists(filename)==0);
	loadData(filename);
	do{ 
		choice= menu();
		switch(choice)
		{
			case 1:
				Addnew(fi);
				break;
			case 2:
				Del();
				break;
			case 3:
				changeCost();
				break;
			case 4:
				SearchItem();
				break;
			case 5:
				display();
				break;
			case 6:
				Quit();
				getch();
				exit(1);
		}
		
	} while (choice> 0&& choice<7);
	return 0;
}
