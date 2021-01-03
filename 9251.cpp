#include <iostream>
#include <algorithm>

using namespace std;

// Greedy Algorith으로 가장 많은 전깃줄과 겹치는 식으로 풀었으나, 여러 전깃줄 중 어떤 전깃줄을 선택하냐에 따라 답이 다르게 나오는 문제가 발생
// 따라서 DP 방식(LIS 문제)으로 새로 품!

int compare(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}



int main(){
  int N = 0;
  int output = 0;
  cin >> N;
  pair<int, int> line[N];
  pair<int, int> dp[N];

  for(int idx = 0; idx < N; idx++){
    cin >> line[idx].first >> line[idx].second;
  }

  sort(line, line + N, compare);

  for(int idx = 0; idx < N; idx++){
    dp[idx].first = 1;
    dp[idx].second = line[idx].second;
  }

  output = dp[0].first;

  for(int idx = 1; idx < N; idx++){
    for(int jdx = 0; jdx < idx; jdx++){
      if(dp[idx].second > dp[jdx].second){
        dp[idx].first = max(dp[idx].first, dp[jdx].first + 1);
      }
    }
    output = max(output, dp[idx].first);
  }

  cout << N - output;

}
