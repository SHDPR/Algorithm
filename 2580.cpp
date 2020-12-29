#include <iostream>
#include <vector>
using namespace std;

bool possible(int arr[][9], int x, int y){
  for(int k = 0; k < 9; k++){
    if(arr[x][y] == arr[k][y] && x!=k)
      return false;
  }
  for(int k = 0; k < 9; k++){
    if(arr[x][y] == arr[x][k] && y!=k)
      return false;
  }
  int idx = (x / 3) * 3;
  int x_max = idx + 3;
  int jdx = (y / 3) * 3;
  int y_max = jdx + 3;


  for(; idx < x_max; idx++){
    for(jdx = y_max - 3; jdx < y_max; jdx++){
      if(arr[x][y] == arr[idx][jdx] && !(x==idx && y==jdx))
        return false;
    }
  }

  return true;
}


void sudoku(int arr[][9], vector<pair<int, int>> blank, int cnt, int size){
  if(cnt == size){
    for(int idx = 0; idx < 9; idx++){
      for(int jdx = 0; jdx < 9; jdx++){
        cout << arr[idx][jdx] << " ";
      }
      cout << '\n';
    }
    exit(0);
  }

  int x = blank[cnt].first;
  int y = blank[cnt].second;

  for(int k = 1; k < 10; k++){
    arr[x][y] = k;
    if(possible(arr, x, y)){
      sudoku(arr, blank, cnt+1, size);
    }
    arr[x][y] = 0;
  }
}



int main(){
  int arr[9][9];
  int cnt = 0;
  vector<pair<int, int>> blank(81);

  for(int idx = 0; idx < 9; idx++){
    for(int jdx = 0; jdx < 9; jdx++){
      cin >> arr[idx][jdx];
      if(arr[idx][jdx] == 0){
        blank[cnt].first = idx;
        blank[cnt].second = jdx;
        cnt++;
      }
    }
  }

  sudoku(arr, blank, 0, cnt);
}
