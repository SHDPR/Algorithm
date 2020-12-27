#include <iostream>
#include <vector>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  vector<int> count(10001,0);
  int N = 0;
  cin >> N;

  for(int idx = 0; idx < N; idx++){
    int input = 0;
    cin >> input;
    count[input]++;
  }

  for(int idx = 0; idx < 10001; idx++){
    for(int jdx = 0; jdx < count[idx]; jdx++){
      cout << idx << '\n';
    }
  }

}
