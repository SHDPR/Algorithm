#include <iostream>
using namespace std;



long long divconq(long long target, long long pow, long long div){
  if(pow == 1)
    return target % div;

  long long tmp = divconq(target, pow/2, div);

  if(pow % 2 == 0)
    return (tmp * tmp) % div;

  else
    return (tmp * tmp) % div * target % div;
}


int main(){
  long long A, B, C;
  cin >> A >> B >> C;
  cout << divconq(A, B, C);
}
