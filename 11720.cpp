#include <iostream>
#include <string>
using namespace std;

int main(){
  int location;
  string input = "";
  cin >> input;

  for(char x = 'a'; x < ('z' + 1); x++){
    location = input.find(x);
    cout << location << " ";
  }

  cout << endl;

}
