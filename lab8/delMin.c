#include<stdio.h>
#include<stdlib.h>

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

int findAndDel(int heaparr[],int n)
{
	int i=0,pos,min=heaparr[0];
	for(i=1;i<n;i++)
	{
	  	if(heaparr[i]<min)
	  	{	
	  		min=heaparr[i];
	  		pos = i;
	  	}
	}
	printf("\nDeleted %d.\n",heaparr[pos]);
	swap(&heaparr[pos],&heaparr[n-1]);
	n--;
	heapify(heaparr,n);
	return n;
}


void main()
{
	int heaparr[] = {7,4,1,3,8,9,2};
	int ele,n = sizeof(heaparr)/sizeof(heaparr[0]);
	heapify(heaparr,n);
	printf("Before Deletion :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
	n=findAndDel(heaparr,n);
	printf("After Deletion :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
}