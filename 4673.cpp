#include <iostream>
using namespace std;

int kaprekar(int n){
  return n + (n / 1000) + (n % 1000) / 100 + (n % 100) / 10 + (n % 10);
}



int main(){
  int n = 0;
  cin >> n;
  cout << kaprekar(n) << endl;
}
