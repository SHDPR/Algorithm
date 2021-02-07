#include <iostream>

using namespace std;

long long coeff(int N, int K){
  if(K == 0)
    return 1;
  if(K == N)
    return 1;
  return (coeff(N-1, K-1) + coeff(N-1, K)) % 1000000007;
}


int main(){
  long long N, K;
  cin >> N >> K;

  cout << coeff(N, K) << endl;
}
