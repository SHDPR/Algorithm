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
      res[idx][jdx] %= 1000000007;
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

/*

Use the fact below

| F(N+1)  F(N)  |   =   | 1   1 | ^ N
| F(N)    F(N-1)|       | 1   0 |

*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll B;
  cin >> B;
  matrix input(2, vector<ll>(2));
  matrix result(2, vector<ll>(2));
  input[0][0] = 1;
  input[0][1] = 1;
  input[1][0] = 1;
  input[1][1] = 0;

  result = power(input, B);

  cout << result[1][0];

}
