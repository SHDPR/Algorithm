#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

    vector<int> connection[V];


    for(int jdx = 0; jdx < V; jdx++)
      visit[jdx] = 0;

    for(int jdx = 0; jdx < E; jdx++)
    {
      int start, end;
      cin >> start >> end;

      connection[start-1].push_back(end-1);
      connection[end-1].push_back(start-1);
    }

    bool flag = false;

    queue<int> bfs;
    bfs.push(0);
    visit[0] = 1;


    while(true)
    {
      int all_visited = true;

      if(bfs.empty())
      {
        for(int idx = 0; idx < V; idx++)
        {
          if(visit[idx] == 0)
          {
            bfs.push(idx);
            visit[idx] = 1;
            all_visited = false;
            break;
          }
        }

        if(all_visited)
          break;
      }

      int x = bfs.front();
      int check = visit[x];

      bfs.pop();

      for(int jdx = 0; jdx < connection[x].size(); jdx++)
      {
        int next_x = connection[x][jdx];

        if(visit[next_x] == check)
        {
          flag = true;
          break;
        }

        if(visit[next_x] == 0)
        {
          visit[next_x] = (check == 1)? -1 : 1;
          bfs.push(next_x);
        }
      }

      if(flag) break;
    }

    if(flag)  cout << "NO\n";
    else  cout << "YES\n";

    free(visit);
  }

}
