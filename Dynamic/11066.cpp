#include <iostream>
#include <memory.h>
using namespace std;


int dp_solve(int pages[], int page_cnt)
{
  int **dp = (int**)malloc(sizeof(int*) * page_cnt);
  for(int idx = 0; idx < page_cnt; idx++)
  {
    dp[idx] = (int*)malloc(sizeof(int) * page_cnt);
    dp[idx][idx] = pages[idx];
  }

  int length = 1;

  while(length < page_cnt)
  {
    for(int idx = 0; idx + length < page_cnt; idx++)
    {
      //Calculate dp[idx][idx + length]
      int min = dp[idx][idx] + dp[idx + 1][idx + length];

      for(int jdx = idx; jdx < idx + length; jdx++)
      {
        int sum = dp[idx][jdx] + dp[jdx + 1][idx + length];
        min = (min < sum)? min : sum;
      }

      dp[idx][idx + length] = min;
    }
    length++;
  }
  return dp[0][page_cnt-1];
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
