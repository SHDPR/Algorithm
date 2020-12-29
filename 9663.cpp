#include <iostream>

using namespace std;


bool possible(int i, int row[]){
  for(int idx = 0; idx < i; idx++){
    if(row[idx] == row[i] || (i - idx) == abs(row[i] - row[idx]))
      return false;
  }
  return true;
}



void queen(int i, int N, int row[], int *result){
  if(N == i){
    *result += 1;
    return;
  }

  for(int j = 0; j < N; j++){
    row[i] = j;
    if(possible(i, row)){
      queen(i+1, N, row, result);
    }
  }
  return;
}




int main(){
  int N;
  cin >> N;

  int row[N];
  int result = 0;

  queen(0, N, row, &result);

  cout << result << endl;
}
