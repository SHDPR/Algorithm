#include <iostream>
using namespace std;

int main(){
  int T, N;
  pair<int, int> fib[41] = {{0,0},};
  fib[0] = {1,0};
  fib[1] = {0,1};


  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> N;
    for(int idx = 2; idx <= N; idx++){
      if(fib[idx] != pair<int, int>{0,0})
        continue;
      else
        fib[idx] = {fib[idx-1].first + fib[idx-2].first, fib[idx-1].second + fib[idx-2].second};
    }
    cout << fib[N].first << " " << fib[N].second << '\n';
  }

}
