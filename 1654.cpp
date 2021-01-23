#include <iostream>
#include <algorithm>

using namespace std;



int lan_search(int lan[], int size, int target, int start, int end){
  int mid;
  int cnt = 0;

  while(end > start){
    mid = (start + end) / 2;
    for(int idx = 0; idx < size; idx++)
      cnt+= lan[idx] / mid;

    if(cnt > target)
      end = mid;
    else
      start = mid + 1;
  }
  return end;
}




int main(){
  int K, N;
  cin >> K >> N;
  int lan[K];

  int max = 0;

  for(int idx = 0; idx < K; idx++){
    cin >> lan[idx];
    max = (lan[idx] > max)? lan[idx] : max;
  }


  cout << lan_search(lan, K, N, 1, max);






}
