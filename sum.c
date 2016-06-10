#include <stdio.h>
#include <string.h>
/*void array(char a[63], char b[63])		//a : 원래 숫자, b : 배열한 숫자
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
}*/
int main(void)
{
	char a[63]="555555555";
	char b[63]="\0\0\0999999";
	char c[63]={};
	char d[64]={};
	char e[63]={};
	char f[63]={};

//	array(a, e);
//	array(b, f);

//	printf("%s\n", e);
//	printf("%s\n", f);

	for (int i=0; i<strlen(c) ; i++)
		d[i+1]=c[i];

	for (int i = 62; i >= 0; i--)
	{
		int A,B,C;
		if (a[i]== 0)
			c[i] = (a[i])+(b[i]-'0');
		else if (b[i]== 0)
			c[i] = (a[i]-'0')+(b[i]);
		else
			c[i] = (a[i]-'0')+(b[i]-'0');
		d[i+1]= c[i];
	}
	for (int i = 62; i >= 0; i--)
	{
		if (d[i]>9)
		{
			d[i] -= 10;
			d[i-1]++;
		}
		d[i] += '0';
	}
	printf("%s\n", d);
	return 0;
}
