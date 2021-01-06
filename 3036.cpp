#include <iostream>
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

int main(){
  int N = 0;
  cin >> N;
  int arr[N];
  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
  }

  for(int idx = 1; idx < N; idx++){
    int factor = gcf(arr[0], arr[idx]);
    cout << arr[0]/factor << '/' << arr[idx]/factor << '\n';
  }


}
