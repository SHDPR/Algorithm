#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> dint;

struct compare
{
  bool operator()(dint a, dint b)
  {
    return a.second > b.second;
  }
};


int main()
{
  int testcase;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++)
  {
    int V, E, dest_num;
    cin >> V >> E >> dest_num;

    int start, stop_a, stop_b;
    cin >> start >> stop_a >> stop_b;
    start -= 1;
    stop_a -= 1;
    stop_b -= 1;

    vector<dint> *conn = new vector<dint>[V];
    for(int jdx = 0; jdx < E; jdx++)
    {
      int src, dest, dist;
      cin >> src >> dest >> dist;
      conn[src-1].push_back({dest-1, dist});
      conn[dest-1].push_back({src-1, dist});
    }

    int *target = new int[dest_num];
    for(int jdx = 0; jdx < dest_num; jdx++)
    {
      cin >> target[jdx];
      target[jdx] -= 1;
    }


    int *dist_start = new int[V];
    int *dist_stop_a = new int[V];
    int *dist_stop_b = new int[V];

    for(int jdx = 0; jdx < V; jdx++)
    {
      dist_start[jdx] = INT_MAX;
      dist_stop_a[jdx] = INT_MAX;
      dist_stop_b[jdx] = INT_MAX;
    }

    priority_queue<dint, vector<dint>, compare> dij;
    dist_start[start] = 0;
    dij.push({start, dist_start[start]});

    while(!dij.empty())
    {
      dint cur = dij.top();
      int cur_dist = dij.top().second;
      int cur_node = dij.top().first;
      dij.pop();

      int len = conn[cur_node].size();
      for(int jdx = 0; jdx < len; jdx++)
      {
        dint next = conn[cur_node][jdx];
        int route_dist = next.second;
        int next_node = next.first;

        if(route_dist + cur_dist < dist_start[next_node])
        {
          dist_start[next_node] = route_dist + cur_dist;
          dij.push({next_node, dist_start[next_node]});
        }
      }
    }

    dist_stop_a[stop_a] = 0;
    dij.push({stop_a, dist_stop_a[stop_a]});

    while(!dij.empty())
    {
      dint cur = dij.top();
      int cur_dist = dij.top().second;
      int cur_node = dij.top().first;
      dij.pop();

      int len = conn[cur_node].size();
      for(int jdx = 0; jdx < len; jdx++)
      {
        dint next = conn[cur_node][jdx];
        int route_dist = next.second;
        int next_node = next.first;

        if(route_dist + cur_dist < dist_stop_a[next_node])
        {
          dist_stop_a[next_node] = route_dist + cur_dist;
          dij.push({next_node, dist_stop_a[next_node]});
        }
      }
    }

    dist_stop_b[stop_b] = 0;
    dij.push({stop_b, dist_stop_b[stop_b]});

    while(!dij.empty())
    {
      dint cur = dij.top();
      int cur_dist = dij.top().second;
      int cur_node = dij.top().first;
      dij.pop();

      int len = conn[cur_node].size();
      for(int jdx = 0; jdx < len; jdx++)
      {
        dint next = conn[cur_node][jdx];
        int route_dist = next.second;
        int next_node = next.first;

        if(route_dist + cur_dist < dist_stop_b[next_node])
        {
          dist_stop_b[next_node] = route_dist + cur_dist;
          dij.push({next_node, dist_stop_b[next_node]});
        }
      }
    }

    vector<int> destination;

    int dist_inter = dist_stop_a[stop_b];

    for(int jdx = 0; jdx < dest_num; jdx++)
    {
      int candidate = target[jdx];
      if(dist_start[candidate] == INT_MAX)
        continue;

      int total_dist = dist_start[candidate];

      if(dist_start[stop_a] != INT_MAX && dist_stop_b[candidate] != INT_MAX)
      {
        if(dist_start[stop_a] + dist_inter + dist_stop_b[candidate] == total_dist)
        {
          destination.push_back(candidate);
          continue;
        }
      }

      if(dist_start[stop_b] != INT_MAX && dist_stop_a[candidate] != INT_MAX)
      {
        if(dist_start[stop_b] + dist_inter + dist_stop_a[candidate] == total_dist)
        {
          destination.push_back(candidate);
          continue;
        }
      }
    }

    sort(destination.begin(), destination.end());

    for(int n : destination)
    {
      cout << n+1 << " ";
    }

    free(target);
    free(dist_start);
    free(dist_stop_a);
    free(dist_stop_b);

  }
  cout << "\n";
}
