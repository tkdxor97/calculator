#include <stdio.h>
#include <string.h>
void array(char a[63], char b[63])		// array 함수
{
	int i, j, n=1;
	for(i=0; i<strlen(a); ++i)
	{
		if(a[i]=='.')
		{
			b[50]=a[i];
			for(j=i+1; j<strlen(a); ++j)
			{
				b[50+n]=a[j];
				++n;
			}
			b[j]='\0';
			n=1;
			for(j=i-1; j>=0; --j)
			{
				b[50-n]=a[j];
				++n;
			}
			for(j=50-i-1; j>=0; --j)
				b[j]=' ';
			return;
		}
	}
	n=1;
	for(i=strlen(a);i>=0;--i)
	{
		b[50-n]=a[i];
		++n;
	}
	for(i=0; i>n; ++i)
		b[i]=' ';
	return;
}
int main(void)
{
	char a[63]="555555.12323432";
	char b[63]="123124999999.123125  ";
	char c[63]={};
	char d[64]={};
	char e[63]={};
	char f[63]={};

	array(a, e);
	array(b, f);

	printf("%s\n", e);
	printf("%s\n", f);
	printf("%d\t%d\n", strlen(e), strlen(f));

	for (int i = 62; i >= 0; i--)    //계산
	{
		if (e[i]==' '&& (f[i]>='0'&&f[i]<='9')) 
			c[i] = (e[i]-' ')+(f[i]-'0');
		else if (f[i]==' '&& (e[i]>='0'&&e[i]<='9'))
			c[i] = (e[i]-'0')+(f[i]-' ');
		else
			c[i] = (e[i]-'0')+(f[i]-'0');
	}
	for (int i = 62; i >= 0; i--)   //올림
	{
		if (c[i]>9)
		{
			c[i] -= 10;
			c[i-1]++;
		}
		c[i] += '0';      //문자로 바꾸기
		if ((e[i]=='.'||f[i]=='.')) //소수점 찍기
			c[50] = '.';
	}
	printf("%s\n", c);
	return 0;
}
