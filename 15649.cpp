/*
Algorithm : Use depth-first-search on recursion
Frankly, there's no need to declare array of pair<int, bool>.
Array of <int> will do fine.

*/
#include <iostream>

using namespace std;

void dfs(pair<int, bool> tree[], int result[], int count, int M, int N){
  if(count == M){
    for(int j = 0; j < M; j++){
      cout << result[j] << " ";
    }
    cout << '\n';
    return;
  }
  for(int i = 1; i < N + 1; i++){
    if(tree[i].second == false){
      result[count] = tree[i].first;
      tree[i].second = true;
      dfs(tree, result, count + 1, M, N);
      tree[i].second = false;
    }
  }
}



int main(){
  int N, M;
  cin >> N >> M;

  if(N < M || N > 8)
    throw out_of_range("N M Value out of range");

  pair<int, bool> tree[N+1];
  int result[M];

  for(int i = 0; i < N + 1; i++){
    tree[i].first = i;
    tree[i].second = false;
  }

  dfs(tree, result, 0, M, N);


}
