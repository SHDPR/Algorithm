#include <iostream>

using namespace std;

int main(){
  int x, y, w, h;
  cin >> x >> y >> w >> h;

  int x_close = (w - x) > x? x : (w - x);
  int y_close = (h - y) > y? y : (h - y);

  x_close = x_close > y_close? y_close : x_close;
  cout << x_close << '\n';

}
