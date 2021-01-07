#include <iostream>
#include <stack>

using namespace std;

int main(){
  int K, input;
  int sum = 0;
  cin >> K;
  stack<int> st;

  for(int idx = 0; idx < K; idx++){
    cin >> input;
    if(input == 0)
      st.pop();
    else
      st.push(input);
  }

  while(!st.empty()){
    sum += st.top();
    st.pop();
  }
  cout << sum;
}
