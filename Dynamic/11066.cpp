#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, int> pr;

int dp_solve(int pages[], int page_cnt)
{
  pr **dp = (pr**)malloc(sizeof(pr*) * page_cnt);
  for(int idx = 0; idx < page_cnt; idx++)
  {
    dp[idx] = (pr*)malloc(sizeof(pr) * page_cnt);
    dp[idx][idx].first = 0;
    dp[idx][idx].second = pages[idx];
  }

  int length = 1;

  while(length < page_cnt)
  {
    for(int idx = 0; idx + length < page_cnt; idx++)
    {
      //Calculate dp[idx][idx + length]
      int len = dp[idx][idx].second + dp[idx + 1][idx + length].second;
      int min = dp[idx][idx].first + dp[idx + 1][idx + length].first;

      for(int jdx = idx; jdx < idx + length; jdx++)
      {
        int sum = dp[idx][jdx].first + dp[jdx + 1][idx + length].first;
        min = (min < sum)? min : sum;
      }

      dp[idx][idx + length].first = min + len;
      dp[idx][idx + length].second = len;
    }
    length++;
  }
  return dp[0][page_cnt-1].first;
}


int main()
{
  int testcase = 0;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++)
  {
    int page_cnt = 0;
    cin >> page_cnt;

    int *pages = (int*)malloc(sizeof(int) * page_cnt);

    for(int jdx = 0; jdx < page_cnt; jdx++)
      cin >> pages[jdx];

    cout << dp_solve(pages, page_cnt) << '\n';

    free(pages);
  }

}
