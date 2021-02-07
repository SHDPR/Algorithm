#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int testcase = 0;
  int input = 0;

  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++){
    cin >> input;
    vector<int> eratos(input + 1, 1);
    eratos[1] = 0;

    for(int kdx = 2; kdx <= sqrt(input); kdx++){
      if(eratos[kdx] == 0)
        continue;
      for(int jdx = 2; jdx * kdx <= input; jdx++)
        eratos[jdx * kdx] = 0;
    }

    for(int kdx = input / 2; kdx >= 2; kdx--){
      if(eratos[kdx] == 1 && eratos[input- kdx] == 1){
        cout << kdx << " " <<  input - kdx << '\n';
        break;
      }
    }
  }
}
