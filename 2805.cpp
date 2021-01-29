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








int main(){
  // N -> Num of trees, M -> Length of wood we need
  ll N, M;
  ll *trees;
  ll max_tree = 0;
  cin >> N >> M;
  trees = (ll*)malloc(sizeof(ll) * N);

  for(int idx = 0; idx < N; idx++){
    cin >> trees[idx];
    max_tree = (max_tree > tree[idx])? max_tree : tree[idx];
  }




}
