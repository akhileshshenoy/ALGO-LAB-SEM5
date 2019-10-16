#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void heapOrNot(int heaparr[], int n)
{
	int curr;
	int flag=0;
	int par;
	for(int i=1;i<n;i++)
	{
		curr= i;
		par = (curr%2)?curr/2:curr/2-1;
		if(heaparr[curr]>heaparr[par])
		{
			printf("Not a heap.");
			return;
		}
	}
	printf("It is a heap.");
}



void main()
{
	int heaparr[] = {7,4,3,2,8,9,1};
	int n = sizeof(heaparr)/sizeof(heaparr[0]);
	heapOrNot(heaparr,n);
}