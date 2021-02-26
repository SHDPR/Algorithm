#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> tint;

struct compare{
  bool operator()(tint a, tint b)
  {
    return get<2>(a) > get<2>(b);
  }
};


int main()
{
  int testcase;
  cin >> testcase;

  for(int tc = 0; tc < testcase; tc++)
  {
    int N, M, K;
    cin >> N >> M >> K;

    /* Vector list of src[(dest, cost, time)] */
    vector<tint> *conn = new vector<tint>[N];
    for(int idx = 0; idx < K; idx++)
    {
      int u, v, c, d;
      cin >> u >> v >> c >> d;
      conn[u-1].push_back(make_tuple(v-1, c, d));
    }

    /* DP array of [idx][jdx] = [dest][cost] */
    int **dp = (int**)malloc(sizeof(int*) * N);
    for(int idx = 0; idx < N; idx++)
    {
      dp[idx] = (int*)malloc(sizeof(int) * (M+1));
      for(int jdx = 0; jdx < M+1; jdx++)
        dp[idx][jdx] = INT_MAX;
    }

    priority_queue<tint, vector<tint>, compare> dij;
    dp[0][0] = 0;
    dij.push(make_tuple(0, 0, 0));

    while(!dij.empty())
    {
      tint cur = dij.top();
      int cur_node = get<0>(cur);
      int cur_cost = get<1>(cur);
      int cur_time = get<2>(cur);
      dij.pop();

      int len = conn[cur_node].size();
      for(int idx = 0; idx < len; idx++)
      {
        tint next = conn[cur_node][idx];
        int next_node = get<0>(next);
        int next_cost = get<1>(next);
        int next_time = get<2>(next);

        int time_sum = cur_time + next_time;
        int cost_sum = cur_cost + next_cost;
        if(cost_sum <= M && dp[next_node][cost_sum] > time_sum)
        {
          dp[next_node][cost_sum] = time_sum;
          dij.push(make_tuple(next_node, cost_sum, time_sum));
        }
      }
    }
    
    int result = INT_MAX;

    for(int idx = 0; idx <= M; idx++)
      result = (result > dp[N-1][idx])? dp[N-1][idx] : result;

    if(result == INT_MAX)
      cout << "Poor KCM";
    else
      cout << result;

    cout << '\n';

    free(dp);
  }

}
