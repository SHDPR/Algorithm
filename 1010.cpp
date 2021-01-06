#include <iostream>
using namespace std;

int pascal(int n, int k){
  int arr[n+1][n+1];
  for(int idx = 1; idx <= n; idx++){
    for(int jdx = 0; jdx <= idx; jdx++){
      if(idx == jdx || jdx == 0)
        arr[idx][jdx] = 1;
      else
        arr[idx][jdx] = (arr[idx-1][jdx] + arr[idx-1][jdx-1]);
    }
  }
  return arr[n][k];
}

int main(){
  int test = 0;
  cin >> test;
  for(int idx = 0; idx < test; idx++){
    int N, M;
    cin >> N >> M;
    cout << pascal(M, N) << '\n';
  }
}
