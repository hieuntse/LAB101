#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define maxn 100

char names[100][50];
int menu(){
	int choice;
	printf("\n==========Student Management==========\n");
	printf("\n**************************************\n");
	printf("1 - Add a student.\n");
	printf("2 - Remove a student.\n");
	printf("3 - Search a student.\n");
	printf("4 - Print list student in a ascending folder.\n");
	printf("5 - Exit.\n");
	printf("****************************************\n\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}

void output(char s[][31], int n)
{
	int i;
	printf("Total student: %d\n",n);
    for (i = 0; i < n; i++){
        printf("%d.%s \n", i, s[i]);
    }
        
}

void input(char s[][31], int *n)
{
    int ok;
    char name[31];
        printf("Enter new student name:");
        fflush(stdin);
        scanf("%30[^\n]", name);
        strcpy(s[*n], name);
        (*n)++;
    printf("Student has been added to list successfully!\n");    
}



int findPos(char name[], char s[][31], int n)
{
	int i;
    for (i = 0; i < n; i++)
        if (strcmp(s[i], name) == 0)
            return i;
    return -1;
}
void find(char name[], char s[][31], int n)
{
    int pos = findPos(name, s, n);
    if (pos >= 0)
        printf("Name '%s' found at position %d\n", s[pos], pos);
    else
        printf("Student name doesn't exist in list! \n");
}
void rm(char name[], char s[][31], int *n)
{
    int pos = findPos(name, s, *n);
    if (pos >= 0)
    {
    	int i;
        printf("Name '%s' found at position %d\n", s[pos], pos);
        for (i = pos; i < (*n - 1); i++)
            strcpy(s[i], s[i + 1]);
        (*n)--;
        printf("Student name has been removed from list successfully!\n");
        printf("After deleting: \n");
        output(s, *n);
    }
    else
        printf("Student name doesn't exist in list! \n");
}
void swap(char a[], char b[])
{
    char t[31];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void sort(char s[][31], int n)
{
	int i,j;
    for ( i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(s[i], s[j]) > 0)
                swap(s[i], s[j]);
    printf("After sorting in ascending order: \n");
    output(s, n);
}

int main()
{
    int option, n = 0;
    char s[maxn][31], name[31];
    do
    {
        option=menu();
        switch (option)
        {
        case 1:
            input(s, &n);
            break;
        case 2:
            printf("Enter students name to remove: ");
            fflush(stdin);
            scanf("%30[^\n]", name);
            rm(name, s, &n);
            break;
        case 3:
            printf("Enter student name to search: ");
            fflush(stdin);
            scanf("%30[^\n]", name);
            find(name, s, n);
            break;
        case 4:
            fflush(stdin);
            sort(s, n);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Exit\n");
            break;
        }
    } while ((option >= 1) && (option <= 5));
    getch();
    return 0;
}

