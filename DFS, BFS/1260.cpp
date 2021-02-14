#include <iostream>
#include <queue>
using namespace std;


void dfs(int s, int **graph, int *visit, int N)
{
  cout << s + 1 << " ";
  visit[s] = 1;

  for(int idx = 0; idx < N; idx++)
  {
    if(visit[idx] == 0 && graph[s][idx] == 1)
      dfs(idx, graph, visit, N);
  }
}

void bfs(int s, int **graph, int *visit, int N)
{
  queue <int> list;

  list.push(s);
  visit[s] = 1;

  while(!list.empty())
  {
    int next = list.front();
    cout << next + 1 << " ";
    list.pop();

    for(int idx = 0; idx < N; idx++)
    {
      if(visit[idx] == 0 && graph[next][idx] == 1)
      {
        list.push(idx);
        visit[idx] = 1;
      }
    }
  }
}


int main()
{
  int N, M, start;
  int *visit;
  int **graph;

  cin >> N >> M >> start;

  visit = (int*)malloc(sizeof(int) * N);

  for(int idx = 0; idx < N; idx++)
    visit[idx] = 0;

  graph = (int**)malloc(sizeof(int*) * N);

  for(int idx = 0; idx < N; idx++)
  {
    graph[idx] = (int*)malloc(sizeof(int) * N);
    for(int jdx = 0; jdx < N; jdx++)
      graph[idx][jdx] = 0;
  }

  for(int idx = 0; idx < M; idx++)
  {
    int x, y;
    cin >> x >> y;
    graph[x-1][y-1] = 1;
    graph[y-1][x-1] = 1;
  }

  dfs(start-1, graph, visit, N);

  cout << '\n';

  for(int idx = 0; idx < N; idx++)
    visit[idx] = 0;


  bfs(start-1, graph, visit, N);



}
