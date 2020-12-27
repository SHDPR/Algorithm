#include <iostream>
#include <algorithm>

using namespace std;

struct coordinate{
  int x;
  int y;

  bool operator<(coordinate b){
    if(this->y == b.y)
      return this->x < b.x;
    else
      return this->y < b.y;
  }
};


int main(){
  int N = 0;
  int x, y;

  cin >> N;

  coordinate *arr = (coordinate*)malloc(sizeof(struct coordinate) * N);

  for(int idx = 0; idx < N; idx++){
    cin >> x >> y;
    arr[idx] = coordinate{x, y};
  }

  sort(arr, arr + N);

  for(int idx = 0; idx < N; idx++){
    cout << arr[idx].x << " " << arr[idx].y << '\n';
  }
}
