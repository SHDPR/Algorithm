#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int w[21][21][21];

  for(int idx = 0; idx < 21; idx++){
    for(int jdx = 0; jdx < 21; jdx++){
      for(int kdx = 0; kdx < 21; kdx++){
        if(idx == 0 || jdx == 0 || kdx == 0)
          w[idx][jdx][kdx] = 1;
        else if(idx < jdx && jdx < kdx)
          w[idx][jdx][kdx] = w[idx][jdx][kdx-1] + w[idx][jdx-1][kdx-1] - w[idx][jdx-1][kdx];
        else
          w[idx][jdx][kdx] = w[idx-1][jdx][kdx] + w[idx-1][jdx-1][kdx] + w[idx-1][jdx][kdx-1] - w[idx-1][jdx-1][kdx-1];
      }
    }
  }

  while(1){
    int i, j, k;
    cin >> i >> j >> k;
    if(i == -1 && j == -1 && k == -1)
      return 0;
    if(i <=0 || j <= 0 || k <=0)
      cout << "w(" << i << ", " << j << ", " << k << ") = " << 1 << '\n';
    else if(i > 20 || j > 20 || k > 20)
      cout << "w(" << i << ", " << j << ", " << k << ") = " << w[20][20][20] << '\n';
    else
      cout << "w(" << i << ", " << j << ", " << k << ") = " << w[i][j][k] << '\n';
  }

}
