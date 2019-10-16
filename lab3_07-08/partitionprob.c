#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int n,m,sum=0,sum1,flag=1;
	printf("Enter the length: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:");
	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	
	for(int i=0;i<n;i++)
		sum+=a[i];
	if(sum%2==1)
	{
		printf("Not possible.\n");
		return;
	}

	m=pow(2,n);
	sum/=2;
	for(int i=0;i<m;i++)
	{
		sum1=0;
		for(int j=0;j<n;j++)
		{
			if(i&1<<j)
				sum1+=a[j];
		}
		if(sum==sum1)
		{
			printf("Possible.");
			flag=0;
			printf("%d",i);
		}

	}
	if(flag==1)
	{
		printf("Not possible.");
	}
	
}