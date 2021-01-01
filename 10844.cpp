#include <iostream>
using namespace std;

#define DIV 1000000000;

int main(){
  int N = 0;
  cin >> N;

  int stair[N+1][10] = {{0,0,0,0,0,0,0,0,0,0}, };

  for(int idx = 1; idx < N+1; idx++){
    for(int jdx = 0; jdx < 10; jdx++){
      if(idx == 1){
        if(jdx == 0) stair[idx][jdx] = 0;
        else         stair[idx][jdx] = 1;
      }
      else{
        if(jdx != 0 && jdx != 9)
          stair[idx][jdx] = stair[idx-1][jdx-1] + stair[idx-1][jdx+1];
        else if(jdx == 0)
          stair[idx][jdx] = stair[idx-1][jdx+1];
        else
          stair[idx][jdx] = stair[idx-1][jdx-1];
      }
    }
  }

  int sum = 0;
  for(int idx = 0; idx < 10; idx++){
    sum += stair[N][idx];
  }

  cout << sum;

}
