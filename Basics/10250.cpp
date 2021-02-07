#include <iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int testcase;
  int H, W, N;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++){
    cin >> H >> W >> N;
    if(N % H != 0){
      cout << 100 * (N % H) + (N / H) + 1 << '\n';
    }
    else{
      cout << H * 100 + (N / H)<< '\n';
    }
  }
}
