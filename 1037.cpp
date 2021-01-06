#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int num = 0;
  cin >> num;
  long long factor[num];
  for(int idx = 0; idx < num; idx++){
    cin >> factor[idx];
  }
  sort(factor, factor + num);

  cout << factor[num-1] * factor[0];
}
