#include <iostream>
#include <deque>

using namespace std;

int main(){
  deque<int> deq;
  int N, M, cnt, op;
  cin >> N >> M;
  int pos[M];

  for(int idx = 1; idx <= N; idx++)
    deq.push_back(idx);

  for(int idx = 0; idx < M; idx++)
    cin >> pos[idx];

  cnt = -1;
  op = 0;

  while(++cnt < M){
    int idx = 0;
    int size = deq.size();
    for(; idx < size; idx++){
      if(deq[idx] == pos[cnt])
        break;
    }

    if(size - idx > idx){
      for(int jdx = 0; jdx < idx; jdx++){
        int tmp = deq.front();
        deq.pop_front();
        deq.push_back(tmp);
      }
      deq.pop_front();
      op += idx;
    }
    else{
      for(int jdx = 0; jdx < size - idx; jdx++){
        int tmp = deq.back();
        deq.pop_back();
        deq.push_front(tmp);
      }
      deq.pop_front();
      op += (size - idx);
    }
  }

  cout << op << endl;


}
