#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

// Operator overloading for matrix
matrix operator * (matrix &A, matrix &B){
  int size = A.size();
  matrix res(size, vector<ll>(size));

  for(int idx = 0; idx < size; idx++){
    for(int jdx = 0; jdx < size; jdx++){
      for(int kdx = 0; kdx < size; kdx++)
        res[idx][jdx] += A[idx][kdx] * B[kdx][jdx];
      res[idx][jdx] %= 1000;
    }
  }
  return res;
}

matrix power(matrix &A, ll B){
  int size = A.size();
  matrix res(size, vector<ll>(size));
  // Set result as Identity matrix
  for(int idx = 0; idx < size; idx++){
    res[idx][idx] = 1;
  }

  while(B != 0){
    if(B % 2 == 1)
      res = res * A;
    A = A * A;
    B /= 2;
  }
  return res;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll N, B;
  cin >> N >> B;
  matrix input(N, vector<ll>(N));

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++)
      cin >> input[idx][jdx];
  }

  matrix result(N, vector<ll>(N));
  result = power(input, B);

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++)
      cout << result[idx][jdx] << " ";
    cout << '\n';
  }

}
