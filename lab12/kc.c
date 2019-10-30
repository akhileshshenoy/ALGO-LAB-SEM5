#include <stdio.h>
#define MAX 20

float final_profit;
int w[MAX];
int p[MAX];
int n,m;
int temp[MAX],x[MAX];
float final_wt;
 
float Bound_Calculation(int cp,int cw,int k)
{
   int ub,c,i;
   ub=cp;
   c=cw;
   for(i=k+1;i <=n;i++)
   {
	  c=c+w[i];
	  if(c < m)
	   ub=ub+p[i];
	  else
	   return (ub+(1-(c-m)/w[i])*p[i]);
   }
   return ub;
}

void BackTracking(int k,int cp,int cw)
{
 int new_k,new_cp,new_cw,j;
 if(cw+w[k] <=m)
 {
  temp[k]=1;
  if(k < n)
  {
   new_k=k+1;
   new_cp=cp+p[k];
   new_cw=cw+w[k];
   BackTracking(new_k,new_cp,new_cw);
  }
  if((new_cp>final_profit)&&(k==n))
  {
   final_profit=new_cp;
   final_wt=new_cw;
   for(j=1;j <=k;j++)
   {
	x[j]=temp[j];
   }
  }
 }
  
 if(Bound_Calculation(cp,cw,k)>=final_profit)
 {
  temp[k]=0;
  if(k < n)
   BackTracking(k+1,cp,cw);
  if((cp>final_profit)&&(k==n))
  {
   final_profit=cp;
   final_wt=cw;
   for(j=1;j <=n;j++)
	x[j]=temp[j];
  }
 }
}
 
void main()
{
 int i;
 printf("Enter number of Objects you want:");
 scanf("%d",&n);
 for(i=1;i <=n;i++)
 {
  printf("Enter Weight and value for object %d:",i);
  scanf("%d %d",&w[i],&p[i]);
 }
 printf("Enter Capacity of Knapsack:");
 scanf("%d",&m);

 BackTracking(1,0,0);
  
 printf("Following Objects are included:");
 for(i=1;i <=n;i++)
 {
  if(x[i]==1)
   printf("\n%d",i);
 }

 printf("\n Final Weight:%f",final_wt);
 printf("\n Final value:%f",final_profit);

}


