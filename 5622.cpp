#include <iostream>
#include <string>

using namespace std;

int main(){
  string input;
  int sum = 0;
  int dial[8] = {3,6,9,12,15,19,22,26};
  cin >> input;

  if(input.length() > 15 || input.length() < 2)
    throw out_of_range("Input string length out of range");

  for(int idx = 0; idx < input.length(); idx++){
    int num = input[idx] - 'A' + 1;
    int jdx;
    for(jdx = 0; jdx < 8; jdx++){
      if(num <= dial[jdx]){
        break;
      }
    }
    sum += jdx + 3;
  }

  cout << sum << endl;
}
