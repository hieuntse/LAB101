#include <stdio.h>
#define MAX 100
//input an array
void input(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element [%d]: ", i);
        scanf("%d", &a[i]);
    }
}

//print out the array
void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
//Sort the array in ascending order and display on the screen
void SortAsc(int *a, int n)
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
    printf("\nThe array sorted ascending: \n");
    print(a, n);
}
//Sort the array in descending order and display on the screen
void SortDsc(int *a, int n)
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
    printf("\nThe array sorted in descending: \n");
    print(a, n);
}

int main()
{
    int n;
    int a[MAX];
    do
    {
        printf("Please enter size of array: ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);
    input(a, n);
 	SortAsc(a, n);
 	SortDsc(a, n);
    getchar();
    getchar();
    return 0;
}
