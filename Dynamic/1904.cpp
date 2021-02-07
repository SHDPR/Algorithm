#include <iostream>

using namespace std;

int main(){
  int n = 0;
  cin >> n;

  int *fib = (int *)malloc(sizeof(int) * (n+1));
  fib[0] = 1;
  fib[1] = 1;

  for(int i = 2; i <= n; i++){
    fib[i] = fib[i-1] + fib[i-2];
    if(fib[i] >= 15746)
      fib[i] %= 15746;
  }

  cout << fib[n];
}
