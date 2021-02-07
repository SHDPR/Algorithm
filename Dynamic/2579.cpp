#include <iostream>
#include <cmath>
using namespace std;


int main(){
  int stair[301] = {0, };
  int score[301] = {0, };
  int n = 0;
  cin >> n;
  for(int idx = 1; idx <= n; idx++){
    cin >> stair[idx];
    if(idx == 1){
      score[idx] = stair[idx];
    }
    if(idx == 2){
      score[idx] = stair[idx] + stair[idx-1];
    }
    if(idx >= 3)
      score[idx] = stair[idx] + stair[idx-1] + score[idx-3];
    if(idx >= 2)
      score[idx] = max(score[idx], stair[idx] + score[idx-2]);
  }

  cout << score[n];
}
