#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int main()
{
  int N, M;
  int *cost;
  int *memr;
  int **memo;
  int costMAX = 0;

  cin >> N >> M;

  memr = (int*)malloc(sizeof(int) * N);
  cost = (int*)malloc(sizeof(int) * N);

  for(int idx = 0; idx < N; idx++)
    cin >> memr[idx];

  for(int idx = 0; idx < N; idx++)
  {
    cin >> cost[idx];
    costMAX += cost[idx];
  }

  memo = (int**)malloc(sizeof(int*) * N);

  for(int idx = 0; idx < N; idx++)
  {
    memo[idx] = (int*)malloc(sizeof(int) * (costMAX + 1));
    for(int jdx = 0; jdx <= costMAX; jdx++)
      memo[idx][jdx] = 0;
  }


  //memset(memo, 0, sizeof(int) * (costMAX + 1) * N);


  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 1; jdx <= costMAX; jdx++)
    {
      if(idx == 0)
      {
        if(jdx >= cost[idx])
          memo[idx][jdx] = memr[idx];
        else
          memo[idx][jdx] = 0;
      }
      else if(jdx >= cost[idx])
        memo[idx][jdx] = max(memo[idx - 1][jdx], memo[idx - 1][jdx - cost[idx]] + memr[idx]);
      else
        memo[idx][jdx] = memo[idx - 1][jdx];
    }
  }

  for(int idx = 0; idx <= costMAX; idx++)
  {
    if(memo[N-1][idx] >= M)
    {
      cout << idx;
      break;
    }
  }


}
