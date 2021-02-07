#include <iostream>
#include <cmath>
using namespace std;


bool prime(int input){
  if(input == 1){
    return false;
  }
  int fix = (int)sqrt(input);
  bool ret = true;
  for(int idx = 2; idx < fix + 1; idx++){
    ret = ret && (input % idx != 0);
  }

  return ret;
}

int main(){
  int num = 0;
  int input = 0;
  int count = 0;
  cin >> num;
  if(num > 100){
    throw out_of_range("Input N out of range");
  }

  for(int idx = 0; idx < num; idx++){
    cin >> input;
    if(prime(input)){
      count++;
    }

  }
  cout << count << endl;
}
