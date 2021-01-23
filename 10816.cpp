#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int start, int end, int max, int target, vector<pair<int,int>> input){
  int flag = (start + end) / 2;

  if(input[flag].first == target){
    return input[flag].second;
  }

  if(start == end)
    return 0;

  if(input[flag].first < target)
    return binary_search(flag + 1, end, max, target, input);

  if(target < input[flag].first)
    return binary_search(start, flag, max, target, input);
}



int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  int target, tmp, pdx;

  cin >> N;
  int input[N];
  vector<pair<int, int>> inputpair(N);
  for(int idx = 0; idx < N; idx++)
    cin >> input[idx];

  sort(input, input + N);

  pdx = 0;
  tmp = input[0];
  inputpair[0] = {tmp, 1};

  for(int idx = 1; idx < N; idx++){
    if(tmp == input[idx])
      inputpair[pdx].second++;
    else{
      tmp = input[idx];
      inputpair[++pdx] = {tmp, 1};
    }
  }

  // Binary search for M values
  cin >> M;
  for(int idx = 0; idx < M; idx++){
    cin >> target;
    cout << binary_search(0, pdx, pdx, target, inputpair) << ' ';
  }
}
