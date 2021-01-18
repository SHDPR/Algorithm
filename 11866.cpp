#include <iostream>
#include <queue>
using namespace std;

int main(){
  int N, K, tmp;
  cin >> N >> K;
  queue<int> queue;

  for(int idx = 1; idx <= N; idx++)
    queue.push(idx);

  cout << '<';


  while(queue.size() != 1){
    for(int idx = 0; idx < K-1; idx++){
      tmp = queue.front();
      queue.pop();
      queue.push(tmp);
    }
    cout << queue.front() << ", ";
    queue.pop();
  }
  cout << queue.front() << '>';
}
