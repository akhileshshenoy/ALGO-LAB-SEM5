#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char a[50],b[50];
	int alen,blen,flag=1;
	printf("Enter 1st string:");
	scanf("%s",&a);
	printf("Enter 2nd string:");
	scanf("%s",&b);
	alen=strlen(a);
	blen=strlen(b);
	if(alen==blen)
	{
		for(int i =0; i< alen; i++)
			if(a[i]!=b[i])
			{
				flag=0;
				break;
			}
		if(flag==1)
		{
			printf("The 2 strings are same.");
			return;
		}	
	}
	printf("The 2 strings are different.");
	return;
}