#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int compare(string a, string b){
  int length = a.length();
  if(a.length() == b.length()){
    for(int idx = 0; idx < length; idx++){
      if(a[idx] == b[idx])
        continue;
      return a[idx] < b[idx];
    }

  }
  return a.length() < b.length();
}


int main(){
  int N = 0;
  cin >> N;

  string input[N];

  for(int idx = 0; idx < N; idx++){
    cin >> input[idx];
  }

  sort(input, input + N, compare);

  for(int idx = 0; idx < N; idx++){
    if(idx >= 1 && input[idx] == input[idx - 1])
      continue;
    cout << input[idx] << '\n';
  }

}
