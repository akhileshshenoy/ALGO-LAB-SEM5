#include<stdio.h>
#include<stdlib.h>

void main(){
	int num1,num2,gcd,g=1,opcount=0;
	printf("Enter 2 numbers: ");
	scanf("%d %d",&num1,&num2);
	while(g<=num1 && g<=num2)
	{
		opcount++;
		if(num1%g==0 && num2%g==0)
		{
			gcd=g;
		}
		g++;
	}
	printf("m + n = %d\ngcd = %d\n",num1+num2,gcd);
	printf("opcount : %d",opcount);
}