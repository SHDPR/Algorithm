#include <iostream>
using namespace std;

int apart(int a, int b){
  int sum = 0;
  if(a == 1){
    sum += (b + 1) * b / 2;
  }
  else{
    for(int idx = 0; idx < b; idx++){
      sum += apart(a - 1, idx + 1);
    }
  }
  return sum;
}

int main(){
  int T, k, n;
  cin >> T;

  for(int idx = 0; idx < T; idx++){
    cin >> k >> n;
    cout << apart(k, n) << '\n';
  }
}
