#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> xy;
typedef pair<xy, int> xyz;

int main(){
  int M, N, H;
  cin >> M >> N >> H;

  int tomat[M][N][H];
  int visit[M][N][H];

  bool all_ripen = true;

  queue<xyz> ripen;

  memset(visit, 0, sizeof(visit));

  for(int kdx = 0; kdx < H; kdx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      for(int idx = 0; idx < M; idx++)
      {
        cin >> tomat[idx][jdx][kdx];

        int tmp = tomat[idx][jdx][kdx];
        if(tmp == 0)
          all_ripen = false;
        if(tmp == 1)
        {
          ripen.push({{idx, jdx}, kdx});
          visit[idx][jdx][kdx] = 1;
        }
      }
    }
  }

  while(!ripen.empty())
  {
    int x = ripen.front().first.first;
    int y = ripen.front().first.second;
    int z = ripen.front().second;

    ripen.pop();

    int move_x[6] = {0, 0, 0, 0, -1, 1};
    int move_y[6] = {0, 0, 1, -1, 0, 0};
    int move_z[6] = {1, -1, 0, 0, 0, 0};

    for(int idx = 0; idx < 6; idx++)
    {
      int next_x = x + move_x[idx];
      int next_y = y + move_y[idx];
      int next_z = z + move_z[idx];

      if(next_x == M || next_x == -1)
        continue;

      if(next_y == N || next_y == -1)
        continue;

      if(next_z == H || next_z == -1)
        continue;

      if(tomat[next_x][next_y][next_z] == 0 && visit[next_x][next_y][next_z] == 0)
      {
        ripen.push({{next_x, next_y}, next_z});
        visit[next_x][next_y][next_z] = visit[x][y][z] + 1;
      }
    }
  }

  if(all_ripen){
    cout << 0;
    return 0;
  }

  int max = 0;

  for(int idx = 0; idx < M; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      for(int kdx = 0; kdx < H; kdx++)
      {

        int tmp = visit[idx][jdx][kdx];
        if(tomat[idx][jdx][kdx] != -1 && tmp == 0)
        {
          cout << -1;
          return 0;
        }
        if(tomat[idx][jdx][kdx] != -1 && tmp > max)
          max = tmp;
      }
    }
  }
  cout << max-1 << '\n';

  /*
  for(int kdx = 0; kdx < H; kdx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      for(int idx = 0; idx < M; idx++)
        cout << visit[idx][jdx][kdx];
      cout << "\n";
    }
    cout << '\n';
  }
  */
}
