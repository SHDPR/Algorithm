#include <iostream>
using namespace std;

int main(){
  int N = -1;
  cin >> N;

  int cycle = 0;
  int M = N;

  if(N < 0 || N > 99){
    throw out_of_range("N value out of range");
  }

  M = (M % 10) * 10 + ((M / 10) + (M % 10)) % 10;
  cycle++;

  while(M != N){
    M = (M % 10) * 10 + ((M / 10) + (M % 10)) % 10;
    cycle++;
  }

  cout << cycle << endl;
}
