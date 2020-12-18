#include <iostream>

using namespace std;

int main(){
  int N = 0;
  int M = 1;
  int count = 1;
  cin >> N;

  if(N == 1){
    cout << count << endl;
    return 0;
  }

  while(N > M){
    count++;
    M += 6 * (count - 1);
  }

  cout << count << endl;
}
