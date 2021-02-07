#include <iostream>
using namespace std;

int main(){
  int N, M, K;
  cin >> N >> M;
  int arrone[N][M];

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < M; jdx++)
      cin >> arrone[idx][jdx];
  }

  cin >> M >> K;
  int arrtwo[M][K];

  for(int idx = 0; idx < M; idx++){
    for(int jdx = 0; jdx < K; jdx++)
      cin >> arrtwo[idx][jdx];
  }

  int arrmult[N][K];

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < K; jdx++){
      int sum = 0;
      for(int kdx = 0; kdx < M; kdx++){
        sum += arrone[idx][kdx] * arrtwo[kdx][jdx];
      }
      arrmult[idx][jdx] = sum;
    }
  }

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < K; jdx++){
      cout << arrmult[idx][jdx] << ' ';
    }
    cout << '\n';
  }


}
