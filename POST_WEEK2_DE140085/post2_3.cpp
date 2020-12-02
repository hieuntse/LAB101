#include <stdio.h>
#include <conio.h>
#define max 100

int menu()
{
    int option;
    printf("===============MENU===============");
    printf("\nChoice what you want: ");
    printf("\n1- Add a value");
    printf("\n2- Search a value");
    printf("\n3- Remove the first existence of a value");
    printf("\n4- Remove all existences of a value ");
    printf("\n5- Print out the array ");
    printf("\n6- Sort the array in ascending order ");
    printf("\n7- Sort the array in descending order ");
    printf("\nOthers- Quit");
    printf("\nPlease choice: ");
    scanf("%d", &option);
    return option;
}

void input(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element [%d]= ", i);
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}


void search(int a[], int i){
	int numSearch,check=0;
	printf("Enter an integer number to search: ");
	scanf("%d",&numSearch);
	for(int j=0; j<i; j++){
		if(a[j]==numSearch){
			check=1;
		}	
	}
	if(check==1){
		printf("Element %d found at position: ", numSearch);
		for(int j=0; j<i; j++){
			if(a[j]==numSearch){
				printf("%d\n",j);
			}	
		}
	}
	if(check==0){
		printf("Element %d not found\n",numSearch);
	}
}


void sortAscending(int *a, int n)
{
    int minIndex;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (a[minIndex] > a[j])
                minIndex = j;
        if (minIndex > i)
        {
            int t = a[minIndex];
            a[minIndex] = a[i];
            a[i] = t;
        }
    }
    printf("\nArray after sort: ");
    output(a, n);
}


void sortDsc(int *a, int n)
{
    int minIndex;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (a[minIndex] < a[j])
                minIndex = j;
        if (minIndex > i)
        {
            int t = a[minIndex];
            a[minIndex] = a[i];
            a[i] = t;
        }
    }
    printf("\nArray sorted descending: ");
    output(a, n);
}

int deleteElementEquals(int a[], int *n, int element)
{
    int i;
    for (i = 0; i < *n; i++) 
    {
        if (a[i] == element) 
        {
        
            for (i = i; i < *n - 1; i++)
                a[i] = a[i + 1];
            *n = *n - 1;

            return 1;
        }
    }
    return 0;
}


void deleteOne(int a[], int *n)
{
    int element;
    printf("\nEnter the element to be deleted: ");
    scanf("%d", &element);
    
    if (!deleteElementEquals(a, n, element)) {
        printf("Element %d is not found in the array", element);
    }
    printf("Resultant array after deleted element is: ");
    output(a, *n);
    printf("\n");
}


void deleteAll(int a[], int *n)
{
    int element;
    printf("\nEnter the element to be deleted: ");
    scanf("%d", &element);
    
    while (deleteElementEquals(a, n, element)); 
    printf("\nResultant array after delete all matches elements found is: ");
    output(a, *n);
    printf("\n");
}

int main()
{
    int n, a[max];
    int choice;
    do
    {
        printf("How many elements which will be used : ", max);
        scanf("%d", &n);
    } while (n < 1 || n > max);
    printf("Enter %d values of the arrays: \n", n);
    input(a, n);
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: 
            printf("Value: ");
            scanf("%d", &a[n]);
            n++;
            break;
        case 2: 
            search(a,n);
            break;
        case 3: 
            deleteOne(a, &n);
            break;
        case 4: 
            deleteAll(a, &n);
            break;
        case 5:
            printf("Element of array: ");
            output(a, n);
            printf("\n");
            break;
        case 6: 
            sortAscending(a, n);
            printf("\n");
            break;
        case 7: 
            sortDsc(a, n);
            printf("\n");
        default:
            break;
        }
    } while (choice > 0 && choice < 8);
    getch();
    return 0;
}
