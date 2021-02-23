#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;

  int **dist = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    dist[idx] = (int*)malloc(sizeof(int) * N);
    for(int jdx = 0; jdx < N; jdx++)
    {
      if(idx == jdx)  dist[idx][jdx] = 0;
      else  dist[idx][jdx] = INT_MAX;
    }
  }

  for(int idx = 0; idx < M; idx++)
  {
    int src, dest, weight;
    cin >> src >> dest >> weight;

    if(dist[src-1][dest-1] > weight)
      dist[src-1][dest-1] = weight;
  }

  for(int kdx = 0; kdx < N; kdx++)
  {
    for(int src = 0; src < N; src++)
    {
      for(int dest = 0; dest < N; dest++)
      {
        if(dist[src][kdx] != INT_MAX && dist[kdx][dest] != INT_MAX)
        {
          if(dist[src][kdx] + dist[kdx][dest] < dist[src][dest])
            dist[src][dest] = dist[src][kdx] + dist[kdx][dest];
        }
      }
    }
  }

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      if(dist[idx][jdx] == INT_MAX)
        cout << 0 << " ";
      else
        cout << dist[idx][jdx] << " ";
    }
    cout << '\n';
  }



}
