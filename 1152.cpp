#include <iostream>
#include <string>

using namespace std;

int main(){
  string input;
  string::iterator iter;
  int cnt = 1;

  getline(cin, input);

  if(input.length() > 1000000){
    throw out_of_range("Input string length out of range");
  }

  if(input.empty()){
    cout << 0 << endl;
    return 0;
  }

  for(int idx = 0; idx < input.length(); idx++){
    if(input[idx] == ' ')
      cnt++;
  }

  if(input[0] == ' ')
    cnt--;

  if(input[input.length()-1] == ' ')
    cnt--;


  cout << cnt << endl;
}
