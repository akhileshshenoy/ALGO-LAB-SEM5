#include<stdio.h>
#include<stdlib.h>

struct  adjNode
{
	int val;
	struct adjNode* next;
};

struct adjList
{
	struct adjNode* head;
};

struct graph
{
	int numOfVertices;
	int* visited;
	struct adjList* array;
};

struct adjNode* newAdjNode(int value)
{
	struct adjNode* node = (struct adjNode*)malloc(sizeof(struct adjNode));
	node->val = value;
	node->next = NULL;
	return node;
}

struct graph* createGraph(int totVertices)
{
	struct graph* graph1 = (struct graph*)malloc(sizeof(struct graph));
	graph1->numOfVertices = totVertices;
	graph1->visited=(int*)malloc((totVertices+1)*sizeof(int));
	for(int i = 0; i < totVertices; i++)
		graph1->visited[i]=0;
	graph1->array = (struct adjList*)malloc((totVertices+1)*sizeof(struct adjList));
	return graph1;
}

void addNode(struct graph* graph1,int src,int dst)
{
	struct adjNode* node = newAdjNode(src);
	node->next = graph1->array[dst].head;
	graph1->array[dst].head = node;

	node=newAdjNode(dst);
	node->next = graph1->array[src].head;
	graph1->array[src].head = node;
}

void printList1(struct graph* graph1)
{
	struct adjNode* currNode;
	printf("The adjacency list for the graph is :\n");
	for(int currentVertex = 1;currentVertex <= graph1->numOfVertices;currentVertex++)
	{
		currNode=graph1->array[currentVertex].head;
		printf("Vertex %d : head",currentVertex);
		while(currNode)
		{
			printf(" -> %d",currNode->val);
			currNode = currNode->next;
		}
		printf(".\n");
	} 
}

void DFS(struct graph* graph1, int vertex)
{
	graph1->visited[vertex]=1;
	printf("Popped %d\n",vertex);
	struct adjNode* temp=graph1->array[vertex].head;
	while(temp!=NULL)
	{
		if(graph1->visited[temp->val]==0)
		{
			//printf("Pushed %d\n",temp->val);
			DFS(graph1,temp->val);
		}
		else
			temp=temp->next;
	}

}

void main()
{
	int src,dst,flag=1,numOfVertices;
	printf("Enter number of vertices in the graph :");
	scanf("%d",&numOfVertices);
	struct graph* graph1=createGraph(numOfVertices);
	while(flag)
	{
		printf("Enter source edge and destination edge(0 0 to stop): ");
		scanf("%d %d",&src,&dst);
		if(src == 0 && dst == 0)
			break;
		else
			addNode(graph1,src,dst);
	}
	printList1(graph1);

	printf("Implementing DFS... \n");
	for(int i=1;i<sizeof(graph1->visited)/sizeof(int);i++)
		if(graph1->visited[i]==0)
		{
			//printf("Pushed %d\n",i);
			DFS(graph1,i); //2nd parameter is the starting vertex
		}
}