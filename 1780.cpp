#include <iostream>
using namespace std;

int check(int **color, int idx, int jdx, int len){
  int flag = color[idx][jdx];
  for(int i = idx; i < idx + len; i++){
    for(int j = jdx; j < jdx + len; j++){
      if(flag != color[i][j]) return 100;
    }
  }
  return flag;
}




void divconq(int **color, int idx, int jdx, int len, int *w_cnt, int *b_cnt, int *c_cnt){
  int flag = check(color, idx, jdx, len);
  switch(flag){
    case 1 :
      (*b_cnt)++;
      break;
    case 0 :
      (*w_cnt)++;
      break;
    case -1 :
      (*c_cnt)++;
      break;
    case 100 :
      divconq(color, idx, jdx, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + len/3, jdx, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + 2 * len/3, jdx, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx, jdx + len/3, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + len/3, jdx + len/3, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + 2 * len/3, jdx + len/3, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx, jdx + 2 * len/3, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + len/3, jdx + 2 * len/3, len/3, w_cnt, b_cnt, c_cnt);
      divconq(color, idx + 2 * len/3, jdx + 2 * len/3, len/3, w_cnt, b_cnt, c_cnt);
      break;
    default :
      throw out_of_range("Inappropriate flag");
  }
}


int main(){
  int len = 0;
  int w_cnt = 0;
  int b_cnt = 0;
  int c_cnt = 0;

  cin >> len;
  int **color = (int**)malloc(sizeof(int*) * len);
  for(int idx = 0; idx < len; idx++){
    color[idx] = (int*)malloc(sizeof(int) * len);
    for(int jdx = 0; jdx < len; jdx++)
      cin >> color[idx][jdx];
  }

  divconq(color, 0, 0, len, &w_cnt, &b_cnt, &c_cnt);
  cout << c_cnt << '\n' << b_cnt << '\n' << w_cnt;


}
