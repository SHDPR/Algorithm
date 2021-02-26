#include <iostream>
using namespace std;

int main()
{
  int N, S;
  cin >> N >> S;

  int *arr = new int[N];

  for(int idx = 0; idx < N; idx++)
    cin >> arr[idx];

  int start = 0;
  int end = 0;
  int sum = arr[0];
  int len = 0;

  while(start < N)
  {
    if(sum >= S)
    {
      int cur_len = end - start + 1;
      if(len == 0 || cur_len < len)
        len = cur_len;

      sum -= arr[start++];
    }

    else if(end == N-1)
    {
      sum -= arr[start++];
    }

    else
    {
      sum += arr[++end];
    }
  }

  cout << len;
}
