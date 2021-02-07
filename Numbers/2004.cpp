#include <iostream>
#include <algorithm>
using namespace std;


long long ff5(long long n, long long k){
  long long cntd = 0;
  long long cntp = 0;
  for(long long idx = 5; idx <= n; idx *= 5){
    cntp += k/idx;
    cntd += n/idx - (n-k)/idx;
  }
  return cntd - cntp;
}

long long ff2(long long n, long long k){
  long long cntd = 0;
  long long cntp = 0;
  for(long long idx = 2; idx <= n; idx *= 2){
    cntp += k/idx;
    cntd += n/idx - (n-k)/idx;
  }
  return cntd - cntp;
}





int main(){
  long long n, m;
  cin >> n >> m;
  cout << min(ff2(n,m), ff5(n,m));
}
