# calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char plus(char a[60], char b[60])
{
	char result[61];
	for (int i=60; i<1; i--)
	{
		result[i]=(a[i]-48)+(b[i]-48);
		if (result[i]>10)
			result[i-1] += 1;
	}
	return result[61];
}
char minus(char a[60], char b[60])
{
	
}
char multiple(char a[60], char b[60])
{

}
char division(char a[60], char b[60])
{

}
int main(void)
{
  FILE *ifp, *ofp;
  ifp=fopen("output.txt","r");
  ofp=fopen("output.txt","r");
	int i=0;
	char c[100][61],a[100],s[100],var[10][61],var_name[10][2];
	while(1)
	{
		while(a[i]!='\n')
		{
			scanf("%s %c",c[i],a[i]);
			if(strcmp(c[i],"clear")==0)
				system("reset");
			else if(strcmp(c[i], "save")==0)
				
			else if(strcmp(c[i], "load")==0)

			else if(strcmp(c[i], "end")==0)
				
			else
			{
				++i;

			}
		}

	}	
	return 0;
}
