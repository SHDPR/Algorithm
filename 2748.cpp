#include <iostream>

using namespace std;

int main(){
  int n = 0;
  cin >> n;

  long long *fib = (long long *)malloc(sizeof(long long) * (n+1));
  fib[0] = 0;
  fib[1] = 1;

  for(int i = 2; i <= n; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  cout << fib[n];
}
