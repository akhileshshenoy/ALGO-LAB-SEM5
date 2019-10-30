#include<stdio.h>
#include<stdlib.h>

void addNode(int *adjMatrix,int src,int dst,int numOfVertices)
{
	*((adjMatrix+src*numOfVertices)+dst) = 1;
	*((adjMatrix+dst*numOfVertices)+src) = 1;
}

void printList1(int* adjMatrix,int numOfVertices)
{
	printf("Adjacency matrix is:\n");
	for(int i=0;i<numOfVertices;i++)
	{
		for(int j=0;j<numOfVertices;j++)
		{
			printf("%d ",*((adjMatrix + i*numOfVertices)+j));
		}
		printf("\n");
	}
}

void main()
{
	int src,dst,flag=1,numOfVertices;
	printf("Enter number of vertices in the graph :");
	scanf("%d",&numOfVertices);
	int adjMatrix[numOfVertices][numOfVertices];
	for(int i=0;i<numOfVertices;i++)
	{
		for(int j=0;j<numOfVertices;j++)
		{
			adjMatrix[i][j]=0;
		}	
	}
	while(flag)
	{
		printf("Enter source edge and destination edge(0 0 to stop): ");
		scanf("%d %d",&src,&dst);
		if(src == 0 && dst == 0)
			break;
		else
			addNode(&adjMatrix[0][0],src-1,dst-1,numOfVertices); //0-indexed
	}
	printList1(&adjMatrix[0][0],numOfVertices);
}