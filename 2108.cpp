#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int compare(int a, int b){
  return a < b;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N = 0;
  int cnt = 0;
  int cnt_idx = 0;
  int min_idx = 0;
  int max_idx = 8000;
  int flag = 0;

  cin >> N;

  int *arr = (int*)malloc(sizeof(int) * N);    //중앙값
  vector<int> count(8001, 0);                  //최빈값, 범위
  double sum = 0;                              //산술평균

  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
    sum += arr[idx];
    count[arr[idx] + 4000]++;
  }

  sort(arr, arr + N, compare);

  for(int idx = 0; idx < 8001; idx++){

    if(cnt < count[idx]){
      cnt = count[idx];
      cnt_idx = idx-4000;
      flag = 0;
    }

    else if(cnt == count[idx]){
      if(flag == 0){
        cnt_idx = idx - 4000;
        flag++;
      }
    }
  }

  for(int idx = 0; idx < 8001; idx++){
    if(count[idx] != 0){
      min_idx = idx;
      break;
    }
  }

  for(int idx = 8000; idx >= 0; idx--){
    if(count[idx] != 0){
      max_idx = idx;
      break;
    }
  }







  cout << round(sum/(double)N) << '\n' << arr[N/2] << '\n' << cnt_idx << '\n' << max_idx - min_idx;



}
