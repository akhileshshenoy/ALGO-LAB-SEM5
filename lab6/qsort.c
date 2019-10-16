#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void qcksort(int* arr, int lpivot, int rpivot)
{
	if(lpivot<rpivot)
	{
		int left = lpivot, right = rpivot;
		int p = arr[left];
		while(rpivot>=lpivot)
		{
			while(arr[lpivot]<=p && lpivot < right)
				lpivot++;
			while(arr[rpivot]>p && rpivot > left)
				rpivot--;
			swap(&arr[lpivot],&arr[rpivot]);
		}
		swap(&arr[lpivot],&arr[rpivot]);
		swap(&arr[left],&arr[rpivot]);
		qcksort(arr,left,rpivot-1);
		qcksort(arr,rpivot+1,right);
	}
}

void main()
{
	int n;
	printf("Enter the length of the array:");
	scanf("%d",&n);
	int arr[50];
	printf("Enter elements : ");
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	qcksort(arr,0,n-1);
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
} 