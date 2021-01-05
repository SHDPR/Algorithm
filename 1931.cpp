#include <iostream>
#include <algorithm>
using namespace std;

int compare(pair<int, int> a, pair<int, int> b){
  if(a.second = b.second)
    return a.first < b.first;
  return a.second < b.second;
}



int main(){
  int N = 0;
  int end = 0;
  int idx = 0;
  int cnt = 0;
  cin >> N;
  pair<int, int> timetable[N];

  for(int idx = 0; idx < N; idx++){
    cin >> timetable[idx].first >> timetable[idx].second;
  }

  sort(timetable, timetable + N, compare);

  end = timetable[0].second;
  cnt++;
  idx++;

  while(idx < N){
    if(end <= timetable[idx].first){
      cnt++;
      end = timetable[idx].second;
    }
    idx++;
  }


  cout << cnt;
}
