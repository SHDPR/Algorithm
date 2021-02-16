#include <iostream>
using namespace std;

void farm_search(int x, int y, int **farm, int **visit, int M, int N)
{
  int move_x[4] = {0, 1, 0, -1};
  int move_y[4] = {1, 0, -1, 0};

  visit[x][y] = 1;

  for(int idx = 0; idx < 4; idx++)
  {
    int next_x = x + move_x[idx];
    int next_y = y + move_y[idx];

    if(next_x == M || next_x == -1)
      continue;

    if(next_y == N || next_y == -1)
      continue;

    if(visit[next_x][next_y] == 0 && farm[next_x][next_y] == 1)
      farm_search(next_x, next_y, farm, visit, M, N);
  }
}




int main()
{
  int testcase;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++)
  {
    int M, N, K;
    int **farm;
    int **visit;

    cin >> M >> N >> K;

    farm = (int**)malloc(sizeof(int*) * M);
    for(int jdx = 0; jdx < M; jdx++)
    {
      farm[jdx] = (int*)malloc(sizeof(int) * N);
      for(int kdx = 0; kdx < N; kdx++)
        farm[jdx][kdx] = 0;
    }

    visit = (int**)malloc(sizeof(int*) * M);
    for(int jdx = 0; jdx < M; jdx++)
    {
      visit[jdx] = (int*)malloc(sizeof(int) * N);
      for(int kdx = 0; kdx < N; kdx++)
        visit[jdx][kdx] = 0;
    }

    for(int jdx = 0; jdx < K; jdx++)
    {
      int x, y;
      cin >> x >> y;
      farm[x][y] = 1;
    }

    int cnt = 0;

    for(int jdx = 0; jdx < M; jdx++)
    {
      for(int kdx = 0; kdx < N; kdx++)
      {
          if(visit[jdx][kdx] == 0 && farm[jdx][kdx] == 1)
          {
            cnt++;
            farm_search(jdx, kdx, farm, visit, M, N);
          }
      }
    }

    cout << cnt << '\n';

    free(farm);
    free(visit);

  }
}
