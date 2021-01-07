#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int vps(char input[]){
  stack<char> br;
  int len = strlen(input);

  for(int idx = 0; idx < len; idx++){
    switch(input[idx]){
      case '(' :
        br.push(input[idx]);
        break;

      case '[' :
        br.push(input[idx]);
        break;

      case ')' :
        if(br.empty() || br.top() == '[')
          return 0;
        else
          br.pop();
        break;

      case ']' :
        if(br.empty() || br.top() == '(')
          return 0;
        else
          br.pop();
        break;

      default :
        continue;
    }
  }

  if(br.empty())
    return 1;
  else
    return 0;
}


int main(){
  char input[1000];
  while(true){
    cin.getline(input, 1000);
    if(strcmp(input, ".") == 0)
      exit(0);

    if(vps(input))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
