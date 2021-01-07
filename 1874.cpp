#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


int main(){
  int n = 0;
  cin >> n;
  int input[n];
  char op[2*n];
  for(int idx = 0; idx < n; idx++){
    cin >> input[idx];
  }

  stack<int> st;
  int idx = 1;
  int jdx = 0;
  int kdx = 0;

  while(jdx < n){
    if(st.empty()){
      st.push(idx++);
      op[kdx++] = '+';
    }
    else if(st.top() > input[jdx]){
      cout << "NO";
      exit(0);
    }
    else if(st.top() == input[jdx]){
      st.pop();
      op[kdx++] = '-';
      jdx++;
    }
    else{
      st.push(idx++);
      op[kdx++] = '+';
    }
  }

  for(int ldx = 0; ldx < kdx; ldx++){
    cout << op[ldx] << '\n';
  }

}
