#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Input(char a[1000])	//식 입력
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
char cut(char a[100][62], char b[100], char input[1000])	//숫자와 연산자 분리
{
	int k=0, j=0, n=1;
	for(int i=1; i<strlen(input); ++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*' || input[i]=='%')
		{
			k=i;
			b[0]=input[i];
			break;
		}
	}
	for(int i=0; i<k; ++i)
		a[0][i]=input[i];

	for(int i=k+1, l=k; i<strlen(input);++i)
	{
		if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*' || input[i]=='%')
		{
			b[n-1]=input[i];
			for(int j=l+1; j<i; ++j)
				a[n][j-l-1]=input[j];
			++n;
			l=k;
			k=i;
		}
	}
	for(int i=k+1; strlen(input); ++i)
	{
		a[n][i-k-1]=input[i];
	}
	++n;
	return n;
}
void array(char a[63], char b[63])		//a : 원래 숫자, b : 재배열한 숫자
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
			break;
		}
	}
	return;
}
char plus(char a[60], char b[60])
{
	char result[61];
	int i;
	for (i=60; i<1; i--)
	{
		result[i+1]=(a[i]-48)+(b[i]-48);
		if (result[i+1]>10)
			result[i] += 1;
	}
	return result[61];
}
char minus(char a[60], char b[60])
{
	char result[61];
	int i;
	for (i=60; i < 1; i--)
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
void multiple(char a[63], char b[63], char result2[63])
{
	char a2[63], b2[63];
	int result[73]={0}, k=0, s;
	strcpy(a,"1345135.451451451");
	strcpy(b,"786251.414214527");
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
	for(int i=0; i<73; ++i)
	{
		printf("%d %d\n",i,result[i]);
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

void multiple(char a[63], char b[63], char result2[63])
{
	char a2[63], b2[63];
	int result[73]={0}, k=0, s;
	strcpy(a,"1345135.451451451");
	strcpy(b,"786251.414214527");
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
	for(int i=0; i<73; ++i)
	{
		printf("%d %d\n",i,result[i]);
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
char division(char a[60], char b[60])
{//배열째로 나눗셈 16/2 면 [1,6]/[2], [2] > [4] > [8] > [1,6] 나눠지는 값과 배열이 같아질 때까지 몫+1
 //나누는 값이 나눠지는 값보다 작을 때까지 반복문

}
char mod(char a[60], char b[60])
{

}
void Clear()
{
	system("clear");
}
void Exit()
{
	exit(1);
}
void save(char var_name[10], char var[10][62], int var_number)
{
	FILE *ofp;
	ofp=fopen("data.txt","w");
	for(int i=0; i<var_number; ++i)
		fprintf(ofp,"%c %s ",var_name[i], var[i]);
	fclose(ofp);
}
int load(char var_name[10], char var[10][62])
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
int main(void)
{
	char input[1000];
	char number[100][62], operator[100];
	char var_name[10], var[10][62];
	int var_number=0,n,plus_minus[100]={0};	//n : 숫자의 갯수, plus_minus : 양수/음수 구분(양수 : 0, 음수 : 1)
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
			printf("%s",input);
			n=cut(number,operator,input);
			for(int i=0; i<n; ++i)
			{
				if(number[i][0]=='-')
				{
					plus_minus[i]=1;
					for(int j=1; j<strlen(number[i]); ++j)
						number[i][j-1]=number[i][j];
					number[i][strlen(number[j])-1]='\0';
				}
			}
			for(int i=0;i<n;++i)
				printf("%s\n",number[i]);
			for(int i=0;i<n-1;++i)
				printf("%c\n",operator[i]);
		}
	}
}
