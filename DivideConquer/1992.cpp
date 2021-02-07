#include <iostream>
using namespace std;

int check(int **color, int idx, int jdx, int len){
  int flag = color[idx][jdx];
  for(int i = idx; i < idx + len; i++){
    for(int j = jdx; j < jdx + len; j++){
      if(flag != color[i][j]) return -1;
    }
  }
  return flag;
}

void divconq(int **color, int idx, int jdx, int len){
  int flag = check(color, idx, jdx, len);
  switch(flag){
    case 1 :
      cout << 1;
      break;
    case 0 :
      cout << 0;
      break;
    case -1 :
      cout << '(';
      divconq(color, idx, jdx, len/2);
      divconq(color, idx, jdx + len/2, len/2);
      divconq(color, idx + len/2, jdx, len/2);
      divconq(color, idx + len/2, jdx + len/2, len/2);
      cout << ')';
      break;
    default :
      throw out_of_range("Inappropriate flag");
  }

}



int main(){
  int len = 0;
  string input = "";

  cin >> len;
  int **color = (int**)malloc(sizeof(int*) * len);
  for(int idx = 0; idx < len; idx++){
    color[idx] = (int*)malloc(sizeof(int) * len);
    cin >> input;
    for(int jdx = 0; jdx < len; jdx++){
      color[idx][jdx] = input[jdx] - '0';
    }
  }

  divconq(color, 0, 0, len);

}
