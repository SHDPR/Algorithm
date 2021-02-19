#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <memory.h>

using namespace std;
typedef pair<int, int> dint;

/* compare function for dint member in priority queue */
struct compare{
  bool operator()(dint a, dint b)
  {
    return a.second > b.second;
  }
};

int main()
{
  int V, E;
  cin >> V >> E;

  int start;
  cin >> start;
  start -= 1;

  vector<dint> *conn = new vector<dint>[V];
  for(int idx = 0; idx < E; idx++)
  {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    conn[src-1].push_back({dest-1, dist});
  }

  int *dist = new int[V];
  for(int idx = 0; idx < V; idx++)
    dist[idx] = INT_MAX;

  priority_queue<dint, vector<dint>, compare> dij;

  dist[start] = 0;
  dij.push({start, dist[start]});


  while(!dij.empty())
  {
    dint cur = dij.top();
    int cur_dist = dij.top().second;
    int cur_node = dij.top().first;
    dij.pop();

    int len = conn[cur_node].size();
    for(int idx = 0; idx < len; idx++)
    {
      dint next = conn[cur_node][idx];
      int route_dist = next.second;
      int next_node = next.first;

      if(route_dist + cur_dist < dist[next_node])
      {
        dist[next_node] = route_dist + cur_dist;
        dij.push({next_node, dist[next_node]});
      }
    }
  }


  for(int idx = 0; idx < V; idx++)
  {
    if(dist[idx] == INT_MAX)
      cout << "INF\n";
    else
      cout << dist[idx] << "\n";
  }


}
