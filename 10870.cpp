#include <iostream>
using namespace std;

int fib(int n){
  if(n == 0)  return 0;
  if(n == 1)  return 1;

  return fib(n-1) + fib(n-2);
}

int fib2(int n){
  //int *fibo = (int *)malloc(sizeof(int) * (2*n));
  int *fibo = new int[n+2];
  fibo[0] = 0;
  fibo[1] = 1;

  for(int idx = 2; idx <= n; idx++){
    fibo[idx] = fibo[idx-1] + fibo[idx-2];
  }

  return fibo[n];

}


int main(){
  int n;
  cin >> n;

  cout << fib2(n) << endl;
}
