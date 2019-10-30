#include<stdio.h> 

int min(int a, int b)
{
	int c =	 0;
	return c=(a<b)?a:b;
}
 
void printMatrix(int transitiveMatrix[][10],int V) 
{ 
    printf ("Transitive closure =\n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
            printf ("%d ", transitiveMatrix[i][j]); 
        printf("\n"); 
    } 
} 

void transitiveClosure(int graph[][10],int V) 
{ 
    int transitiveMatrix[10][10], i, j, k; 

    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            transitiveMatrix[i][j] = graph[i][j]; 
  
    for (k = 0; k < V; k++) 
    { 
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            { 
                transitiveMatrix[i][j] = min(transitiveMatrix[i][j],(transitiveMatrix[i][k] + transitiveMatrix[k][j])); 
                printf("k= %d, i = %d, j = %d , t = %d \n",k,i,j,transitiveMatrix[i][j]);
            } 
        } 
    } 
    printMatrix(transitiveMatrix,V); 
} 
  


int main() 
{
    int V;
    int graph[10][10]; 
    printf("Enter the number of vertices : ");
    scanf("%d",&V);
    printf("Enter the distance matrix :\n");
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
               scanf("%d",&graph[i][j]);
    } 
    transitiveClosure(graph,V); 
    return 0; 
} 
