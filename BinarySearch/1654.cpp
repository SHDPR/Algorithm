#include <iostream>

using namespace std;

typedef long long ll;

ll compute_lines(ll lines[], ll len, int size){
  ll cnt = 0;
  for(int idx = 0; idx < size; idx++)
    cnt += (lines[idx] / len);
  return cnt;
}


ll binary_lines(ll lines[], int size, ll start, ll end, int target, ll max){
  ll mid = (start + end) / 2;
  ll cnt = compute_lines(lines, mid, size);

  if(cnt >= target){
    max = (mid > max)? mid : max;
    if(start >= end)
      return max;
    return binary_lines(lines, size, mid + 1, end, target, max);
  }
  else
    return binary_lines(lines, size, start, mid - 1, target, max);
}



int main(){
  // K -> Num of Input, N -> Num of Output
  int K, N;
  ll *lines;
  ll max_line = 0;
  cin >> K >> N;
  lines = (ll*) malloc(sizeof(ll) * K);

  for(int idx = 0; idx < K; idx++){
    cin >> lines[idx];
    max_line = (max_line > lines[idx])? max_line : lines[idx];
  }

  cout << binary_lines(lines, K, 1, max_line, N, 0);

}
