#include <iostream>
using namespace std;

int main(){
  int N = 0;
  int i = 665;
  int cnt = 0;
  cin >> N;

  while(1){
    int temp = ++i;
    int flag = 0;
    while(temp){
      if(temp % 1000 == 666){
        flag = 1;
        break;
      }
      temp = temp / 10;
    }
    if(flag){
      if(++cnt == N){
        break;
      }
    }
  }
  cout << i << endl;
}
