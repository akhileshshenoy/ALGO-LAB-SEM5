#include<stdio.h>

void main()
{
	int a =3;
	if(a&1<<2)
		printf("%d\n",a);
	else
		printf("no");
}