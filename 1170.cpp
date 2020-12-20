#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int T = 0;
  double x, y;
  cin >> T;

  for(int idx = 0; idx < T; idx++){
    cin >> x >> y;
    int i = 0;
    int remainder = 0;
    while(pow(i + 1, 2) <= (y - x)){
      i++;
    }
    cout << i * 2 - 1 + ceil(((y -x) - pow(i, 2)) / (double)i) << endl;
  }
}
