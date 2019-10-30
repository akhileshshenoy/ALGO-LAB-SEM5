#include<stdio.h>
#include<stdlib.h>

int towerOfHanoi(int n, char a, char b, char aux) 
{ 
    int sum;
    if(n-1==1)
        return 2;
    else{
        sum = 2 + towerOfHanoi(n-1, a, aux, b) + towerOfHanoi(n-1, aux, b, a);
        return sum;
    } 
} 
  
int main() 
{ 
    int n;
    printf("n=");
    scanf("%d",&n); 
    int sum = towerOfHanoi(n, 'A', 'C', 'B');
    printf("For n = %d, Opcount = %d.",n,sum);
} 