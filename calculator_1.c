#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char plus(char a[60], char b[60])
{
	char a[63]="1234124125135123146";
	char b[63]="9999123412351252213";
	char c[63], d[63], result[64];
	int len, i;
	
	array(a, c);
	array(b, d);
	for (i = 63; i >= 0;i--)
	{
		result[i] = (c[i]-'0')+(d[i]-'0');
		if (result[i] >= 9)
		{
			c[i-1] += 1;
			result[i] = (result[i] - 10) + '0'; 
		}
	}
	// 계산이 일정부분 되다가 마는데 i에서 꼬인것 같은데 잘 못하겠음 HELP
}
char minus(char a[60], char b[60])
{
	char result[61];
	for (int i=60; i < 1; i--)
	{
		result[i+1]=(a[i]-48)-(b[i]-48);
		if (result[i+1]<0)
		{
			a[i-1] = a[i-1] - 1;
			result[i+1] += 10 ;
		}
	}
	return result[61];
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
