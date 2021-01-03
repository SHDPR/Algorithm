#include <iostream>
#include <cmath>

using namespace std;

/* Knapsack problem solving by dynamic programming */
void knapsack_dp(){
  int N, W;
  cin >> N >> W;
  //things[N][0] -> weight, things[N][1] -> value
  int things[N][2];
  // dp array
  int knapdp[N][W+1];
  int maxvalue = 0;

  for(int idx = 0; idx < N; idx++){
    cin >> things[idx][0] >> things[idx][1];
    for(int jdx = 0; jdx < W+1; jdx++){
      if(idx == 0){
        if(jdx >= things[idx][0])
          knapdp[idx][jdx] = things[idx][1];
        else
          knapdp[idx][jdx] = 0;
      }
      else if(jdx >= things[idx][0]){
        knapdp[idx][jdx] = max(knapdp[idx-1][jdx-things[idx][0]] + things[idx][1], knapdp[idx-1][jdx]);
      }
      else{
        knapdp[idx][jdx] = knapdp[idx-1][jdx];
      }
    }
  }
  cout << knapdp[N-1][W];
}




int main(){
  knapsack_dp();
}
