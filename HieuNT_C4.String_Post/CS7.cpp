#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

void RemoveLeft(char s[])
{
    int i = 0, j;
    while (s[i] == ' ')
    {
        if (s[i] == ' ')
        {
            for (j = i; j < strlen(s); j++)
            {
                s[j] = s[j + 1];
            }
        }
    }
}
void RemoveRight(char s[])
{
    int i = strlen(s) - 1, j;
    while (s[i] == ' ')
    {
        if (s[i] == ' ')
        {
            s[i] = s[i + 1];
            i--;
        }
    }
}
void RBetween(char s[])
{
    int i, j;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            strcpy(&s[i], &s[i + 1]);
            i--;
        }
    }
}
int main()   
{
    char c, st[1000];
    int x;
    do
    {
        do
        {
        	x=1;
            printf("Enter an string: ");
            fflush(stdin);
            gets(st);
            for (int i = 0; i < strlen(st); i++)
            {
                if ((st[i] == '@') || (st[i] == '#') || (st[i] == '!') || (st[i] == '[') || (st[i] == ']') || (st[i] == '{') || (st[i] == '}') || (st[i] == '(') || (st[i] == ')'))
                {
                    printf("The string has special characters!!! Please enter agian!\n");
                    x = 0;
                }
            }
        } while (x != 1);
        RemoveLeft(st);
        RemoveRight(st);
        RBetween(st);
        printf("The string after removing: ");
        puts(st);
        printf("\nPress enter to continue another reverse, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
