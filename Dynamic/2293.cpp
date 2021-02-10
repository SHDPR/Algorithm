#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
  int n, k;
  int *coin;
  int **knapsack;
  cin >> n >> k;

  coin = (int*)malloc(sizeof(int) * (n + 1));
  knapsack = (int**)malloc(sizeof(int*) * (n + 1));

  for(int idx = 0; idx < n + 1; idx++)
  {
    knapsack[idx] = (int*)malloc(sizeof(int) * (k + 1));
    for(int jdx = 0; jdx < k + 1; jdx++)
    {
      knapsack[idx][jdx] = 0;
    }
  }

  //memset(knapsack, 0, sizeof(knapsack));

  for(int idx = 1; idx < n + 1; idx++){
    cin >> coin[idx];
    knapsack[idx][0] = 1;
  }

  for(int idx = 1; idx < n + 1; idx++){
    for(int jdx = 1; jdx < k + 1; jdx++)
    {
      if(coin[idx] > jdx)
        knapsack[idx][jdx] = knapsack[idx-1][jdx];
      else
        knapsack[idx][jdx] = knapsack[idx-1][jdx] + knapsack[idx][jdx - coin[idx]];
    }
  }

  cout << knapsack[n][k];

  free(knapsack);
  free(coin);
}
