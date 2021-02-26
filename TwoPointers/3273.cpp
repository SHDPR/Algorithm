#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int len;
  cin >> len;

  int *arr = new int[len];
  for(int idx = 0; idx < len; idx++)
    cin >> arr[idx];

  int target;
  cin >> target;

  /* 오름차순 정렬 */
  sort(arr, arr + len);

  int start = 0;
  int end = len-1;
  int cnt = 0;

  while(start < end)
  {
    int sum = arr[start] + arr[end];

    if(sum == target)
    {
      cnt++;
      start++;
      end--;
    }
    else if(sum < target)
      start++;
    else
      end--;
  }

  cout << cnt;


}
