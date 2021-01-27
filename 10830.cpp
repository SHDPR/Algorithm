#include <iostream>
#include <vector>


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, B;
  cin >> N >> B;
  int matrix[N][N];

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++)
      cout << matrix[idx][jdx];
  }



}
