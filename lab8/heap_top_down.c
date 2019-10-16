#include<stdio.h>
#include<stdlib.h>
int count = 0;
void swap(int* a, int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void topdown_heapify(int heaparr[], int n)
{
	int curr;
	int par;
	for(int i=1;i<n;i++)
	{
		curr= i;
		while(curr>0)
		{
			par = (curr%2)?curr/2:curr/2-1;
			if(heaparr[curr]<heaparr[par])
				break;
			else
			{
				count++;
				swap(&heaparr[curr],&heaparr[par]);
				curr=par;			
			}

		}
	}
}



void main()
{
	int heaparr[] = {1,2,3,4,5,7,8};//{7,4,3,2,8,9,1};
	printf("Before topdown_heapify :");
	int n = sizeof(heaparr)/sizeof(heaparr[0]);
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
	topdown_heapify(heaparr,n);
	printf("\nAfter topdown_heapify :");
	for(int i=0;i<n;i++)
		printf("%d  ",heaparr[i]);
	printf("\ncount = %d",count);
}