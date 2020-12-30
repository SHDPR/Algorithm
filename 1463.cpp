#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N = 0;
  cin >> N;

  int cnt[N+1] = {0,};

  for(int idx = 2; idx < N+1; idx++){
    cnt[idx] = 1 + cnt[idx-1];
    if(idx % 3 == 0)
      cnt[idx] = min(cnt[idx], 1 + cnt[idx/3]);
    if(idx % 2 == 0)
      cnt[idx] = min(cnt[idx], 1 + cnt[idx/2]);
  }

  cout << cnt[N] <<sizeof(int);


}
