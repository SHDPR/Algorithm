#include <iostream>
using namespace std;

int main(){
  int n = 0;
  int cnt = 0;
  cin >> n;

  for(int idx = 5; idx <= n; idx += 5){
    cnt++;
  }

  for(int idx = 25; idx <= n; idx += 25){
    cnt++;
  }

  for(int idx = 125; idx <= n; idx += 125){
    cnt++;
  }

  cout << cnt;



}
