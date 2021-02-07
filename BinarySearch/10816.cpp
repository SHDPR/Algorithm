#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int lower_bound(int input[], int target, int size){
  int mid;
  int start = 0;
  int end = size - 1;

  while(end > start){
    mid = (start + end) / 2;
    if(input[mid] >= target)
      end = mid;
    else
      start = mid + 1;
  }

  return end;
}


int upper_bound(int input[], int target, int size){
  int mid;
  int start = 0;
  int end = size - 1;

  while(end > start){
    mid = (start + end) / 2;
    if(input[mid] > target)
      end = mid;
    else
      start = mid + 1;
  }
  return end;
}


int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, M;
  int target;

  cin >> N;
  int input[N];

  for(int idx = 0; idx < N; idx++)
    cin >> input[idx];

  sort(input, input + N);

  cin >> M;
  for(int idx = 0; idx < M; idx++){
    cin >> target;
    int lower = lower_bound(input, target, N);
    int upper = upper_bound(input, target, N);

    if(upper == N-1 && input[N-1] == target){
      upper++;
    }

    cout << upper - lower << ' ';
  }
}
