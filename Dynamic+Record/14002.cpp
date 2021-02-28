#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int *input = new int[N];
  pair<int, int> *memo = new pair<int, int>[N];

  int maxlen = 0;
  int maxidx = 0;
  for(int idx = 0; idx < N; idx++)
  {
    memo[idx] = {1, idx};
    cin >> input[idx];

    int max = memo[idx].first;
    for(int jdx = 0; jdx < idx; jdx++)
    {
      if(input[idx] > input[jdx] && max < memo[jdx].first + 1)
      {
        memo[idx] = {memo[jdx].first + 1, jdx};
        max = memo[idx].first;
      }
    }

    if(max > maxlen)
    {
      maxlen = max;
      maxidx = idx;
    }

  }
  cout << maxlen << '\n';


  int start = maxidx;
  stack<int> output;

  while(start != memo[start].second)
  {
    output.push(input[start]);
    start = memo[start].second;
  }
  output.push(input[start]);

  while(!output.empty())
  {
    cout << output.top() << " ";
    output.pop();
  }


}
