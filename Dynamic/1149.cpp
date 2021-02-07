#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N;
  cin >> N;

  int arr[N][3];
  int cost[N][3];

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < 3; jdx++){
      cin >> arr[idx][jdx];
    }
  }

  // Initial Condition
  cost[0][0] = arr[0][0];
  cost[0][1] = arr[0][1];
  cost[0][2] = arr[0][2];

  for(int idx = 1; idx < N; idx++){
    cost[idx][0] = arr[idx][0] + min(cost[idx-1][1], cost[idx-1][2]);
    cost[idx][1] = arr[idx][1] + min(cost[idx-1][0], cost[idx-1][2]);
    cost[idx][2] = arr[idx][2] + min(cost[idx-1][0], cost[idx-1][1]);
  }

  cout << min(min(cost[N-1][0], cost[N-1][1]), cost[N-1][2]);


}
