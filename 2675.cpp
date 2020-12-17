#include <iostream>
#include <string>

using namespace std;

int main(){
  int num_testcase = -1;
  int num_repeat = -1;
  string input = "";

  string::iterator iter;

  cin >> num_testcase;


  for(int idx = 0; idx < num_testcase; idx++){
    cin >> num_repeat >> input;
    for(iter = input.begin(); iter!= input.end(); iter++){
      for(int jdx = 0; jdx < num_repeat; jdx++){
        cout << *iter;
      }
    }
    cout << endl;
  }
}
