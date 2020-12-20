#include <iostream>
using namespace std;

int main(){
  int testcase = 0;
  int H, W, N;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++){
    cin >> H >> W >> N;
    if(N % H != 0){
      cout << 100 * (N % H) + (N / H) + 1 << endl;
    }
    else{
      cout << H * 100 + (N / H)<< endl;
    }
  }
}
