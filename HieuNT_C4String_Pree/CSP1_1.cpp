#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char *a;
  a=(char *)calloc(99, sizeof(char));
  printf("Nhap chuoi: ");
  fflush(stdin);
  gets(a);
  printf("The old string: %s\n", a);
  printf("\nNew string: %s", strrev(a));
  
  printf("\nAnother reservered string: ");
  char *p=strstr(a,"_");
  while (p!= NULL){
  	*p= '\0';
  	printf("%s_",strrev(a));
  	a=p+1;
  	p=strstr( a,"_");
  } 
  printf("%s",strrev(a));
  return 0;
}
