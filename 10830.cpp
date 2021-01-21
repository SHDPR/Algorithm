#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;                   // Type definition for long long in short ver
typedef vector<vector<ll>> matrix;      // Type definition for matrix by vector<vector<long long>>


matrix operator * (matrix &A, matrix &B){
  ll size = A.size();                   // Figure out size of matrix from matrix A
  matrix res(size, vector<ll>(size));   // Res matrix where result A * B is stored

  for(int idx = 0; idx < size; idx++){
    for(int jdx = 0; jdx < size; jdx++){
      for(int kdx = 0; kdx < size; kdx++){
        res[idx][jdx] += A[idx][kdx] * B[kdx][jdx];
      }
      res[idx][jdx] %= 1000;            // Divide by 1000 (Problem Condition)
    }
  }
  return res;
}

matrix power(matrix A, ll n){
  int size = A.size();
  matrix res(size, vector<ll>(size));

  for(int idx = 0; idx < size; idx++){
    res[idx][idx] = 1;                  // Initialization by identity matrix
  }

  while(n > 0){
    if(n % 2 == 1)
      res = res * A;                    // Example : A13 = A8*A4*A;
    n = n / 2;
    A = A * A;
  }
  return res;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  ll B;
  cin >> N >> B;

  matrix A(N, vector<ll>(N));           // Vector initialization (std::vector(element_count, intial_value);
  matrix result(N, vector<ll>(N));


  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++)
      cin >> A[idx][jdx];
  }

  result = power(A, B);

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      cout << result[idx][jdx] << " ";
    }
    cout << '\n';
  }
}
