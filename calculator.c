
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
/*		for(int i=60-k; i>50-k; --i)
		{
			if(result2[i]=='0' && result2[i-1]!='0')
			{
				result2[i+1]='\0';
				break;
			}
		}*/
	}
	return;
}
