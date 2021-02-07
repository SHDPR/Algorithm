#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
/* Main Idea
   Kth value is the result of binary search for x that satisfies the condition below.
   Count of n in A[][] that satisfies n <= x is k"
*/

ll compute_order(ll N, ll val){
  ll cnt = 0;
  for(ll idx = 1; idx <= N; idx++){
    cnt += min(N, val/idx);
  }
  return cnt;
}


ll binary_order(ll N, ll start, ll end, ll K, ll val){
  ll mid = (start + end) / 2;
  ll cnt = compute_order(N, mid);

  if(cnt >= K){
    val = mid;
    if(start >= end)
      return val;
    return binary_order(N, start, mid-1, K, val);
  }
  else{
    if(start >= end)
      return val;
    return binary_order(N, mid + 1, end, K, val);
  }

}


int main(){
  // N -> Dimension of array, K -> Kth value
  ll N, K;
  cin >> N >> K;

  cout << binary_order(N, 1, K*2, K, 1);
}
