#include <iostream>
#define DIV 1000000000;
using namespace std;


int main(){

  int stair[2][10];

  for(int idx = 0; idx < 10; idx++){
    if(idx == 0)
      stair[0][idx] = 0;
    else
      stair[0][idx] = 1;
  }
  int sum = 0;
  int N = 0;
  cin >> N;
  if(!(N >= 1 && N <= 100))
    throw out_of_range("N value out of range");

  for(int ndx = 2; ndx <= N; ndx++){
    for(int idx = 0; idx < 10; idx++){
      int next = (ndx + 1)%2;
      int prev = ndx % 2;
      if(idx == 0)  stair[next][idx] = stair[prev][idx+1];
      else if(idx == 9)  stair[next][idx] = stair[prev][idx-1];
      else  stair[next][idx] = (stair[prev][idx+1] + stair[prev][idx-1]) % DIV;
    }
  }

  for(int idx = 0; idx < 10; idx++){
    sum = (sum + stair[(N + 1) % 2][idx]) % DIV;
  }

  cout << sum << endl;




}
