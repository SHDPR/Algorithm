#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int com_cnt, com_line;
  int **graph;
  int *visit;

  cin >> com_cnt >> com_line;

  visit = (int*)malloc(sizeof(int) * com_cnt);
  for(int idx = 0; idx < com_cnt; idx++)
    visit[idx] = 0;

  graph = (int**)malloc(sizeof(int*) * com_cnt);
  for(int idx = 0; idx < com_cnt; idx++)
  {
    graph[idx] = (int*)malloc(sizeof(int) * com_cnt);
    for(int jdx = 0; jdx < com_cnt; jdx++)
      graph[idx][jdx] = 0;
  }

  for(int idx = 0; idx < com_line; idx++)
  {
    int x, y;
    cin >> x >> y;
    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
  }

  queue<int> worm;
  int cnt = -1;

  worm.push(0);
  visit[0] = 1;

  while(!worm.empty())
  {
    int next = worm.front();
    cnt++;
    worm.pop();

    for(int idx = 0; idx < com_cnt; idx++)
    {
      if(visit[idx] == 0 && graph[next][idx] == 1)
      {
        worm.push(idx);
        visit[idx] = 1;
      }
    }
  }

  cout << cnt;
}
