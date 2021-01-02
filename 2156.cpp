#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n = 0;
  cin >> n;
  int glass[n+1] = {0, };
  int qt[n+1] = {0, };


  for(int idx = 1; idx <= n; idx++){
    cin >> qt[idx];
    switch(idx){
      case 1 :
        glass[idx] = qt[idx];
        break;
      case 2 :
        glass[idx] = qt[idx] + glass[idx-1];
        break;
      default :
        glass[idx] = max(glass[idx-1], max(qt[idx] + glass[idx-2], qt[idx] + qt[idx-1] + glass[idx-3]));
        break;
    }
  }

  cout << glass[n] << endl;
}
