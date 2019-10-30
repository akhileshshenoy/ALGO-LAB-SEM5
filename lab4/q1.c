#include <stdio.h>
#include <stdlib.h>

int min = 9999;
int matrix[10][10];
int n;

void calc(int arr[]) {
	int cost = 0,i;
	for(i=0; i<n; i++) {
		cost = cost + matrix[i][arr[i]-1];
	}
	if(cost < min)
		min = cost;
	return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perm(int arr[], int l, int r)
{
    if(l==r) {
        calc(arr);
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(&arr[i], &arr[l]);
        perm(arr, l+1, r);
        swap(&arr[i], &arr[l]);
    }
}

int main() {
	int arr[n];
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter Matrix:\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d",&matrix[i][j]);
		}
	}
	for(int i=0; i<n; i++) {
		arr[i] = i+1;
	}
	perm(arr,0,n-1);
	printf("The minimum cost is: %d\n", min);
}