#include <iostream>
#include <map>

using namespace std;

int main(){
  map<int, int> rect_x;
  map<int, int> rect_y;
  map<int, int>::iterator iter;
  int x, y;

  for(int idx = 0; idx < 3; idx++){
    cin >> x >> y;

    iter = rect_x.find(x);

    if(rect_x.find(x) != rect_x.end())
      rect_x[x]++;
    else
      rect_x[x] = 1;

    iter = rect_y.find(y);

    if(rect_y.find(y) != rect_y.end())
      rect_y[y]++;
    else
      rect_y[y] = 1;
  }

  for(iter = rect_x.begin(); iter != rect_x.end(); iter++){
    if(iter->second == 1){
      cout << iter->first << " ";
    }
  }

  for(iter = rect_y.begin(); iter != rect_y.end(); iter++){
    if(iter->second == 1){
      cout << iter->first << endl;
    }
  }
}
