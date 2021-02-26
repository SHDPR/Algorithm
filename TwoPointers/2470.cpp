#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int *fluidlist = new int[N];
  for(int idx = 0; idx < N; idx++)
    cin >> fluidlist[idx];

  sort(fluidlist, fluidlist + N);

  int start = 0;
  int end = N-1;

  int result = fluidlist[start] + fluidlist[end];
  pair<int, int> result_pair = {start, end};

  while(start < end)
  {
    int test = fluidlist[start] + fluidlist[end];
    if(test == 0)
    {
      result = test;
      result_pair = {start, end};
      break;
    }

    if(abs(test) < abs(result))
    {
      result = test;
      result_pair = {start, end};
    }

    if(test < 0)
      start++;

    else
      end--;
  }

  cout << fluidlist[result_pair.first] << " " << fluidlist[result_pair.second];

}
