#include <iostream>
using namespace std;

void star(char** arr, int x_start, int y_start, int size){
  if(size == 1){
    arr[x_start][y_start] = '*';
    return;
  }
  int div = size / 3;
  for(int idx = 0; idx < 3; idx++){
    for(int jdx = 0; jdx < 3; jdx++){
      if(idx == 1 && jdx == 1)
        continue;
      else
        star(arr, x_start + (idx * div), y_start + (jdx * div), div);
    }
  }
}


int main(){
  int N;
  cin >> N;

  char **arr = (char**)malloc(sizeof(char*) * N);
  for(int idx = 0; idx < N; idx++){
    arr[idx] = (char*)malloc(sizeof(char) * N);
    for(int jdx = 0; jdx < N; jdx++){
      arr[idx][jdx] = ' ';
    }
  }


  star(arr, 0, 0, N);


  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      cout << arr[idx][jdx];
    }
    cout << '\n';
  }

}
