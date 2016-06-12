#include <stdio.h>
#include <string.h>
void array(char a[62], char b[62])      //ARRAY 함수 INPUT a , OUTPUT b
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
	char a[62]="12341234.";
	char b[62]="1254124982345.";
	char c[62]={};
	char e[62]={};
	char f[62]={};
	array(a, e);
	array(b, f);

	printf("%s\n", e);
	printf("%s\n", f);
	printf("%d\t%d\n", strlen(e), strlen(f));
	
	for (int i=61;i >= 0; i--)
	{
		if (strcmp(e,f) > 0)		//a가 b보다 클때
		{
			if (f[i]==' '&& (e[i]>='0'&&e[i]<='9'))
				c[i] = (e[i]-'0')-(f[i]-' ');
			else
				c[i] = (e[i]-'0')-(f[i]-'0');
		}
		else if (strcmp(e,f) < 0)	//a가 b보다 작을 때
		{
			if (e[i]==' '&& (f[i]>='0'&&f[i]<='9'))
				c[i] = (f[i]-'0')-(e[i]-' ');
			else
				c[i] = (f[i]-'0')-(e[i]-'0');
		}
	}
	for (int i=61; i >= 0; i--)
	{
		if (c[i] < 0)
		{
			c[i] += 10;
			c[i-1]--;
		}
		c[i] += '0';
		if ((e[i]=='.'||f[i]=='.'))
			c[50] = '.';
	}
	if (strcmp(e, f) < 0)
	{
		c[0] = '-';
	}
	printf("%s\n", c);
	return 0;	
}
void minus(char a[62], char b[62], char result[63])
{
	char c[62]={};
	char e[62]={};
	char f[62]={};
	int i;
	array(a, e);
	array(b, f);
	printf("%d %d",strlen(e), strlen(f));
	if(strlen(e)>strlen(f))
	{
		for(i=strlen(f); i<strlen(e); ++i)
			f[i]=' ';
		f[i]='\0';
	}
	else if(strlen(f)>strlen(e))
	{
		for(i=strlen(e); i<strlen(f); ++i)
			e[i]=' ';
		e[i]='\0';
	}
	printf("%s\n%s\n", f,e);
	for (int i=61;i >= 0; i--)
	{
		if (strcmp(e,f) > 0)
		{
			if (e[i]==' '&& (f[i]>='0'&&f[i]<='9'))
				c[i] = (e[i]-' ')-(f[i]-'0');
			else if (f[i]==' '&& (e[i]>='0'&&e[i]<='9'))
				c[i] = (e[i]-'0')-(f[i]-' ');
			else
				c[i] = (e[i]-'0')-(f[i]-'0');
		}
		else if (strcmp(e,f) < 0)
		{
			if (f[i]==' '&& (e[i]>='0'&&e[i]<='9'))
				c[i] = (f[i]-' ')-(e[i]-'0');
			else if (e[i]==' '&& (f[i]>='0'&&f[i]<='9'))
				c[i] = (f[i]-'0')-(e[i]-' ');
			else
				c[i] = (f[i]-'0')-(e[i]-'0');
		}
	}
	for (int i=61; i >= 0; i--)
	{
		if (c[i] < 0)
		{
			c[i] += 10;
			c[i-1]--;
		}
		c[i] += '0';
		if ((e[i]=='.'||f[i]=='.'))
			c[50] = '.';
	}
	for (int i = 0; i <= 63; i++)
		result[i+1] = c[i];
	if (strcmp(e, f) < 0)
		result[0] = '-';
	
	return;
}
