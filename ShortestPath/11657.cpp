#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;


int main()
{
  long long N, M;

  cin >> N >> M;

  vector<tuple<long long, long long, long long>> edge;
  for(long long idx = 0; idx < M; idx++)
  {
    long long src, dest, dist;
    cin >> src >> dest >> dist;
    edge.push_back(make_tuple(src-1, dest-1, dist));
  }

  long long *dist = new long long[N];
  for(long long idx = 1; idx < N; idx++)
    dist[idx] = INT_MAX;
  dist[0] = 0;

  long long len = edge.size();
  for(long long idx = 0; idx < N; idx++)
  {
    for(long long jdx = 0; jdx < len; jdx++)
    {
      long long src = get<0>(edge[jdx]);
      long long dest = get<1>(edge[jdx]);
      long long w = get<2>(edge[jdx]);

      if(dist[src] == INT_MAX)
        continue;

      if(dist[dest] > dist[src] + w)
        dist[dest] = dist[src] + w;
    }
  }

  long long *check = new long long[N];

  for(long long idx = 0; idx < N; idx++)
    check[idx] = dist[idx];

  for(long long jdx = 0; jdx < len; jdx++)
  {
    long long src = get<0>(edge[jdx]);
    long long dest = get<1>(edge[jdx]);
    long long w = get<2>(edge[jdx]);

    if(dist[src] == INT_MAX)
      continue;

    if(dist[dest] > dist[src] + w)
      dist[dest] = dist[src] + w;
  }

  bool flag = true;
  for(long long idx = 0; idx < N; idx++)
  {
    if(check[idx] != dist[idx])
    {
      flag = false;
      break;
    }
  }

  if(flag)
  {
    for(long long idx = 1; idx < N; idx++)
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
