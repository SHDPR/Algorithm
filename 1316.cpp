#include <iostream>
#include <string>

using namespace std;

int main(){
  string input = "";
  int repeat = 0;
  int cnt = 0;


  cin >> repeat;

  for(int jdx = 0; jdx < repeat; jdx++){
    cnt++;
    int alphabet[26] = {0, };
    cin >> input;

    if(input.length() > 100){
      throw out_of_range("String input length out of range");
    }
    else if(input.empty()){
      break;
    }

    for(int idx = 0; idx < input.length(); idx++){
      if(input[idx] == input[idx - 1] && idx > 0)
        continue;
      else
        alphabet[input[idx] - 'a']++;
    }

    for(int idx = 0; idx < 26; idx++){
      if(alphabet[idx] > 1){
        cnt--;
        break;
      }
    }
  }

  cout << cnt << endl;

}
