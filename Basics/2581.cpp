#include <iostream>
#include <cmath>
using namespace std;

bool prime(int input){
  if(input == 1){
    return false;
  }
  int fix = (int)sqrt(input);
  bool ret = true;
  for(int idx = 2; idx < fix + 1; idx++){
    ret = ret && (input % idx != 0);
  }
  return ret;
}

int main(){
  int M, N;
  int sum = 0;


  cin >> M >> N;

  int max = (M > N)? M : N;
  int min = (M > N)? N : M;


  for(int idx = min; idx < max + 1; idx++){
    if(prime(idx)){
      if(sum == 0)  N = idx;
      sum += idx;
    }
  }

  if(sum == 0)
    cout << -1 << endl;
  else{
    cout << sum << '\n' << N << endl;
  }

}
