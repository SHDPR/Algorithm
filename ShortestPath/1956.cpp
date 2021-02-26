#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
  int V, E;

  cin >> V >> E;

  /* dist[idx][jdx] : distance of source(idx) to dest(jdx) */
  int **dist = (int**)malloc(sizeof(int*) * V);
  for(int idx = 0; idx < V; idx++)
  {
    dist[idx] = (int*)malloc(sizeof(int) * V);
    for(int jdx = 0; jdx < V; jdx++)
    {
      if(idx == jdx)  dist[idx][jdx] = 0;
      else  dist[idx][jdx] = INT_MAX;
    }
  }

  for(int idx = 0; idx < E; idx++)
  {
    int src, dest, weight;
    cin >> src >> dest >> weight;
    dist[src-1][dest-1] = weight;
  }

  for(int kdx = 0; kdx < V; kdx++)
  {
    for(int src = 0; src < V; src++)
    {
      for(int dest = 0; dest < V; dest++)
      {
        int dist_first = dist[src][kdx];
        int dist_second = dist[kdx][dest];
        if(dist_first != INT_MAX && dist_second != INT_MAX)
        {
          if(dist_first + dist_second < dist[src][dest])
            dist[src][dest] = dist_first + dist_second;
        }
      }
    }
  }

  int result = INT_MAX;
  for(int idx = 0; idx < V; idx++)
  {
    for(int jdx = idx + 1; jdx < V; jdx++)
    {
      if(dist[idx][jdx] == INT_MAX) continue;

      else if(dist[jdx][idx] != INT_MAX)
      {
        int dist_sum = dist[idx][jdx] + dist[jdx][idx];
        result = (result > dist_sum)? dist_sum : result;
      }
    }
  }

  if(result == INT_MAX)
    cout << -1;
  else
    cout << result;
}
