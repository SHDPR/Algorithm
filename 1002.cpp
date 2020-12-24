#include <iostream>
#include <cmath>

using namespace std;


struct point{
  double x;
  double y;
};

double dis(point p1, point p2){
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}



int main(){
  int testcase = 0;
  double x1, y1, r1, x2, y2, r2;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    point p1 = {x1, y1};
    point p2 = {x2, y2};

    double dist = dis(p1, p2);
    double cnt = 0;

    if(dist == 0 && r1 == r2){
      cout << -1 << endl;
      return 0;
    }

    else if(r1 + r2 < dist){
      cout << 0 << endl;
    }
    else if(r1 + r2 == dist){
      cout << 1 << endl;
    }
    else if(r1 + r2 > dist && abs(r1 - r2) < dist){
      cout << 2 << endl;
    }
    else if(abs(r1 - r2) == dist){
      cout << 1 << endl;
    }
    else if(abs(r1 - r2) > dist){
      cout << 0 << endl;
    }
    else{
      cout << 2 << endl;
    }
  }
}
