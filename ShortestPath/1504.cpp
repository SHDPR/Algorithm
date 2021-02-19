#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
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
  int N, E;
  cin >> N >> E;

  vector<dint> *conn = new vector<dint>[N];
  for(int idx = 0; idx < E; idx++)
  {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    conn[src-1].push_back({dest-1, dist});
    conn[dest-1].push_back({src-1, dist});
  }

  int stop_a, stop_b;
  cin >> stop_a >> stop_b;
  stop_a -= 1;
  stop_b -= 1;

  int *dist_a = new int[N];
  int *dist_b = new int[N];
  int *dist_c = new int[N];

  for(int idx = 0; idx < N; idx++)
  {
    dist_a[idx] = INT_MAX;
    dist_b[idx] = INT_MAX;
    dist_c[idx] = INT_MAX;
  }

  priority_queue<dint, vector<dint>, compare> dij;
  dist_a[0] = 0;
  dij.push({0, dist_a[0]});

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

      if(route_dist + cur_dist < dist_a[next_node])
      {
        dist_a[next_node] = route_dist + cur_dist;
        dij.push({next_node, dist_a[next_node]});
      }
    }
  }

  dist_b[N-1] = 0;
  dij.push({N-1, dist_b[N-1]});

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

      if(route_dist + cur_dist < dist_b[next_node])
      {
        dist_b[next_node] = route_dist + cur_dist;
        dij.push({next_node, dist_b[next_node]});
      }
    }
  }

  dist_c[stop_a] = 0;
  dij.push({stop_a, dist_c[stop_a]});

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

      if(route_dist + cur_dist < dist_c[next_node])
      {
        dist_c[next_node] = route_dist + cur_dist;
        dij.push({next_node, dist_c[next_node]});
      }
    }
  }

  bool flag_inter = (dist_c[stop_b] == INT_MAX);
  bool flag_routea = (dist_a[stop_a] == INT_MAX || dist_b[stop_b] == INT_MAX);
  bool flag_routeb = (dist_a[stop_b] == INT_MAX || dist_b[stop_a] == INT_MAX);
  int route_a = dist_a[stop_a] + dist_c[stop_b] + dist_b[stop_b];
  int route_b = dist_a[stop_b] + dist_c[stop_b] + dist_b[stop_a];

/*
  cout << flag_inter << " " << flag_routea << " " << flag_routeb <<endl;
  cout << route_a << " " << route_b << endl;
*/

  if(flag_inter || (flag_routea && flag_routeb))
    cout << -1;
  else if(flag_routea)
    cout << route_b;
  else if(flag_routeb)
    cout << route_a;

  else
  {
    if(route_a > route_b)
      cout << route_b;
    else
      cout << route_a;
  }
}
