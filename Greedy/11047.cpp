#include <iostream>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  int penny[N];
  int cnt = 0;

  for(int idx = 0; idx < N; idx++){
    cin >> penny[idx];
  }

  for(int idx = N-1; idx >= 0; idx--){
    if(penny[idx] <= K){
      cnt += K / penny[idx];
      K = K % penny[idx];
    }
  }

  cout << cnt;
}
