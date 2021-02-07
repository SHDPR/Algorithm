#include <iostream>
#include <string>
using namespace std;

int main(){
  int count[26] = {0,};
  string input;
  string::iterator iter;

  cin >> input;


  if(input.length() > 1000000){
    throw out_of_range("Input string out of range");
  }

  for(iter = input.begin(); iter != input.end(); iter++){
    int idx = (((char)(*iter) - 'a') < 0)? ((char)(*iter) - 'A') : ((char)(*iter) - 'a');
    count[idx]++;
  }

  int max = 0;
  int flag = 0;
  for(int jdx = 1; jdx < 26; jdx++){
    if(count[jdx] > count[max]){
      max = jdx;
      flag = 0;
    }
    else if(count[jdx] == count[max]){
      flag = 1;
    }
  }

  if(flag == 1){
    cout << '?' << endl;
  }
  else{
    cout << (char)(max + 'A') << endl;
  }

}
