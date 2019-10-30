#include<stdio.h>
#include<stdlib.h>

int fib(int n) 
{ 
    int sum;
    if (n == 2) 
    	return 2;
  	if(n==1)
  		return 1;
    else{ 
    sum= 2+ fib(n-1) + fib(n-2);
    return sum;
}
} 
  
void main () 
{ 
  int n,sum;
  printf("n=");
  scanf("%d",&n);  
  sum=fib(n);
  printf("n = %d\n", n);
  printf("Opcount=%d",sum);
} 