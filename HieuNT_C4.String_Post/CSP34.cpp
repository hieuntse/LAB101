#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input(char str[])
{
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    printf("\nThe old string: %s", str);
}

void process(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) != 0)
        {
            if (isupper(s[i]) != 0)
            {
                s[i] += 32;
            }
            else if (islower(s[i]) != 0)
            {
                s[i] -= 32;
            }
        }
    }
}

int main()
{
    char s[1000], c;
    do
    {
        input(s);
        process(s);
        printf("\nNew string: %s", strrev(s));
        printf("\nPress enter to continue another , ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}

