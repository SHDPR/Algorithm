#include <iostream>
#include <memory.h>
using namespace std;

char uppp[9] = {'w','w','w','w','w','w','w','w','w' };
char down[9] = {'y','y','y','y','y','y','y','y','y' };
char frnt[9] = {'r','r','r','r','r','r','r','r','r' };
char back[9] = {'o','o','o','o','o','o','o','o','o' };
char leff[9] = {'g','g','g','g','g','g','g','g','g' };
char righ[9] = {'b','b','b','b','b','b','b','b','b' };


void rotate1(char a[], int dir)
{
  if(dir == 0)
  {
    char new_a[9];
    new_a[0] = a[6];
    new_a[1] = a[3];
    new_a[2] = a[0];
    new_a[3] = a[7];
    new_a[4] = a[4];
    new_a[5] = a[1];
    new_a[6] = a[8];
    new_a[7] = a[5];
    new_a[8] = a[2];
    memcpy(a, new_a, sizeof(char) * 9);
  }
  else
  {
    char new_a[9];
    new_a[0] = a[2];
    new_a[1] = a[5];
    new_a[2] = a[8];
    new_a[3] = a[1];
    new_a[4] = a[4];
    new_a[5] = a[7];
    new_a[6] = a[0];
    new_a[7] = a[3];
    new_a[8] = a[6];
    memcpy(a, new_a, sizeof(char) * 9);
  }
}



void rotate4(char a[], char b[], char c[], char d[], int idx, int jdx, int kdx)
{
  int temp[3] = {a[idx], a[jdx], a[kdx]};

  a[idx] = b[idx];
  a[jdx] = b[jdx];
  a[kdx] = b[kdx];

  b[idx] = c[idx];
  b[jdx] = c[jdx];
  b[kdx] = c[kdx];

  c[idx] = d[idx];
  c[jdx] = d[jdx];
  c[kdx] = d[kdx];

  d[idx] = temp[0];
  d[jdx] = temp[1];
  d[kdx] = temp[2];
}


void operation(int cube, int dir)
{
  switch(cube)
  {
    case 5 :
      if(dir == 0)
      {
        rotate4(back, down, frnt, uppp, 0, 3, 6);
        rotate1(leff, dir);
      }
      else
      {
        rotate4(back, uppp, frnt, down, 0, 3, 6);
        rotate1(leff, dir);
      }
      break;

    case 6:
      if(dir == 0)
      {
        rotate4(frnt, down, back, uppp, 2, 5, 8);
        rotate1(righ, dir);
      }
      else
      {
        rotate4(uppp, back, down, frnt, 2, 5, 8);
        rotate1(righ, dir);
      }
      break;
    case 1 :
      rotate1(uppp, dir);
      break;

    case 2 :
      rotate1(down, dir);
      break;

    case 3 :
      if(dir == 0)
      {
        rotate4(leff, down, righ, uppp, 6, 7, 8);
        rotate1(frnt, dir);
      }
      else
      {
        rotate4(leff, uppp, righ, down, 6, 7, 8);
        rotate1(frnt, dir);
      }
      break;

    case 4 :
      if(dir == 0)
      {
        rotate4(uppp, righ, down, leff, 0, 1, 2);
      }
      else
      {
        rotate4(uppp, leff, down, righ, 0, 1, 2);
      }
      rotate1(back, dir);
      break;

  }
}

int main()
{
  int op_cnt;

  cin >> op_cnt;

  for(int idx = 0; idx < op_cnt; idx++)
  {
    char opcode[2];
    int cnt;

    cin >> cnt;

    for(int jdx = 0; jdx < cnt; jdx++)
    {
      cin >> opcode;
      int mode = (opcode[1] == '+')? 0 : 1;
      switch(opcode[0])
      {
        case 'U' :
          operation(1, mode);
          break;
        case 'D' :
          operation(2, mode);
          break;
        case 'F' :
          operation(3, mode);
          break;
        case 'B' :
          operation(4, mode);
          break;
        case 'L' :
          operation(5, mode);
          break;
        case 'R' :
          operation(6, mode);
          break;
      }
    }
  }

  for(int idx = 0; idx < 9; idx++)
  {
    cout << uppp[idx] << " ";
  }





}
