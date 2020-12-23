#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int M, N;
  cin >> M >> N;

  vector<int> eratos(N + 1, 1);

  eratos[1] = 0;

  for(int idx = 2; idx <= sqrt(N); idx++){
    if(eratos[idx] == 0)
      continue;
    for(int jdx = 2; idx * jdx <= N; jdx++)
      eratos[idx * jdx] = 0;
  }

  for(int idx = M; idx <= N; idx++){
    if(eratos[idx] == 1)
      cout << idx << '\n';
  }
}
