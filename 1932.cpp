#include <iostream>
#include <cmath>
using namespace std;

pair<int, int> parent(int idx){
  int sum = 0;
  int i = 0;
  int first = 0;
  int second = 0;
  for(i = 1; sum < idx; i++){
    sum += i;
  }
  i--;
  first = ((idx-i) > (sum-(2*i)+1))? idx-i : 0;
  second = ((idx-i+1) < (sum-i+1))? idx-i+1 : 0;
  return {first, second};
}

int main(){
  int n = 0;
  int result = 0;
  cin >> n;
  int size = n * (n + 1) / 2;
  int tri[size + 1] = {0, };
  pair<int, int> node;

  for(int idx = 1; idx < size+1; idx++){
    cin >> tri[idx];
    node = parent(idx);
    tri[idx] += max(tri[node.first], tri[node.second]);
  }

  for(int idx = size-n+1; idx < size+1; idx++){
    result = max(result, tri[idx]);
  }

  cout << result;

}
