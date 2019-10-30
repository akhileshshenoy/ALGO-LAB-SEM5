#include<stdio.h> 

int max(int a, int b) 
{
 	return (a > b)? a : b; 
 } 

int MFKnapsack(int mf[][1000],int wt[],int val[],int i,int j) 
{ 
    int value = 0; 
    if(mf[i][j] < 0)
        if(j < wt[i]) 
            value = MFKnapsack(mf,wt,val,i-1,j);
        else
            value = max(MFKnapsack(mf,wt,val,i-1,j), val[i] + MFKnapsack(mf,wt,val,i-1, j-wt[i]));
    mf[i][j] = value; 
    return mf[i][j];
    printf("\n");
} 

int main() 
{ 
	int val[10],wt[10]; 
	int W, n; 
    int mf[1000][1000];
    printf("Enter the number of weights : ");
    scanf("%d",&n);
	printf("Enter the weight vector : ");
    for (int i = 1; i <= n; i++)
    	scanf("%d",&wt[i]); 
    printf("Enter the value vector : ");
    for (int i = 1; i <= n; i++)
    	scanf("%d",&val[i]); 
    printf("Enter the knapsack weight : ");
    scanf("%d",&W);
    for (int i = 0; i <=W; i++){
        mf[0][i]=0;
    }
    for (int i = 0; i <=n; i++){
        mf[i][0]=0;
    }
    for(int i =1; i<=n;i++)
        for (int j = 1; j <=W; j++)
        {
            mf[i][j]=-1;
        }
    for(int i =1; i<=n;i++)
        for (int j = 1; j <= W; j++)
        {
            mf[i][j]=MFKnapsack(mf, wt, val, i, j);
        }
 	printf("Maximum value = %d\n", mf[n][W]);  
    for(int i =0; i<=n;i++){
        for (int j = 0; j <= W; j++)
        {
            printf("%d ",mf[i][j]);
        }
        printf("\n");
    }
    return 0; 
} 
