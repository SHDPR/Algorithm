#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> cod;


int visit[20][20];
int space[20][20];
cod dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int fish_cnt = 0;
cod shark;
int shark_size = 2;
int eaten_cnt = 0;
int N;

int findfish()
{
  queue<cod> route;
  route.push(shark);

  while(!route.empty())
  {
    cod now = route.front();
    route.pop();

    for(int idx = 0; idx < 4; idx++)
    {
      int new_x = now.first + dir[idx].first;
      int new_y = now.second + dir[idx].second;

      if(new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)
        continue;

      if(visit[new_x][new_y] != -1)
        continue;

      int fish_size = space[new_x][new_y];

      if(fish_size > shark_size)
        continue;


      visit[new_x][new_y] = visit[now.first][now.second] + 1;

      route.push({new_x, new_y});
    }
  }

  int min_path = N * N;
  cod pos = {N, N};

  for(int idx = N-1; idx >= 0; idx--)
  {
    for(int jdx = N-1; jdx >= 0; jdx--)
    {
      int temp = visit[idx][jdx];

      if(temp == -1 || space[idx][jdx] == 0 || space[idx][jdx] == shark_size)
        continue;

      if(min_path >= temp)
      {
        min_path = temp;
        pos = {idx, jdx};
      }
    }
  }

  if(pos.first == N && pos.second == N)
  {
    return -1;
  }


  fish_cnt -= 1;
  eaten_cnt += 1;
  if(eaten_cnt == shark_size)
  {
    shark_size += 1;
    eaten_cnt = 0;
  }

  space[pos.first][pos.second] = 0;

  shark = pos;
  return min_path;
}










int main()
{
  cin >> N;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      cin >> space[idx][jdx];
      visit[idx][jdx] = -1;

      if(space[idx][jdx] == 9)
      {
        space[idx][jdx] = 0;
        shark = {idx, jdx};
        visit[idx][jdx] = 0;
      }

      else if(space[idx][jdx] != 0)
      {
        fish_cnt++;
      }
    }
  }

  int time_sum = 0;

  while(true)
  {
    if(fish_cnt == 0)
      break;

    for(int idx = 0; idx < N; idx++)
    {
      for(int jdx = 0; jdx < N; jdx++)
      {
        visit[idx][jdx] = -1;
      }
    }

    visit[shark.first][shark.second] = 0;

    int ret = findfish();

    if(ret == -1)
      break;

    else
      time_sum += ret;
  }

  cout << time_sum;
}
