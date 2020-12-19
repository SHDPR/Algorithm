#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int A, B, V;
  int sum = 0;
  int cnt = 0;

  cin >> A >> B >> V;

  if((V-A) % (A-B) == 0){
    cout << (V-A) / (A-B) + 1 << endl;
  }
  else{
    cout << (V-A) / (A-B) + 2 << endl;
  }
}
