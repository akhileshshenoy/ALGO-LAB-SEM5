#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct queue {
    int items[SIZE];
    int front;
    int rear;
};
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct queue* createQueue() 
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q) 
{
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value)
{
    //if(q->rear == SIZE-1)
      //  printf("\nQueue is Full!!");
    //else 
    {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q))
    {
        //printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {
            //printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) 
{
    int i = q->front;
    if(isEmpty(q)) 
    {
        //printf("Queue is empty");
    } 
    else 
    {
        //printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) 
        {
                printf("%d ", q->items[i]);
        }
    }    
}

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

void BFS(struct graph* graph1, int vertex)
{
	struct queue* q = createQueue();
	graph1->visited[vertex]=1;
	enqueue(q,vertex);

	while(!isEmpty(q))
	{
		int currentVertex = dequeue(q);
		printf("Visited %d\n",currentVertex);

		struct adjNode* temp=graph1->array[currentVertex].head;
		while(temp!=NULL)
		{
			if(graph1->visited[temp->val]==0)
			{
				graph1->visited[temp->val]=1;
				enqueue(q,temp->val);
			}
			temp=temp->next;
		}
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

	printf("Implementing BFS... \n");
	BFS(graph1,1); //2nd parameter is the starting vertex
		
}