#include<stdio.h>
#include<io.h>
int num(char a){
	int c;
	char b;
	int velue;
	FILE*savei,*saveo;
	if(a=='a'||a=='A'){
	velue=access("a.in",0);
	if(velue== -1){
		printf("= undefined.\n");
		scanf("\n%c%c%d",&a,&b,&c);
		savei=fopen("a.in","w");
		fprintf(savei,"%d",c);
		}

	if(velue==0){
		saveo=fopen("a.in","r");
		fscanf(saveo,"%d",&c);
		printf("= %d\n",c);
	}
	}
}
int main(){
	char a;
	while(1){scanf("%c",&a);
	num(a);}
}



	































