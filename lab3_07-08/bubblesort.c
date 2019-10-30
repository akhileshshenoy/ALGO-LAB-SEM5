#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
	printf("After sorting: ");
	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
}