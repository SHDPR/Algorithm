#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;



int diff_value(int** ability, int* start, int N){
  int sab = 0;
  int lab = 0;

  for(int idx = 0; idx < N; idx++){
    for(int jdx = 0; jdx < N; jdx++){
      if(start[idx] == 1 && start[jdx] == 1 && idx != jdx)
        sab += ability[idx][jdx];
      if(start[idx] == 0 && start[jdx] == 0 && idx != jdx)
        lab += ability[idx][jdx];
    }
  }
  return abs(sab - lab);

}


void divide(int cnt, int idx, int N, int** ability, int* start, int *diff){
  if(cnt == N/2){
    *diff = min(*diff, diff_value(ability, start, N));
    return;
  }

  for(int i = idx; i < N; i++){
    if(start[i] == 0){
      start[i] = 1;
      divide(cnt + 1, i + 1, N, ability, start, diff);
      start[i] = 0;
    }
  }

}

int main(){
	int N = 0;
  cin >> N;

	int **ability = (int**)malloc(sizeof(int*) * N);
	int start[N] = {0,};
	int diff = INT_MAX;

	for(int idx = 0; idx < N; idx++){
		ability[idx] = (int*)malloc(sizeof(int) * N);
		for(int jdx = 0; jdx < N; jdx++){
			cin >> ability[idx][jdx];
		}
	}


  divide(0, 0, N, ability, start, &diff);

  cout << diff << endl;
}
