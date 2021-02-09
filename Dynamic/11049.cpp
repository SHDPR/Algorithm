#include <iostream>
#include <memory.h>

using namespace std;

typedef pair<int, int> size_m;
typedef pair<size_m, int> size_cost;

int dp_solve(size_m matrix[], int cnt)
{
  size_cost **dp = (size_cost **)malloc(sizeof(size_cost*) * cnt);
  for(int idx = 0; idx < cnt; idx++)
  {
    dp[idx] = (size_cost*)malloc(sizeof(size_cost) * cnt);
    dp[idx][idx].first = matrix[idx];
    dp[idx][idx].second = 0;
  }

  int length = 1;

  while(length < cnt)
  {
    for(int idx = 0; idx + length < cnt; idx++)
    {
      //caculate dp[idx][idx + length]
      int min = 0;
      size_m mat_size = {dp[idx][idx].first.first, dp[idx+length][idx+length].first.second};

      for(int jdx = idx; jdx < idx + length; jdx++)
      {
        int sum = dp[idx][jdx].second + dp[jdx + 1][idx + length].second + dp[idx][jdx].first.first * dp[idx][jdx].first.second * dp[jdx + 1][idx + length].first.second;
        if(min == 0 || min > sum)
        {
          min = sum;
        }
      }

      dp[idx][idx + length].first = mat_size;
      dp[idx][idx + length].second = min;
    }
    length++;
  }

  int result = dp[0][cnt - 1].second;
  free(dp);
  return result;
}


int main()
{
  int cnt = 0;
  size_m *matrix;

  cin >> cnt;

  matrix = (size_m*)malloc(sizeof(size_m) * cnt);

  for(int idx = 0; idx < cnt; idx++)
  {
    cin >> matrix[idx].first;
    cin >> matrix[idx].second;
  }

  cout << dp_solve(matrix, cnt) << '\n';

  free(matrix);
}
