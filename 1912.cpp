#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n = 0;
  int input = 0;
  int maxsum = -1001;
  cin >> n;

  int *sumarr = (int *)malloc(sizeof(int) * (n+1));

  sumarr[0] = 0;


  for(int idx = 1; idx <= n; idx++){
    cin >> input;
    if(sumarr[idx-1] < 0){
      sumarr[idx] = input;
    }
    else{
      sumarr[idx] = input + sumarr[idx-1];
    }
    maxsum = max(sumarr[idx], maxsum);
  }

  cout << maxsum;
}
