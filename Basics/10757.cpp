#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(){
  int a[10001] = {0, };
  int b[10001] = {0, };

  char input1[10001];
  char input2[10001];

  cin >> input1 >> input2;

  int length1 = strlen(input1);
  int length2 = strlen(input2);

  for(int idx = 10000; idx > 10000-length1; idx--){
    a[idx] = input1[(length1-1) - (10000-idx)] - '0';
  }
  for(int jdx = 10000; jdx > 10000-length2; jdx--){
    b[jdx] = input2[(length2-1) - (10000-jdx)] - '0';
  }


  int carry = 0;
  for(int idx = 10000; idx >= 0; idx--){
    if(a[idx] + b[idx] + carry >= 10){
      a[idx] = (a[idx] + b[idx] + carry) % 10;
      carry = 1;
    }
    else{
      a[idx] = a[idx] + b[idx] + carry;
      carry = 0;
    }
  }

  int flag = 0;

  for(int idx = 0; idx < 10001; idx++){
    if(a[idx] == 0 && flag == 0)
      continue;
    else{
      flag = 1;
      cout << a[idx];
    }
  }


}
