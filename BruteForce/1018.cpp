#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int checkcnt(char **arr, int x, int y){
  int cntb = 0;
  int cntw = 0;

  for(int idx = x; idx < x + 8; idx++){
    for(int jdx = y; jdx < y + 8; jdx++){
      if((idx + jdx) % 2 == 0){
        if(arr[idx][jdx] != 'W')  cntb++;
        if(arr[idx][jdx] != 'B')  cntw++;
      }
      else{
        if(arr[idx][jdx] != 'B')  cntb++;
        if(arr[idx][jdx] != 'W')  cntw++;
      }
    }
  }
  return min(cntw, cntb);
}



int main(){
  int N, M;
  cin >> N >> M;

  int min = N * M;

  char **arr = (char**)malloc(sizeof(char*) * N);
  for(int idx = 0; idx < N; idx++){
    arr[idx] = (char*)malloc(sizeof(char) * M);
  }

  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx];
  }

  for(int idx = 0; idx + 8 <= N; idx++){
    for(int jdx = 0; jdx + 8 <= M; jdx++){
      min = (min > checkcnt(arr, idx, jdx))? checkcnt(arr, idx, jdx) : min;
    }
  }


  cout << min << endl;
}
