#include <iostream>
using namespace std;

struct body{
  int w;
  int h;
};


int main(){
  int N = 0;
  int rank = 1;
  cin >> N;

  //struct body *arr[N];
  struct body *arr = (struct body *)malloc(sizeof(body) * N);
  for(int idx = 0; idx < N; idx++){
    cin >> arr[idx].w >> arr[idx].h;
  }

  for(int idx = 0; idx < N; idx++){
    rank = 1;
    for(int jdx = 0; jdx < N; jdx++){
      if((arr + idx)->w < (arr + jdx)->w && (arr + idx)->h < (arr + jdx)->h){
        rank++;
      }
    }
    cout << rank << ' ';
  }

  free(arr);
}
