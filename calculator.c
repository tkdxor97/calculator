#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Input(char a[1000])	//???낅젰
{
	char aa[1000],c;
	int i=0;
	gets(aa);
	for(int j=0; j<strlen(aa);++j)
	{
		c=aa[j];
		if(c!=' ' && c!='\0')
		{
			a[i]=c;
			++i;
		}
	}
	a[i]='\0';
	return;
}
char cut(char a[100][63], char b[100], char input[1000])	//?レ옄? ?곗궛??遺꾨━
{
	int k=0, j=0, n=1;
	for(int i=1; i<strlen(input); ++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%')
		{
			if(input[i-1]>='0' && input[i-1]<='9')
			{
				k=i;
				b[0]=input[i];
				break;
			}
		}
	}
	for(int i=0; i<k; ++i)
		a[0][i]=input[i];

	for(int i=k+1; i<strlen(input);++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%')
		{
			if(input[i-1]>='0' && input[i-1]<='9')
			{
				b[n]=input[i];
				for(int j=k+1; j<i; ++j)
					a[n][j-k-1]=input[j];
				++n;
				k=i;
			}
		}
	}
	for(int i=k+1; strlen(input); ++i)
	{
		a[n][i-k-1]=input[i];
	}
	++n;
	return n;
}
void array(char a[63], char b[63])		//a : ?먮옒 ?レ옄, b : 諛곗뿴???レ옄
{
	strcpy(b,"");
	int i, j, n=1, s=0;
	for(i=0; i<strlen(a); ++i)
	{
		if(a[i]=='.')
		{
			s=1;
			b[50]=a[i];
			for(j=i+1; j<strlen(a); ++j)
			{
				b[50+n]=a[j];
				++n;
			}
			b[50+n]='\0';
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
	if(s==0)
	{
		b[50]='\0';
		for(i=strlen(a);i>0;--i)
		{
			b[50-n]=a[i-1];
			++n;
		}
		for(i=0; i<=50-n; ++i)
			b[i]=' ';
	}
	return;
}
void comma(char result[63])
{
	int i = 0, l, k;
	l = strlen(result);
	for(int i = 0; i < l; ++i)
	{
		if(result[i] == '.')
			k= i - 1;
	}
	for(int i = 0; i <= k; ++i)
	{
		printf("%c", result[i]);
		if((i + 1) % 3 ==(k + 1) % 3 && i !=k)
			printf(",");
	}
	for(int i = k + 1; i < l; ++i)
	{
		printf("%c", result[i]);
		if((i - k) != 1 && ((i - k) % 3 == 1) && i != l-1)
			printf(",");
	}
}
void save(char var_name[10], char var[10][63], int var_number)
{
	FILE *ofp;
	ofp=fopen("data.txt","w");
	for(int i=0; i<var_number; ++i)
		fprintf(ofp,"%c %s ",var_name[i], var[i]);
	fclose(ofp);
}
int load(char var_name[10], char var[10][63])
{
	int var_number=0;
	int c;
	FILE *ifp;
	ifp=fopen("data.txt","r");
	while(c!=EOF)
	{
		fscanf(ifp,"%c %s",&var_name[var_number], &var[var_number]);
		c=getc(ifp);
		++var_number;
	}
	fclose(ifp);
	--var_number;
	return var_number;
}
void plus(char a[62], char b[62], char result[63])
{
	char c[62]={};
	char e[62]={};
	char f[62]={};

	array(a, e);
	array(b, f);
	printf("\n%s\n%s",e,f);

	for (int i = 60; i >= 0; i--)
	{
		if ((f[i]>='0'&&f[i]<='9')&&(e[i]>='0')&&(e[i]<='9'))
		{
			c[i] = (e[i]-'0')+(f[i]-'0');
		}
		else 
		{
			if (f[i]>='0'&&f[i]<='9')
				c[i] = (f[i]-'0');
			else if (e[i]>='0'&&e[i]<='9')
				c[i] = (e[i]-'0');
			else
				c[i] = 0;
		}
	}
	for (int i = 60; i >= 0; i--)
	{
		if (c[i]>9)
		{
			c[i] -= 10;
			c[i-1]++;
		}
		c[i] += '0';
		if ((e[i]=='.'||f[i]=='.'))
			c[50] = '.';
	}
	for (int i = 0; i <= 63; i++)
		result[i] = c[i];
	while (result[1]=='0')
		for(int i=2; i<strlen(result); ++i)
			result[i-1]=result[i];
	if (result[0]=='0')
		for (int i=1; i< strlen(result);++i)
			result[i-1]=result[i];
	for(int i=strlen(result)-1;i>0;--i)
	{
		if(result[i]=='0')
			result[i]='\0';
		else
			break;
	}
	return ;
}
void minus(char a[62], char b[62], char result[63])
{
	char a2[63], b2[63];
	int i,c[63]={0},sw;		//sw=1 : a-b?옜, sw=0 : a-b?옜
	array(a,a2);
	array(b,b2);
	if(strlen(a2)>strlen(b2))
	{
		for(i=strlen(b2);i<strlen(a2);++i)
			b2[i]='0';
		b2[i]='\0';
	}
	else if(strlen(a2)<strlen(b2))
	{
		for(i=strlen(a2); i<strlen(b2); ++i)
			a2[i]='0';
		a2[i]='\0';
	}
	for(int i=0; i<60; ++i)
	{
		if(a2[i]==' ')
			a2[i]='0';
		if(b2[i]==' ')
			b2[i]='0';
	}
	for(int i=0; i<60; ++i)
	{
		if(a2[i]>b2[i])
		{
			sw=1;
			break;
		}
		else if(b2[i]>a2[i])
		{
			sw=0;
			break;
		}
	}
	printf("%s\n%s\n",a2,b2);
	if(sw==1)
		for(int i=0; i<strlen(a2); ++i)
			c[i]=(a2[i]-'0')-(b2[i]-'0');
	else if(sw==0)
		for(int i=0; i<strlen(a2); ++i)
			c[i]=(b2[i]-'0')-(b2[i]-'0');
	for(int i=59; i>51; --i)
		if(c[i]<0)
		{
			c[i]+=10;
			--c[i-1];
		}
	if(c[51]<0)
	{
		c[51]+=10;
		--c[49];
	}
	for(int i=49; i>0; --i)
		if(c[i]<0)
		{
			c[i]+=10;
			--c[i-1];
		}
	for(int i=0; i<60; ++i)
		printf("%d %d\n",i,c[i]);
/*	for(int i=0; i<60; ++i)
		result[i+1]=c[i]+'0';
	result[51]='.';
	result[61]='\0';
	printf("%s",result);*/

}
void multiple(char a[63], char b[63], char result2[63])
{
	char a2[63], b2[63];
	int result[73]={0}, k=0, s;
	array(a,a2);
	array(b,b2);
	for(int i=51; i<60; ++i)
	{
		a2[i-1]=a2[i];
		b2[i-1]=b2[i];
	}
	a2[strlen(a2)-1]='\0';
	b2[strlen(b2)-1]='\0';
	for(int i=strlen(b2);i>0;--i)
	{
		if(b2[i]>='0' && b2[i]<='9')
		{
			for(int j=0; j<strlen(a2); ++j)
			{
				if(a2[j]>='0' && a2[j]<='9')	
					result[i-(49-j)]+=(b2[i]-'0') * (a2[j]-'0');
			}
		}
	}
	if(result[0]>=10)
	{
		printf("error\n");
		return;
	}
	for(int i=73; i>0; --i)
	{	
		if(result[i]>=10)
		{
			result[i-1]+=(result[i]-(result[i]%10))/10;
			result[i]=result[i]%10;
		}
	}
	for(int i=0; i<50; ++i)
	{
		if(result[i]!=0)
		{
			k=i;
			break;
		}
	}
	for(int i=k; i<50; ++i)
		result2[i-k]=result[i]+'0';
	for(int i=51; i<60; ++i)
	{
		if(result[i-1]!=0)
		{
			s=1;
			break;
		}
	}
	if(s==1)
	{
		result2[50-k]='.';
		for(int i=50; i<59; ++i)
			result2[i-k+1]=result[i]+'0';
	}
	return;
}
/*void divide(char a[63], char b[63], char result[63])
{
	char a2[63], b2[63], c[63];
	int s[63]={0},sw=0;
	for(int j=0; j<200; ++j)
	{
		printf("%s %s\n",a,b);
		array(a,a2);
		array(b,b2);
		if(strcmp(a2,b2)<0)
		{
			for(int i=60; i>=51; --i)
			{
				b[i+1]=b[i];
			}
			b[51]=b[49];
			for(int i=48; i>=0; --i)
			{
				b2[i+1]=b[i];
			}
		}
		else if(strcmp(a2,b2)>0)
		{
			minus(a,b,c);
			strcpy(a,c);
			s[49]++;
			for(int i=58; i>0; --i)
			{
				if(s[i]>=10)
				{
					++s[i-1];
					s[i]-=10;
				}
			}
			if(s[59]!=0)
				break;
		}
		if(strcmp(a2,b2)==0)
		{
			s[49]++;
			break;
		}
	}
	for(int i=0; i<50; ++i)
		result[i]=s[i]+'0';
	result[50]='.';
	for(int i=50; i<59; ++i)
		result[i+1]=s[i]+'0';
	printf("%s",result);
}*/
int main()
{
	char input[1000];
	char number[100][63], operator[100];
	char var_name[10], var[10][63], result[63];
	int var_number=0, n, plus_minus[100]={0};//plus_minus : ?묒닔/?뚯닔 援щ텇(?묒닔 : 0, ?뚯닔 : 1)
	printf("%s",result);
	strcpy(var[0],"240.052");
	strcpy(var[1],"2.5");
	minus(var[0],var[1],var[2]);
	while(1)
	{
		Input(input);
		if(strcmp(input,"clear")==0)
			system("clear");
		else if(strcmp(input,"end")==0)
			exit(1);
		else if(strcmp(input,"save")==0)
			save(var_name, var, var_number);
		else if(strcmp(input,"load")==0)
			var_number=load(var_name, var);
		else if(strcmp(input,"VAR")==0)
		{
			for(int i=0; i < var_number; ++i)
			{
				printf("%c %s\n",var_name[i], var[i]);
			}
		}
		else if(input[1]=='=')
		{
			var_name[var_number]=input[0];
			for(int i = 2; i < strlen(input); ++i)
				var[var_number][i-2]=input[i];
			++var_number;
		}
		else
		{
			printf("%s\n",input);
			n=cut(number,operator,input);
			for(int i=0; i<n; ++i)	//?レ옄 蹂?섏쓽 留⑥븵??'-'?대㈃ plus_minus媛믪쓣 1濡?諛붽씔???レ옄 蹂?섏뿉 '-'瑜??놁븻??
			{
				if(number[i][0]=='-')
				{
					plus_minus[i]=1;
					for(int j=1; j<strlen(number[i]); ++j)
						number[i][j-1]=number[i][j];
					number[i][strlen(number[i])-1]='\0';
				}
			}
			for(int i=0;i<n;++i)
				printf("%d %s\n",plus_minus[i], number[i]);
			for(int i=0;i<n-1;++i)
				printf("%c\n",operator[i]);
		}
	}
}
