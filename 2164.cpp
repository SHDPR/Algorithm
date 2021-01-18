#include <iostream>
#include <queue>
using namespace std;

int main(){
  queue<int> num;
  int cnt = 0;
  int tmp = 0;
  cin >> cnt;

  for(int idx = 1; idx <= cnt; idx++)
    num.push(idx);

  while(num.size() != 1){
    num.pop();
    int tmp = num.front();
    num.pop();
    num.push(tmp);
  }

  cout << num.front() << endl;
}
