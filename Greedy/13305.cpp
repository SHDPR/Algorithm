#include <iostream>
#include <algorithm>
using namespace std;

long long compare(pair<long long, long long> a, pair<long long, long long> b){
  return a.first < b.first;
}



int main(){
  long long N;
  cin >> N;
  long long dist[N-1];
  pair<long long, long long> city[N];
  long long sum = 0;

  for(long long idx = 0; idx < N-1; idx++)
    cin >> dist[idx];
``

  for(long long idx = 0; idx < N; idx++){
    cin >> city[idx].first;
    city[idx].second = idx;
  }


  sort(city, city+N-1, compare);

  long long checkdt = N-1;


  for(long long idx = 0; idx < N-1; idx++){
    long long pt = city[idx].second;
    if(pt > checkdt){
      continue;
    }
    else{
      for(long long jdx = pt; jdx < checkdt; jdx++){
        sum += dist[jdx] * city[idx].first;
      }
      checkdt = pt;
    }
  }

  cout << sum;


}
