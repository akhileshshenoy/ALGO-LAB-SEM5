#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isprime(int n)
{
	int i =2;
	while(i<n)
	{
		if(n%i==0)
			return 0;
		i++;
	}
	return 1;	
}

void main(){
	int num1,num2,gcd=1,g=2,opcount=0;
	printf("Enter 2 numbers: ");
	scanf("%d %d",&num1,&num2);
	sum = num1 + num2;
	while(g<=num1 && g<=num2)
	{
		
		if(isprime(g))
		{
			opcount++;	
			while(num1%g==0 && num2%g==0)
			{
				gcd*=g;
				num1/=g;
				num2/=g;
			}
		}
		g++;
	}
	printf("m + n = %d\ngcd = %d\n",sum,gcd);
	printf("opcount : %d",opcount);
}