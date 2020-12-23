#include <iostream>
#include <cmath>
using namespace std;

bool prime(int input){
  if(input == 1){
    return false;
  }
  int fix = (int)sqrt(input);

  for(int idx = 2; idx < fix + 1; idx++){
    if(input % idx == 0)
      return false;
  }
  return true;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int M, N;
  cin >> M >> N;
  for(int idx = M; idx < N + 1; idx++){
    if(prime(idx))
      cout <<  idx << '\n';
  }
}
