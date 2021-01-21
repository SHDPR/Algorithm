#include <iostream>
using namespace std;


int main(){
  int N, B;
  cin >> N >> B;
  int matrix[N][N];

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++)
      cin >> matrix[idx][jdx];
  }

}
