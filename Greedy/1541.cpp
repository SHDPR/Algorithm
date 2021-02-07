#include <iostream>
#include <string>
using namespace std;

int main(){
  string input;
  cin >> input;
  int temp = 0;
  int sum = 0;
  int su_flag = 0;
  int st_flag = 0;

  for(int idx = 0; idx < input.length(); idx++){
    switch(input[idx]){
      case '+' :
        if(st_flag == 0){
          sum += temp;
          st_flag = 1;
        }
        else if(su_flag == 0)
          sum += temp;
        else
          sum -= temp;
        temp = 0;
        break;
      case '-' :
        if(st_flag == 0){
          sum += temp;
          st_flag = 1;
        }
        else if(su_flag == 0)
          sum += temp;
        else
          sum -= temp;
        temp = 0;
        su_flag = 1;
        break;
      default:
        temp = temp * 10;
        temp += input[idx] - '0';
        break;
    }
  }
  if(st_flag == 0)
    sum += temp;
  else if(su_flag == 0)
    sum += temp;
  else
    sum -= temp;

  cout << sum;

}
