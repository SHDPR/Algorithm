#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n = 0;

  while(1){
    cin >> n;
    if(n > 123456)
      throw out_of_range("Testcase input n out of range");
    else if(n == 0)
      break;

    int count = 0;

    vector<int> eratos(2 * n + 1, 1);
    eratos[1] == 0;

    for(int idx = 2; idx <= sqrt(2 * n); idx++){
      if(eratos[idx] == 0)
        continue;
      for(int jdx = 2; jdx * idx <= 2 * n; jdx++)
        eratos[jdx * idx] = 0;
    }

    for(int idx = n + 1; idx <= 2 * n; idx++){
      if(eratos[idx] == 1)
        count++;
    }

    cout << count << '\n';
  }
}
