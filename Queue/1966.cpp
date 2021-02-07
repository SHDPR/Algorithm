#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


bool compare(int i, int j){
  return i > j;
}


int main(){
  int testcase = 0;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++){
    int N, M, tdx;
    pair<bool, int> tmp;
    bool check;
    cin >> N >> M;
    int *prior = (int*)malloc(sizeof(int) * N);
    queue<pair<bool, int>> queue;

    for(int jdx = 0; jdx < N; jdx++){
      cin >> prior[jdx];
      if(jdx == M)
        queue.push({true, prior[jdx]});
      else
        queue.push({false, prior[jdx]});
    }

    sort(prior, prior + N, compare);
    tdx = 0;
    check = false;

    while(!check){
      while(queue.front().second != prior[tdx]){
        tmp = queue.front();
        queue.pop();
        queue.push(tmp);
      }
      tdx++;
      check = queue.front().first;
      queue.pop();
    }
    free(prior);

    cout << tdx << '\n';
  }
}
