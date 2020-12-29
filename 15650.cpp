/*

Algorithm : Use depth-first-search on recursion

*/
#include <iostream>

using namespace std;

void dfs(bool tree[], int result[], int count, int M, int N){
  int start;
  if(count == M){
    for(int j = 0; j < M; j++){
      cout << result[j] << " ";
    }
    cout << '\n';
    return;
  }

  if(count == 0)
    start = 1;
  else
    start = result[count - 1];

  for(int i = start; i < N + 1; i++){
    if(tree[i] == false){
      result[count] = i;
      tree[i] = true;
      dfs(tree, result, count + 1, M, N);
      tree[i] = false;
    }
  }
}



int main(){
  int N, M;
  cin >> N >> M;

  if(N < M || N > 8)
    throw out_of_range("N M Value out of range");

  bool tree[N+1] = {false, };
  int result[M] = {1,};


  dfs(tree, result, 0, M, N);


}
