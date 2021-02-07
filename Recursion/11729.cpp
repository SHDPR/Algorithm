#include <iostream>
#include <cmath>
using namespace std;


void hanoi(int n, int from, int to, int by){
  if(n == 1){
    cout << from << ' ' << to << '\n';
    return;
  }

  hanoi(n-1, from, by, to);
  cout << from << ' ' << to << '\n';
  hanoi(n-1, by, to, from);

  return;
}



int main(){
  int num = 0;
  cin >> num;

  cout << (int)(pow(2, num) - 1) << endl;

  hanoi(num, 1, 3, 2);
}
