#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef pair<int, int> dint;


int main()
{
  int N, M;
  cin >> N >> M;

  vector<dint> *conn = new vector<dint>[N];
  for(int idx = 0; idx < M; idx++)
  {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    conn[src-1].push_back({dest-1, dist});
  }

  int *dist = new int[N];
  dist[0] = 0;
  for(int idx = 1; idx < N; idx++)
    dist[idx] = INT_MAX;

  for(int idx = 0; idx < N; idx++)
  {
    int dist_here = dist[idx];
    if(dist_here == INT_MAX)
      continue;
    int len = conn[idx].size();
    for(int jdx = 0; jdx < len; jdx++)
    {
      int node_next = conn[idx][jdx].first;
      if(dist[node_next] == INT_MAX || dist[node_next] > dist_here + conn[idx][jdx].second)
        dist[node_next] = dist_here + conn[idx][jdx].second;
    }
  }

  int *dist_check = new int[N];
  for(int idx = 0; idx < N; idx++)
    dist_check[idx] = dist[idx];

  for(int idx = 0; idx < 1; idx++)
  {
    int dist_here = dist[idx];
    if(dist_here == INT_MAX)
      continue;
    int len = conn[idx].size();
    for(int jdx = 0; jdx < len; jdx++)
    {
      int node_next = conn[idx][jdx].first;
      if(dist[node_next] == INT_MAX || dist[node_next] > dist_here + conn[idx][jdx].second)
        dist[node_next] = dist_here + conn[idx][jdx].second;
    }
  }

  for(int idx = 1; idx < N; idx++)
  {
    if(dist_check[idx] != dist[idx] || dist[idx] == INT_MAX)
      cout << -1 << '\n';
    else
      cout << dist_check[idx] << '\n';
  }


}
