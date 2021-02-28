#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  pair<int, int> *memo = new pair<int, int>[N + 1];

  for(int idx = 0; idx <= N; idx++)
  {
    memo[idx] = {0, 1};
  }

  for(int idx = 2; idx <= N; idx++)
  {
    memo[idx] = {memo[idx-1].first + 1, idx - 1};

    if(idx % 3 == 0 && memo[idx].first > memo[idx / 3].first + 1)
    {
      memo[idx] = {memo[idx / 3].first + 1, idx / 3};
    }

    if(idx % 2 == 0 && memo[idx].first > memo[idx / 2].first + 1)
    {
      memo[idx] = {memo[idx / 2].first + 1, idx / 2};
    }
  }

  cout << memo[N].first << '\n';


  int start = N;

  while(start != 1)
  {
    cout << start << " ";
    start = memo[start].second;
  }

  cout << start;

}
