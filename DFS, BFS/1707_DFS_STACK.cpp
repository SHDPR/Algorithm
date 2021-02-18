#include <iostream>
#include <vector>
#include <stack>
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

    stack<int> st;
    int from = 1;
    bool bigraph = true;
    st.push(0);
    visit[0] = 1;

    while(!st.empty())
    {
      int cur = st.top();
      int color = visit[cur];
      int len = connection[cur].size();
      st.pop();

      for(int jdx = 0; jdx < len; jdx++)
      {
        int next = connection[cur][jdx];

        if(visit[next] == 0)
        {
          visit[next] = (color == 1)? -1 : 1;
          st.push(next);
        }
        else if(visit[next] == color)
        {
          bigraph = false;
          break;
        }
      }

      if(!bigraph)
        break;

      if(st.empty())
      {
        for(;from < V; from++)
        {
          if(visit[from] == 0)
            st.push(from);
        }
      }
    }

    if(bigraph)
      cout << "YES\n";
    else
      cout << "NO\n";
    //call dfs here

    free(visit);
  }
}
