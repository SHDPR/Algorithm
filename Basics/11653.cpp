#include <iostream>
#include <cmath>
using namespace std;


int main(){
  int N = 0;
  cin >> N;
  int idx = 2;

  while(N != 1){
    if(N % idx == 0){
      N /= idx;
      cout << idx << '\n';
    }
    else
      idx++;
  }
}
