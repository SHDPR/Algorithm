#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long upperbound(int start, int end, long long target, vector<long long> group)
{
  int mid = (start + end) / 2 + 1;
  long long value = group[mid];

  if(start == end)
    return start;

  if(target >= value)
    return upperbound(mid, end, target, group);
  else
    return upperbound(start, mid - 1, target, group);
}


long long iter_upperbound(vector<long long> group, long long target, int size)
{
  int mid;
  int start = 0;
  int end = size - 1;

  while(end > start)
  {
    mid = (start + end) / 2 + 1;
    if(target >= group[mid])
      start = mid;
    else
      end = mid - 1;
  }
  return end;
}


void dfs_push(int start, int end, long long weight, vector<long long> *group, vector<long long> things)
{
  if(start > end)
    (*group).push_back(weight);
  else
  {
    dfs_push(start + 1, end, weight, group, things);
    dfs_push(start + 1, end, weight + things[start], group, things);
  }
}



int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  long long C;
  cin >> N >> C;

  vector<long long> things;
  for(int idx = 0; idx < N; idx++)
  {
    long long input;
    cin >> input;
    things.push_back(input);
  }

  vector<long long> former, latter;

  dfs_push(0, N / 2, 0, &former, things);
  dfs_push(N / 2 + 1, N - 1, 0, &latter, things);

  sort(former.begin(), former.end());

  long long ret = 0;

  for(int idx = 0; idx < latter.size(); idx++)
  {
    ret += iter_upperbound(former, C - latter[idx], former.size()) + 1;
  }

  cout << ret;

}
