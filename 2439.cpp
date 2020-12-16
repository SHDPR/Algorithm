#include <iostream>
using namespace std;

int main(){
  int N = -1;
  cin >> N;

  if(N > 100 || N < 1){
    throw out_of_range("N value out of range");
  }

  for(int i = 1; i < N+1; i++){
    for(int j = 1; j < N-i+1; j++){
      cout << " ";
    }
    for(int k = 1; k < i+1; k++){
      cout << "*";
    }
    cout << "\n";
  }
}
