#include <iostream>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> cod;


int nation[50][50];
int visit[50][50] = {0, };
cod dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, L, R;



bool bfs_search(int idx, int jdx, int cnt)
{
  if(visit[idx][jdx] != 0)
    return true;

  bool flag = true;

    for(int kdx = 0; kdx < 4; kdx++)
    {
      int next_idx = idx + dir[kdx].first;
      int next_jdx = jdx + dir[kdx].second;

      if(next_idx < 0 || next_jdx < 0 || next_idx >= N || next_jdx >= N)
      {
        continue;
      }

      int diff = abs(nation[next_idx][next_jdx] - nation[idx][jdx]);

      if(diff >= L && diff <= R)
        flag = false;
    }

    if(flag)
    {
      return true;
    }


  queue<cod> bfs_queue;
  bfs_queue.push({idx, jdx});
  visit[idx][jdx] = cnt;

  int sum = nation[idx][jdx];
  int div = 1;

  while(!bfs_queue.empty())
  {
    cod now = bfs_queue.front();
    bfs_queue.pop();

    for(int kdx = 0; kdx < 4; kdx++)
    {
      int next_idx = now.first + dir[kdx].first;
      int next_jdx = now.second + dir[kdx].second;

      if(next_idx < 0 || next_jdx < 0 || next_idx >= N || next_jdx >= N)
        continue;

      if(visit[next_idx][next_jdx] != 0)
        continue;

      int next_pop = nation[next_idx][next_jdx];
      int now_pop = nation[now.first][now.second];

      if(abs(now_pop - next_pop) >= L && abs(now_pop - next_pop) <= R)
      {
        bfs_queue.push({next_idx, next_jdx});
        visit[next_idx][next_jdx] = cnt;
        div++;
        sum += nation[next_idx][next_jdx];
      }
    }
  }

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(visit[i][j] == cnt)
        nation[i][j] = (int)(sum / div);
    }
  }

  return false;
}


int main()
{
  cin >> N >> L >> R;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
      cin >> nation[idx][jdx];
  }

  memset(visit, 0, sizeof(visit));

  int loop = 0;
  bool flag = false;

  while(!flag)
  {
    flag = true;

    int cnt = 1;
    for(int idx = 0; idx < N; idx++)
    {
      for(int jdx = 0; jdx < N; jdx++)
      {
        if(visit[idx][jdx] == 0)
        {
          flag = bfs_search(idx, jdx, cnt++) && flag;
        }
      }
    }

    if(flag)
      break;

    loop++;

    memset(visit, 0, sizeof(visit));
  }

  cout << loop;


}
