#include<stdio.h>
#include<stdlib.h>
int count = 0;

void swap(int* a, int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void heapify(int heaparr[], int n)
{
	int flag,j,k,v;
	for(int i=(n%2)?n/2:n/2-1;i>=0;i--)
	{
		k=i;
		v=heaparr[k];
		flag = 0;
		while(flag == 0 && 2*k+2<n)
		{
			j=2*k+1;
			if(j<n) //There are 2 children
				if(heaparr[j]<heaparr[j+1])
					j=j+1;
			if(v>=heaparr[j])
				flag = 1;
			else
			{	
				
				heaparr[k]=heaparr[j];
				k=j;
			}
			heaparr[k]=v;
		}
	}
}

int heapsort(int heaparr[],int n)
{
	int i=0;
	while(i<n-1)
	{
		count++;
		swap(&heaparr[0],&heaparr[n-1-i]);
		heapify(heaparr,n-1-i);
		i++;
	}
}


void main()
{
	int heaparr[] = {2,1,3,4,5};
	int n = sizeof(heaparr)/sizeof(heaparr[0]);
	printf("Before heapsort :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
	heapify(heaparr,n);
	heapsort(heaparr,n);
	printf("\nAfter heapsort :");
	for(int i=n-1;i>=0;i--)
		printf("%d  ",heaparr[i]);
	printf("\ncount = %d",count);
}