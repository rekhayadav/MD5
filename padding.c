#include<stdio.h>
void main()
{
	FILE *p;
	int i=0,num;
	p=fopen("message.txt","r+");
	while(feof(p)!=0)
	{
		fscanf(p,"%d",&num);
		if((num!=1)&&(num!=0))
		{
			printf("\nError...\nThe message was not in binary form");
			return;
		}
		i++;
	}
	i=i%512;
	num=512-i;
	while(num!=0)
	{
		if(num%2!=0)
		fprintf(p,"1");
		else
		fprintf(p,"0");
		num--;
	}
	fclose(p);
}
