#include <iostream>
using namespace std;

int main(){
  int n = -1;
  cin >> n;
  if(n < 1 || n > 9){
    throw out_of_range("N value error");
  }
  for(int i = 1; i < 10; i++){
    cout << n << " * " << i << " = " << n * i << endl;
  }

  return 0;
}
