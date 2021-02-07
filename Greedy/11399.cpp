#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b){
  return a < b;
}
int main(){
  int N = 0;
  int sum = 0;
  cin >> N;

  int time[N];

  for(int i = 0; i < N; i++){
    cin >> time[i];
  }

  sort(time, time + N, compare);


  for(int i = 0; i < N; i++){
    sum += (N-i) * time[i];
  }

  cout << sum;

}
