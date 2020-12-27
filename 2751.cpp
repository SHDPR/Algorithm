#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b){
  return a < b;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N = 0;
  cin >> N;
  int *arr = (int*)malloc(sizeof(int) * N);

  for(int idx = 0; idx < N; idx++)
    cin >> arr[idx];

  // Quick sort(nlogn algorithm)
  sort(arr, arr + N, compare);

  for(int idx = 0; idx < N; idx++)
    cout << arr[idx] << '\n';

}
