#include <iostream>
using namespace std;
typedef long long ll;


ll compute_trees(ll trees[], ll height, int size){
  ll cnt = 0;
  for(int idx = 0; idx < size; idx++){
    if(trees[idx] > height)
      cnt += trees[idx] - height;
  }
  return cnt;
}

ll binary_trees(ll trees[], int size, ll start, ll end, ll target, ll max){
  ll mid = (start + end) / 2;
  ll cnt = compute_trees(trees, mid, size);

  if(cnt >= target){
    max = (mid > max)? mid : max;
    if(start >= end)
      return max;
    return binary_trees(trees, size, mid + 1, end, target, max);
  }
  else
    return binary_trees(trees, size, start, mid-1, target, max);
}






int main(){
  // N -> Num of trees, M -> Length of wood we need
  ll N, M;
  ll *trees;
  ll max_tree = 0;
  cin >> N >> M;
  trees = (ll*)malloc(sizeof(ll) * N);

  for(int idx = 0; idx < N; idx++){
    cin >> trees[idx];
    max_tree = (max_tree > trees[idx])? max_tree : trees[idx];
  }

  cout << binary_trees(trees, N, 0, max_tree, M, 0);


}
