#include <iostream>
#include <algorithm>
using namespace std;


int binary_search(int start, int end, int target, int input[]){
  int flag = (start + end) / 2;

  if(input[flag] == target)
    return 1;

  if(start == end)
    return 0;

  if(input[flag] < target)
    return binary_search(flag + 1, end, target, input);

  if(target < input[flag])
    return binary_search(start, flag, target, input);
}



int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  int target;
  // Input of N values
  cin >> N;
  int input[N];
  for(int idx = 0; idx < N; idx++)
    cin >> input[idx];

  // Sort of N values
  sort(input, input + N);

  // Binary search for M values
  cin >> M;
  for(int idx = 0; idx < M; idx++){
    cin >> target;
    cout << binary_search(0, N-1, target, input) << '\n';
  }

}
