#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int compute_pos(ll pos[], ll interval, int size){
  int cnt = 1;
  int prev = pos[0];
  for(int idx = 1; idx < size; idx++){
    int dist = pos[idx] - prev;
    if(dist >= interval){
      prev = pos[idx];
      cnt++;
    }
  }
  return cnt;
}

ll binary_pos(ll pos[], int size, ll start, ll end, int C, ll max){
  ll mid = (start + end) / 2;
  int cnt = compute_pos(pos, mid, size);

  if(cnt >= C){
    max = (mid > max)? mid : max;
    if(start >= end)
      return max;
    return binary_pos(pos, size, mid + 1, end, C, max);
  }
  else
    return binary_pos(pos, size, start, mid - 1, C, max);
}



int main(){
  int N, C;
  ll *pos;

  cin >> N >> C;
  pos = (ll*)malloc(sizeof(ll) * N);

  for(int idx = 0; idx < N; idx++){
    cin >> pos[idx];
  }

  sort(pos, pos + N);


  cout << binary_pos(pos, N, 0, pos[N-1] - pos[0], C, 0);

}
