#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> cod;

int N, M;
int city[50][50];

vector<cod> chick;
vector<cod> house;

int min_dist = 100 * 100 * 2;

cod mov[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

/* BFS -> inefficient
int find_chick(int x, int y)
{
  queue<cod> min_chick;

  min_chick.push({x, y});
  int cnt = 0;

  while(!min_chick.empty())
  {
    cod curr = min_chick.front();
    min_chick.pop();

    for(int idx = 0; idx < 4; idx++)
    {
      cod next = {curr.first + mov[idx].first, curr.second + mov[idx].second};

      if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
        continue;

      if(city[next.first][next.second] == 2)
      {
        return abs(next.first - x) + abs(next.second - y);
      }

      min_chick.push(next);
    }
  }

  min_chick.~queue();
}
*/

int find_chick(int x, int y)
{
  int dist = 100 * 100 * 2;

  for(int idx = 0; idx < chick.size(); idx++)
  {
    if(city[chick[idx].first][chick[idx].second] == 0)
      continue;


    int curr_dist = abs(chick[idx].first - x) + abs(chick[idx].second - y);
    dist = (dist > curr_dist)? curr_dist : dist;
  }
  return dist;
}




int chicken_dist()
{
  int sum = 0;

  for(int idx = 0; idx < house.size(); idx++)
  {
    cod curr = house[idx];
    int dist = find_chick(curr.first, curr.second);
    sum += dist;
  }

  return sum;
}

void dfs_dist(int idx, int cnt)
{
  if(cnt == chick.size() - M)
  {
    int dist = chicken_dist();
    min_dist = (min_dist < dist)? min_dist : dist;
    return;
  }

  for(int i = idx + 1; i < chick.size(); i++)
  {
    cod curr = chick[i];
    city[curr.first][curr.second] = 0;
    dfs_dist(i, cnt + 1);
    city[curr.first][curr.second] = 2;
  }
  return;
}

int main()
{
  cin >> N >> M;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      cin >> city[idx][jdx];
      switch(city[idx][jdx])
      {
        case 1 :
          house.push_back({idx, jdx});
          break;
        case 2 :
          chick.push_back({idx, jdx});
          break;
      }
    }
  }

  dfs_dist(-1, 0);
  cout << min_dist;
}
