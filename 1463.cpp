#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N = 0;
  cin >> N;
  /* If you declare array as int[N+1] form,
     the maximum size you can run without error is 25000
     In order not to get error for sizes over 25000,
     implement through dynamic allocation */
  int *cnt = (int*)malloc(sizeof(int) * (N+1));
  for(int idx = 0; idx < N+1; idx++){
    cnt[idx] = 0;
  }

  for(int idx = 2; idx < N+1; idx++){
    cnt[idx] = 1 + cnt[idx-1];
    if(idx % 3 == 0)
      cnt[idx] = min(cnt[idx], 1 + cnt[idx/3]);
    if(idx % 2 == 0)
      cnt[idx] = min(cnt[idx], 1 + cnt[idx/2]);
  }

  cout << cnt[N];


}
