#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
typedef pair<int, int> dint;

struct compare{
  bool operator()(dint a, dint b)
  {
    if(a.second == -1)
      return true;
    else if(b.second == -1)
      return false;
    else
      return a > b;
  }
};


int main()
{
  int V, E;
  cin >> V >> E;

  int start;
  cin >> start;
  start -= 1;

  vector<dint> conn[V];
  for(int idx = 0; idx < E; idx++)
  {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    conn[src-1].push_back({dest-1, dist});
  }

  bool visit[V];
  memset(visit, 0, sizeof(visit));

  int dist[V];
  for(int idx = 0; idx < V; idx++)
    dist[idx] = -1;

  priority_queue<dint, vector<dint>, compare> dij;

  dist[start] = 0;
  dij.push({start, dist[start]});


  while(!dij.empty())
  {
    dint cur = dij.top();
    int cur_dist = dij.top().second;
    int cur_node = dij.top().first;
    dij.pop();

    if(visit[cur_node] == 1)
      continue;

    visit[cur_node] = 1;

    int len = conn[cur_node].size();
    for(int idx = 0; idx < len; idx++)
    {
      dint next = conn[cur_node][idx];
      int route_dist = next.second;
      int next_node = next.first;

      if(visit[next_node] == 0)
      {
        if(dist[next_node] == -1 || route_dist + cur_dist < dist[next_node])
        {
          dist[next_node] = route_dist + cur_dist;
          dij.push({next_node, dist[next_node]});
        }
      }
    }
  }

  for(int idx = 0; idx < V; idx++)
  {
    if(dist[idx] == -1)
      cout << "INF\n";
    else
      cout << dist[idx] << "\n";
  }


}
