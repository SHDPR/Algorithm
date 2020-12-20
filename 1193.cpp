#include <iostream>
using namespace std;

int main(){
  int sum = 0;
  int loop = 1;
  int X = 0;
  cin >> X;
  while(sum + loop < X){
    sum += loop;
    loop++;
  }

  if(loop % 2 == 0){
    cout << X - sum << "/" << loop + 1 - X + sum << endl;
  }
  else{
    cout << loop + 1 - X + sum << "/" << X - sum << endl;
  }
}
