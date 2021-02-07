#include <iostream>
using namespace std;


int main(){
  int N, K;
  cin >> N >> K;

  int result = 1;

  for(int idx = N; idx > N-K; idx--){
    result *= idx;
  }

  for(int idx = 1; idx < K+1; idx++){
    result /= idx;
  }

  cout << result;
}
