#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int vps(char input[]){
  stack<char> st;
  int len = strlen(input);

  for(int idx = 0; idx < len; idx++){
    switch(input[idx]){
      case '(' :
        st.push(input[idx]);
        break;
      case ')' :
        if(st.empty())
          return 0;
        else
          st.pop();
    }
  }

  if(st.empty())
    return 1;
  else
    return 0;
}


int main(){
  char input[50];
  int n;
  cin >> n;
  for(int idx = 0; idx < n; idx++){
    cin >> input;
    if(vps(input))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
