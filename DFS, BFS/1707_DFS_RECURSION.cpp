#include <iostream>
#include <vector>
using namespace std;

void dfs(int *visit, vector<int> connection[], bool *bigraph, int V, int color)
{
  visit[V] = color;

  int len = connection[V].size();

  for(int idx = 0; idx < len; idx++)
  {
    int node = connection[V][idx];

    if(visit[node] == 0)
    {
      int next_color = (color == 1)? -1 : 1;
      dfs(visit, connection, bigraph, node, next_color);
    }

    else if(visit[node] == color)
    {
      *bigraph = false;
      return;
    }
  }
}




int main()
{
  int testcase = 0;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++)
  {
    int V, E;
    int *visit;

    cin >> V >> E;

    visit = (int*)malloc(sizeof(int) * V);
    for(int jdx = 0; jdx < V; jdx++)
      visit[jdx] = 0;

    vector<int> connection[V];
    for(int jdx = 0; jdx < E; jdx++)
    {
      int start, end;
      cin >> start >> end;
      connection[start-1].push_back(end-1);
      connection[end-1].push_back(start-1);
    }

    bool bigraph = true;

    for(int jdx = 0; jdx < V; jdx++)
    {
      if(visit[jdx] == 0)
        dfs(visit, connection, &bigraph, jdx, 1);
    }

    if(bigraph)
      cout << "YES\n";
    else
      cout << "NO\n";
    //call dfs here

    free(visit);
  }
}
