#include<stdio.h>
#define MAX 100

int stack[MAX],top=-1;

void push(int v)
{
	if(top<MAX)
		stack[top++]=v;
}

int pop()
{
	return stack[--top];
}

int isEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}

int G[MAX][MAX];
int stat[MAX];
int n;

void topsort(int i)
{
	if(stat[i]==0)
	{
		stat[i] = 1;
		for(int j=0;j<n;j++)
		{
			if(G[i][j]==1 && stat[j]==0)
				topsort(j);
		}
		push(i);
	}
}

int main()
{
	printf("Enter Number of Vertices: ");
	scanf("%d",&n);
	printf("Enter Matrix - \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&G[i][j]);
		stat[i] = 0;
	}

	for(int i=0;i<n;i++)
		topsort(i);

	while(!isEmpty())
		printf("%d\t",pop());
	printf("\n");
	return 0;
}

/*
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
1 1 0 0 0 0
1 0 1 0 0 0

5	4	2	3	1	0
*/