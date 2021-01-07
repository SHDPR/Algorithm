#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
  int n = 0;
  int idx = 1;
  cin >> n;
  vector<int> arr(n);
  vector<int> nge(n);
  stack<int> st;

  for(int jdx = 0; jdx < n; jdx++)
    cin >> arr[jdx];

  st.push(0);

  while(idx < n){
    while(!st.empty() && arr[idx] > arr[st.top()]){
      nge[st.top()] = arr[idx];
      st.pop();
    }
    st.push(idx);
    idx++;
  }

  while(!st.empty()){
    nge[st.top()] = -1;
    st.pop();
  }

  for(int jdx = 0; jdx < n; jdx++)
    cout << nge[jdx] << " ";

}
