#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void swaplr(int lr[],int k)
{
	int t=lr[k];
	lr[k]=lr[k+1];
	lr[k+1]=t;
}
/*int max(int p[],int k,int n)
{
	for(int i=0;i<n;i++)
	{
		if(p[k]<p[i])
			return 0;
	}
	return 1;
}*/
int sume(int **a,int p[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[p[i]-1][i];
	return sum;
}
void copy(int b[],int p[],int n)
{
	for(int i=0;i<n;i++)
		b[i]=p[i];
}
int fact(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	return fact(n-1)*n;
}
void revdir(int lr[],int rl[],int p[],int k,int n)
{
	for(int i=0;i<n;i++)
	{
		if(p[k]<p[i])
		{
			if(lr[i])
			{
				lr[i]=0;
				rl[i]=1;
			}
			else
			{
				lr[i]=1;
				rl[i]=0;
			}
			//printf("**%d**%d^^",k,i);
		}
	}
	
}
int largmob(int p[],int lr[],int rl[],int n)
{
	int max=0,pos=0;
	for(int i=0;i<n;i++)
	{
		if(lr[i]&&i!=n-1){
			if(max<p[i]&&p[i]>p[i+1])
			{
				max=p[i]; pos=i;
			}
		}
		if(rl[i]&&i!=0){
			if(max<p[i]&&p[i]>p[i-1])
			{
				max=p[i]; pos=i;
			}
		}
	}
	revdir(lr,rl,p,pos,n);
	return pos;
}
void solve(int n, int **a,int lr[],int rl[],int p[],int f[])
{
	int min=2147483647,sum=0,pos;
	int b[n];
	for(int i=0;i<fact(n);i++)
	{
		
		sum=sume(a,p,n); 
		if(sum<min)
		{
			min=sum;
			copy(b,p,n);
		}
		pos=largmob(p,lr,rl,n); //printf("$$%d**%d",pos,lr[pos]);
		for(int j=0;j<n;j++)
			 printf("%d()%d??%d||",p[j],lr[j],rl[j]);
		printf("\n");
		if(lr[pos])
		{
			/*int temp=p[pos];
			p[pos]=p[pos+1];
			p[pos+1]=temp;
			bool t1=rl[pos];
			rl[pos]=rl[pos+1];
			rl[pos+1]=t1;
			bool t=lr[pos];
			lr[pos]=lr[pos+1];
			lr[pos+1]=t;*/
			swap(&p[pos],&p[pos+1]);
			swaplr(lr,pos);
			//printf("%d&&%d%d\n",rl[pos],pos+1,rl[pos+1]);
			//printf("\n");
			int k=rl[pos+1];
			printf("%d",k);
			//rl[pos+1]=rl[pos];
			//rl[pos]=k;
			printf("^^");
		}
		if(rl[pos])
		{
			int temp=p[pos];
			p[pos]=p[pos-1];
			p[pos-1]=temp;
			int t=lr[pos];
			lr[pos]=lr[pos-1];
			lr[pos-1]=t;
			int t1=rl[pos];
			rl[pos]=rl[pos-1];
			rl[pos-1]=t1;
		}
	}
	copy(f,b,n);
}
int main()
{
	printf("Enter number of people");
	int n;
	scanf("%d",&n);
	/*printf("Enter number of jobs");
	int k;
	scanf("%d",&k);*/
	int **j=(int**)malloc(sizeof(int*)*n); int* lr=(int*)malloc(sizeof(int)*n); int* rl=(int*)malloc(sizeof(int)*n);
	int perm[n],final[n];
	printf("Enter costs");
	for(int i=0;i<n;i++)
	{
		lr[i]=0;
		rl[i]=1;
		perm[i]=i+1;
		j[i]=(int*)malloc(sizeof(int)*n);
		for(int l=0;l<n;l++)
			scanf("%d",&j[i][l]);
	}
	solve(n,j,lr,rl,perm,final);
	for(int i=0;i<n;i++)
		printf("\nPerson %d : Job %d",i+1,final[i]);
}