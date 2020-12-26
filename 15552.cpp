#include <iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int A, B, T;
  cin >> T;

  for(int idx = 0; idx < T; idx++){
    cin >> A >> B;
    cout << A + B << '\n';
  }

}
