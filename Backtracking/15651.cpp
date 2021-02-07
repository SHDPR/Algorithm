/*
Algorithm : Use depth-first-search on recursion

*/
#include <iostream>

using namespace std;

void dfs(int result[], int count, int M, int N){
  int start = 0;
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
    start = result[count-1];

  for(int i = start; i < N + 1; i++){
    result[count] = i;
    dfs(result, count + 1, M, N);
  }
}



int main(){
  int N, M;
  cin >> N >> M;

  if(N < M || N > 8)
    throw out_of_range("N M Value out of range");

  int result[M];


  dfs(result, 0, M, N);


}
