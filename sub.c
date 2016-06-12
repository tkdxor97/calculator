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
