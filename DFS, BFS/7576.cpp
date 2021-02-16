#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int M, N;
  int **tomato;
  int **visit;
  bool all_ripen = true;
  queue<pair<int, int>> ripen;

  cin >> M >> N;

  visit = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    visit[idx] = (int*)malloc(sizeof(int) * M);
    for(int jdx = 0; jdx < M; jdx++)
      visit[idx][jdx] = 0;
  }

  tomato = (int**)malloc(sizeof(int*) *N);
  for(int idx = 0; idx < N; idx++)
  {
    tomato[idx] = (int*)malloc(sizeof(int) * M);
    for(int jdx = 0; jdx < M; jdx++)
    {
      cin >> tomato[idx][jdx];
      if(tomato[idx][jdx] == 0)
        all_ripen = false;
      if(tomato[idx][jdx] == 1)
      {
        ripen.push({idx, jdx});
        visit[idx][jdx] = 1;
      }
    }
  }

  while(!ripen.empty())
  {
    int x = ripen.front().first;
    int y = ripen.front().second;

    ripen.pop();

    int move_x[4] = {1, 0, -1, 0};
    int move_y[4] = {0, 1, 0, -1};

    for(int idx = 0; idx < 4; idx++)
    {
      int next_x = x + move_x[idx];
      int next_y = y + move_y[idx];

      if(next_x == N || next_x == -1)
        continue;
      if(next_y == M || next_y == -1)
        continue;

      if(tomato[next_x][next_y] == 0 && visit[next_x][next_y] == 0)
      {
        ripen.push({next_x, next_y});
        visit[next_x][next_y] = visit[x][y] + 1;
      }
    }
  }


  if(all_ripen)
    cout << 0;
  else
  {
    int max = 0;
    for(int idx = 0; idx < N; idx++)
    {
      for(int jdx = 0; jdx < M; jdx++)
      {
        int tmp = visit[idx][jdx];
        if(tomato[idx][jdx] != -1 && tmp == 0)
        {
          cout << -1;
          return 0;
        }
        if(tomato[idx][jdx] != -1 && tmp > max)
          max = tmp;
      }
    }

    cout << max-1;
  }


}
