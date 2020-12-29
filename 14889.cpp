#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int N;
int diff = INT_MAX;
int ability[20][20];
int start[20] = {0, };


int diff_value(){
  int sab = 0;
  int lab = 0;

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      if(start[idx] == 1 && start[jdx] == 1 && idx != jdx)
        sab += ability[idx][jdx];
      if(start[idx] == 0 && start[jdx] == 0 && idx != jdx)
        lab += ability[idx][jdx];
    }
  }
  return abs(sab - lab);

}


void divide(int cnt, int idx){
  if(cnt == N/2){
    diff = min(diff, diff_value());
    return;
  }

  for(int i = idx; i < N; i++){
    if(start[i] == 0){
      start[i] = 1;
      divide(cnt + 1, i + 1);
      start[i] = 0;
    }
  }

}

int main(){

  cin >> N;

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      cin >> ability[idx][jdx];
    }
  }

  divide(0, 0);

  cout << diff << endl;
}
