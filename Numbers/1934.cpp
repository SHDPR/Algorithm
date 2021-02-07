#include <iostream>
using namespace std;

// Algorithm using Euclidean Algorithm

int main(){
  int inputa, inputb, num;
  cin >> num;
  for(int idx = 0; idx < num; idx++){
    cin >> inputa >> inputb;
    int a = inputa;
    int b = inputb;
    int tmp;

    while(b != 0){
      tmp = b;
      b = a % b;
      a = tmp;
    }
    b = a * (inputa / a) * (inputb / a);

    cout << b << '\n';

  }
}
