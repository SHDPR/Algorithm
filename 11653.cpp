#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main(){
  int N = 0;
  cin >> N;

  vector<int> eratos(N + 1, 1);

  eratos[1] = 0;

  for(int idx = 2; idx <= sqrt(N); idx++){
    if(eratos[idx] == 0)
      continue;
    for(int jdx = 2; idx * jdx <= N; jdx++)
      eratos[idx * jdx] = 0;
  }


  for(int idx = 2; idx < N + 1; idx++){
    if(eratos[idx] == 1){
      while(N % idx == 0){
        cout << idx <<'\n';
        N = N / idx;
      }
    }
  }
}
