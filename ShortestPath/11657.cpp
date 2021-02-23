#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;


int main()
{
  int N, M;

  cin >> N >> M;

  vector<tuple<int, int, int>> edge;
  for(int idx = 0; idx < M; idx++)
  {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    edge.push_back(make_tuple(src-1, dest-1, dist));
  }

  long *dist = new long[N];
  for(int idx = 1; idx < N; idx++)
    dist[idx] = INT_MAX;
  dist[0] = 0;

  int len = edge.size();
  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < len; jdx++)
    {
      int src = get<0>(edge[jdx]);
      int dest = get<1>(edge[jdx]);
      int w = get<2>(edge[jdx]);

      if(dist[src] == INT_MAX)
        continue;

      if(dist[dest] > dist[src] + w)
        dist[dest] = dist[src] + w;
    }
  }

  long *check = new long[N];

  for(int idx = 0; idx < N; idx++)
    check[idx] = dist[idx];

  for(int jdx = 0; jdx < len; jdx++)
  {
    int src = get<0>(edge[jdx]);
    int dest = get<1>(edge[jdx]);
    int w = get<2>(edge[jdx]);

    if(dist[src] == INT_MAX)
      continue;

    if(dist[dest] > dist[src] + w)
      dist[dest] = dist[src] + w;
  }

  bool flag = true;
  for(int idx = 0; idx < N; idx++)
  {
    if(check[idx] != dist[idx])
    {
      flag = false;
      break;
    }
  }

  if(flag)
  {
    for(int idx = 1; idx < N; idx++)
    {
      if(dist[idx] == INT_MAX)
        cout << -1 << '\n';
      else
        cout << dist[idx] << '\n';
    }
  }
  else
    cout << -1 <<'\n';
}
