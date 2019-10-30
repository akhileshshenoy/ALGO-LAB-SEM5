#include <stdio.h>
#include <stdlib.h>

void min_coins(int coin_value[],int n,int amount)
{
  for( int i=n-1; i>=0; i-- ) 
    while(amount >= coin_value[i])
    {
      amount= amount - coin_value[i];
      printf("%d  ",coin_value[i]);
    }
  printf("\n");
}


int main()
{
  int i,j,n,amount;
  printf( "Enter amount to be paid: ");
  scanf( "%d",&amount);
  printf( "Enter total kinds of currency: ");
  scanf("%d",&n);
  int coin_value[n]; 
  printf( "Enter all currency values: ");
  for(i = 0;i< n; i++)//
    scanf("%d",&coin_value[i]);
  printf( "The selected currency values are: \n");
  min_coins(coin_value,n,amount);
  return 0;
} 