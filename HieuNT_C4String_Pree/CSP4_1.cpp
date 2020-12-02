#include <stdio.h>
#include <conio.h>
#include <string.h>
#define maxn 100

typedef char string[maxn];

void process(string s1, int n){
	char s2[2*n];
	int i,j, dup;
	for(i=0; i<n; i++){
		if (s1[i]==' '){
			continue;
		}
		s2[2*i]=s1[i];
		s2[2*i+1]=49;
		dup=0;
		for (j=i-1; j>=0;j--){
			if(s1[i]==s2[2*j]){
				s2[2*i+1]= s2[2*j+1]+1;
				s2[2*j+1]= 'x';
				dup= 1;
				break;
			}
		}
	}
	
	printf("Times of appearance for each character: \n");
	for (i= n-1; i>=0; i--)
		if (s2[2*i+1] != 'x') printf("%c\t",s2[2*i]);
		printf("\n");
		int max= '0', imax;
		for (i= n-1; i>=0; i--)
			if (s2[2*i+1] !='x'){
				printf("%c\t",s2[2*i+1]);
				if (s2[2*i+1]>max){
					max= s2[2*i+1];
				}
			}
	printf("\n_________________________________________________________________\n");
	printf("Characters that apear the most: \n");
	for (i=n-1; i>=0; i--)
		if(s2[2*i+1] >=max&& s2[2*i+1]!='x')
			printf("%c\t",s2[2*i]);
	printf("\n");
	for (i=n-1; i>=0; i--)
		if (s2[2*i+1] >=max&& s2[2*i+1]!='x') 
			printf("%c\t",s2[2*i+1]);
	
}

int main(){
	string s1;
	int c;
	do{
		printf("Enter a string: ");
		fflush(stdin);
		gets(s1);
		int n=strlen(s1);
		process(s1,n);
        printf("\nPress any key to continue! Press ESC to exit!\n");
        c = getch();
	} while (c!= 27);
	
}

