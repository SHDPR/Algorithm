#include <iostream>
#include <string>
using namespace std;

int main(){
  int n = 0;
  string input;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> input;
    int len = input.length();
    int sum = 0;
    int scores[len];

    for(int i = 0; i < len; i++){
      if(input[i] == 'O'){
        if(i == 0) scores[i] = 1;
        else scores[i] = scores[i-1] + 1;
      }
      else{
        scores[i] = 0;
      }
      sum += scores[i];
    }
    cout << sum << endl;
  }
}
