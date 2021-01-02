#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n = 0;
  int output = 0;
  int input = 0;
  cin >> n;
  pair<int, int> lst[n+1] = {{0,0}, };

  for(int idx = 1; idx <= n; idx++){
    cin >> lst[idx].first;
    for(int jdx = 0; jdx < idx; jdx++){
      if(lst[idx].first > lst[jdx].first)
        lst[idx].second = max(lst[idx].second, lst[jdx].second + 1);
    }
    output = max(output, lst[idx].second);
  }


  cout << output;
}
