#include <iostream>
using namespace std;

int main(){
  int N = 0, T = 0;
  cin >> T;
  long long spiral[101] = {0,};
  for(int idx = 1; idx <= 5; idx++){
    spiral[idx] = (idx-1)/3 + 1;
  }

  for(int t = 0; t < T; t++){
    cin >> N;
    for(int idx = 6; idx <= N; idx++){
      if(spiral[idx] != 0)
        continue;
      spiral[idx] = spiral[idx-1] + spiral[idx-5];
    }
    cout << spiral[N] << '\n';
  }
}
