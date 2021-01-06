#include <iostream>
using namespace std;


int pascal(int n, int k){
  int arr[n+1][n+1];
  for(int idx = 1; idx <= n; idx++){
    for(int jdx = 0; jdx <= idx; jdx++){
      if(idx == jdx || jdx == 0)
        arr[idx][jdx] = 1;
      else
        arr[idx][jdx] = (arr[idx-1][jdx] + arr[idx-1][jdx-1]) % 10000;
    }
  }
  return arr[n][k];
}






int main(){
  int N, K;
  cin >> N >> K;

  cout << pascal(N, K);
}
