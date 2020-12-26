#include <iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, X;
  cin >> N >> X;

  int *arr = (int*)malloc(sizeof(int) * N);

  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
    if(X > arr[idx])
      cout << arr[idx] << " ";
  }

}
