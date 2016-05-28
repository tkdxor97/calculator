#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char plus(char a[60], char b[60])
{
	
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
char mod(char a[60], char b[60])
{

}
int main(void)
{
	int k=0, l=0, i, j, var_number=0;
	char aa[10000],c[100][61],a[100],s[100],var[10][61],var_name[10][2];
	while(1)
	{
		
		//숫자와 연산자 읽어들이기
	
		gets(aa);
		for(i=0;i<strlen(aa);++i)
		{
			if(aa[i]=='+' || aa[i]=='-' || aa[i]=='*' || aa[i]=='/' || aa[i] == '%')
			{
				if(k==0)
				{
					for(j=0;j<i-1;++j)
					{
						c[k][j]=aa[j];
					}
					l=i;
					a[k]=aa[i];
					++k;
				}
				else
				{
					for(j=l+2;j<i-1;++j)
					{
						c[k][j-l-2]=aa[j];
					}
					l=i;
					a[k]=aa[i];
					++k;
				}
			}
		}
		for(i=l+2;i<strlen(aa);++i)
		{
			c[k][i-l-2]=aa[i];
		}
		++k;

	}
}
