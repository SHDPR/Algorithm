#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<pair<int, int>, bool> mov;

int main()
{
  int M, N;

  int **map;

  cin >> M >> N;

  map = (int**)malloc(sizeof(int*) * M);

  for(int idx = 0; idx < M; idx++)
  {
    char input[N];
    map[idx] = (int*)malloc(sizeof(int) * N);

    cin >> input;

    for(int jdx = 0; jdx < N; jdx++)
    {
      map[idx][jdx] = (int)(input[jdx] - '0');
    }
  }

  int visit[M][N][2];
  memset(visit, 0, sizeof(visit));


  visit[0][0][0] = 1;
  visit[0][0][1] = 1;
  
  queue<mov> bfs;
  bfs.push({{0,0}, true});

  while(!bfs.empty())
  {
    int x = bfs.front().first.first;
    int y = bfs.front().first.second;
    bool wall = bfs.front().second;

    int z = (wall)? 1 : 0;

    bfs.pop();

    int move_x[4] = {1, 0, -1, 0};
    int move_y[4] = {0, 1, 0, -1};

    for(int idx = 0; idx < 4; idx++)
    {
      int next_x = x + move_x[idx];
      int next_y = y + move_y[idx];

      if(next_x == M || next_x == -1)
        continue;
      if(next_y == N || next_y == -1)
        continue;

      if(map[next_x][next_y] == 0 && visit[next_x][next_y][z] == 0)
      {
        bfs.push({{next_x, next_y}, wall});
        visit[next_x][next_y][z] = visit[x][y][z] + 1;
      }

      if(map[next_x][next_y] == 1 && wall)
      {
        bfs.push({{next_x, next_y}, false});
        visit[next_x][next_y][0] = visit[x][y][z] + 1;
      }
    }
  }

  if(visit[M-1][N-1][0] == 0 && visit[M-1][N-1][1] == 0)
    cout << -1;
  else
  {
    int block = visit[M-1][N-1][0];
    int unblock = visit[M-1][N-1][1];

    if(block == 0)
      cout << unblock;
    else if(unblock == 0)
      cout << block;
    else
      cout << min(block, unblock);
  }
}
