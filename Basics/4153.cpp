#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int a, b, c;

  while(1){
    cin >> a >> b >> c;

    if((!(a|b|c))) break;

    a *= a;
    b *= b;
    c *= c;

    if(a + b == c || a + c == b || b + c == a)
      cout << "right" << '\n';
    else
      cout << "wrong" << '\n';
  }
}
