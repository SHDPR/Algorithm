#include <iostream>
#include <cmath>
using namespace std;


int gcf(int inputa, int inputb){
  int tmp, a, b;
  a = inputa;
  b = inputb;
  while(b != 0){
    tmp  = b;
    b = a % b;
    a = tmp;
  }
  return a;
}


int arrgcf(int arr[], int start, int end){
  int mid = (start + end) / 2;
  if(mid == start)
    return arr[start];

  return gcf(arrgcf(arr, start, mid), arrgcf(arr, mid + 1, end));
}



int main(){
  int N = 0;
  cin >> N;
  int arr[N];

  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
  }
  int tmp = arr[0];

  for(int idx = 0; idx < N; idx++){
    if(idx == N-1){
      arr[idx] = abs(tmp - arr[idx]);
    }
    else
      arr[idx] = abs(arr[idx+1] - arr[idx]);
  }

  tmp = 1;
  int result = arrgcf(arr, 0, N-1);

  for(int idx = 2; idx <= result/2; idx++){
    if(result % idx == 0)
      cout << idx << " ";
  }
  cout << result;
}
