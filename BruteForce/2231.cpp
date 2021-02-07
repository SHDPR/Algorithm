#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N, M;
  int sum;
  int cnt = 0;
  cin >> N;
  M = N;

  while(N != 0){
    N = N / 10;
    cnt++;
  }
  for(int idx = M - (cnt * 9); idx < M; idx++){
    sum = idx;
    for(int jdx = 0; jdx < cnt; jdx++){
      sum += (idx % (int)round((pow(10, jdx + 1)))) / (int)round((pow(10, jdx)));
    }
    if(sum == M){
      cout << idx;
      return 0;
    }
  }
  cout << 0;

}
