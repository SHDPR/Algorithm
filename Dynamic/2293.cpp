#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int coin[n+1];

  int knapsack[2][k+1];

/*
  for(int idx = 0; idx < 2; idx++)
  {
    for(int jdx = 0; jdx < k + 1; jdx++)
      knapsack[idx][jdx] = 0;
  }
*/
  memset(knapsack, 0, sizeof(int) * 2 * (k+1));

  knapsack[0][0] = 1;
  knapsack[1][0] = 1;


  for(int idx = 1; idx < n + 1; idx++)
  {
    cin >> coin[idx];
  }

  int toggle = 0;

  for(int idx = 1; idx < n + 1; idx++)
  {
    toggle = (toggle + 1) % 2;
    for(int jdx = 1; jdx < k + 1; jdx++)
    {
      if(coin[idx] > jdx)
      {
        knapsack[toggle][jdx] = knapsack[(toggle + 1) % 2][jdx];
      //  cout << knapsack[toggle][jdx] << " : " << "toggle-" << toggle << "idx-" << jdx << '\n';
      }

      else
      {
        knapsack[toggle][jdx] = knapsack[(toggle + 1) % 2][jdx] + knapsack[toggle][jdx - coin[idx]];
        //cout << knapsack[toggle][jdx] << " : " << "toggle-" << toggle << "idx-" << jdx << '\n';
      }

    }
  }

  cout << knapsack[toggle][k];

}
