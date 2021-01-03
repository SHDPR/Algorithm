#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int N = 0;
  int maxidx = 0;
  int maxsum = 0;
  int cnt = 0;
  cin >> N;
  pair<int, int> line[N];
  int intersect[N][N];
  int blank[N] = {0, };


  for(int idx = 0; idx < N; idx++)
    cin >> line[idx].first >> line[idx].second;

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < idx; jdx++){
      intersect[idx][jdx] = 0;
    }
    for(int jdx = idx; jdx < N; jdx++){
      int check = (line[idx].first - line[jdx].first) * (line[idx].second - line[jdx].second);
      if(check < 0)
        intersect[idx][jdx] = 1;
      else
        intersect[idx][jdx] = 0;
    }
  }

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      cout << intersect[idx][jdx] << " ";
    }
    cout << '\n';
  }

  while(1){
    memset(blank, 0, sizeof(blank));
    maxidx = 0;
    maxsum = 0;
    for(int idx = 0; idx < N; idx++){
      for(int jdx = 0; jdx < N; jdx++){
        if(intersect[idx][jdx] == 1){
          blank[idx]++;
          blank[jdx]++;
        }
      }
    }

    for(int idx = 0; idx < N; idx++){
      if(maxsum < blank[idx]){
        maxidx = idx;
        maxsum = blank[idx];
      }
    }

    if(maxsum == 0) break;

    for(int idx = 0; idx < N; idx++){
      intersect[maxidx][idx] = 0;
      intersect[idx][maxidx] = 0;
    }
    cout << cnt << '\n';
    for(int idx = 0; idx < N; idx++){
      for(int jdx = 0; jdx < N; jdx++){
        cout << intersect[idx][jdx] << " ";
      }
      cout << '\n';
    }
    cout << '\n';


    cnt++;
  }


cout << cnt;


}
