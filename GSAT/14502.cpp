#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> coord;

int N, M;
int map[8][8];
int mapcpy[8][8];
coord zeros[64];
int zero_cnt = 0;
coord virus[10];
int vrus_cnt = 0;

coord move_four[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


int spreadcnt()
{
  queue<coord> spread;
  for(int idx = 0; idx < vrus_cnt; idx++)
  {
    spread.push(virus[idx]);
  }

  while(!spread.empty())
  {
    coord front = spread.front();
    spread.pop();

    for(int idx = 0; idx < 4; idx++)
    {
      int row = front.first + move_four[idx].first;
      int col = front.second + move_four[idx].second;

      if(row < 0 || row >= N || col < 0 || col >= M)
        continue;

      if(mapcpy[row][col] == 2 || mapcpy[row][col] == 1)
        continue;

      if(mapcpy[row][col] == 0)
      {
        mapcpy[row][col] = 2;
        spread.push({row, col});
      }
    }
  }
  int cnt = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(mapcpy[idx][jdx] == 0)
        cnt++;
    }
  }
  return cnt;

}





int main()
{
  cin >> N >> M;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      cin >> map[idx][jdx];

      if(map[idx][jdx] == 0)
      {
        zeros[zero_cnt++] = {idx, jdx};
      }

      else if(map[idx][jdx] == 2)
      {
        virus[vrus_cnt++] = {idx, jdx};
      }
    }
  }

  int max = 0;

  for(int idx = 0; idx < zero_cnt; idx++)
  {
    for(int jdx = 0; jdx < zero_cnt; jdx++)
    {
      if(idx == jdx) continue;
      for(int kdx = 0; kdx < zero_cnt; kdx++)
      {
        if(kdx == idx || kdx == jdx) continue;
        coord foo = zeros[idx];
        coord bar = zeros[jdx];
        coord baz = zeros[kdx];

        map[foo.first][foo.second] = 1;
        map[bar.first][bar.second] = 1;
        map[baz.first][baz.second] = 1;

        memcpy(mapcpy, map, sizeof(map));

        int cnt = spreadcnt();
        max = (max > cnt)? max : cnt;


        map[foo.first][foo.second] = 0;
        map[bar.first][bar.second] = 0;
        map[baz.first][baz.second] = 0;
      }

    }
  }


  cout << max;

}
