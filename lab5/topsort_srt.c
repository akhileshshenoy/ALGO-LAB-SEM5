#include<stdio.h>
#define MAX 100

int G[MAX][MAX];
int stat[MAX];
int n;

int checkTotal()
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			sum+=G[i][j];
	}
	if(sum == (-1 * n  * n))
		return 1;
	return 0;
}


int checkColumn(int i)
{
	for(int j=0;j<n;j++)
		if(G[j][i]==1)
			return 0;
	return 1;	
}

void topsort()
{
	while(!checkTotal())
	{
		for(int i=0;i<n;i++)
		{
			if(checkColumn(i)==1 && stat[i]==0)
			{
				stat[i]=1;
				for(int j=0;j<n;j++)
				{
					G[i][j]=-1;
					G[j][i]=-1;
				}
				printf("%d\t",i);
			}	
		}
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
	topsort();
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

4	5	0	2	3	1
*/