#include <iostream>

using namespace std;

int main(){
  int M, N;
  int* arr = (int*)malloc(sizeof(int) * N);
  int close = 0;
  int answer = 0;
  cin >> N >> M;

  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
  }

  for(int idx = 0; idx < N; idx++){
    close = arr[idx];
    if(close > M)
      continue;
    for(int jdx = idx + 1; jdx < N; jdx++){
      close = arr[idx] + arr[jdx];
      if(close > M)
        continue;
      for(int kdx = jdx + 1; kdx < N; kdx++){
        close = arr[idx] + arr[jdx] + arr[kdx];
        if(close <= M && close > answer)
          answer = close;
      }
    }
  }

  cout << answer << endl;

}
