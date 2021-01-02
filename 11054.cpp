#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N = 0;
  int output = 0;
  cin >> N;
  vector<int> input(N+1, 0);
  vector<int> bi(N+1, 1);
  vector<int> to(N+1, 1);

  for(int idx = 1; idx <= N; idx++)
    cin >> input[idx];

  for(int idx = 1; idx <= N; idx++){
    for(int jdx = 1; jdx < idx; jdx++){
      if(input[idx] > input[jdx])
        bi[idx] = max(bi[idx], bi[jdx] + 1);
      if(input[idx] < input[jdx])
        to[idx] = max(to[idx], max(to[jdx] + 1, bi[jdx] + 1));
    }
    output = max(max(bi[idx], to[idx]), output);
  }

  cout << output;
}
