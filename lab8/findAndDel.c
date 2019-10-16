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

int findAndDel(int heaparr[],int n,int ele)
{
	int i=0,pos;
	while(i<n)
	{
		if(heaparr[i]==ele)
		{
			pos=i;
			break;
		}
		i++;
	}
	if(pos>=n)
	{
		printf("Not found!");
		exit(0);
	}
	swap(&heaparr[pos],&heaparr[n-1]);
	n--;
	heapify(heaparr,n);
	return n;
}


void main()
{
	int heaparr[] = {7,4,3,2,8,9,1};
	int ele,n = sizeof(heaparr)/sizeof(heaparr[0]);
	heapify(heaparr,n);
	printf("Before Deletion :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
	printf("\nWhat do you want to delete? :");
	scanf("%d",&ele);
	n=findAndDel(heaparr,n,ele);
	printf("\nAfter heapsort :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
}