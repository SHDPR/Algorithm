#include <iostream>
using namespace std;

int kaprekar(int n){
  return n + (n / 1000) + (n % 1000) / 100 + (n % 100) / 10 + (n % 10);
}

int main(){
  int numbers[10001] = {0,};
  int idx = 1;

  for(int i = 0; i < 10001; i++){
    if(kaprekar(i) < 10001)
      numbers[kaprekar(i)] = 1;
  }

  for(int i = 0; i < 10001; i++){
    if(numbers[i] == 0)
      cout << i << endl;
  }
}
