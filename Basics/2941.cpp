#include <iostream>
#include <string>
using namespace std;

int main(){
  string input;
  int cnt = 1;
  getline(cin, input);

  if(input.length() > 100){
    throw out_of_range("Input string length out of range");
  }

  if(input.empty()){
    cout << 0 << endl;
    return 0;
  }

  for(int idx = 1; idx < input.length(); idx++){
    cnt++;
    switch(input[idx]){
      case '-' :
        cnt--;
        break;
      case '=' :
        cnt--;
        if(idx > 1 && input[idx-1] == 'z' && input[idx-2] == 'd')
          cnt--;
        break;
      case 'j' :
        if(input[idx-1] == 'l' || input[idx-1] == 'n')
          cnt--;
        break;
      default :
        break;
    }
  }

  cout << cnt << endl;
}
