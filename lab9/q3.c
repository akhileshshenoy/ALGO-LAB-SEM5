#include<stdio.h> 

int max(int a, int b) 
{
 	return (a > b)? a : b; 
 } 

int knapSack(int W, int wt[], int val[], int n) 
{ 
if (n == 0 || W == 0) 
	return 0; 

if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 
else 
	return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1)); 
} 

int main() 
{ 
	int val[10],wt[10]; 
	int W, n; 
    printf("Enter the number of weights : ");
    scanf("%d",&n);
	printf("Enter the weight vector : ");
    for (int i = 0; i < n; i++)
    	scanf("%d",&wt[i]); 
    printf("Enter the value vector : ");
    for (int i = 0; i < n; i++)
    	scanf("%d",&val[i]); 
    printf("Enter the knapsack weight : ");
    scanf("%d",&W);
 	printf("Maximum value = %d\n", knapSack(W, wt, val, n));  
    return 0; 
} 
