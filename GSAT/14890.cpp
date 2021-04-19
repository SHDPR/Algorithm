#include <iostream>
#include <memory.h>
using namespace std;

int N, L;
int map[100][100];
int chk[100][100] = {0, };


int main()
{
  int path_cnt = 0;
  cin >> N >> L;
  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
      cin >> map[idx][jdx];
  }

  for(int idx = 0; idx < N; idx++)
  {
    int height = map[idx][0];
    bool stop = false;
    for(int jdx = 0; jdx < N; jdx++)
    {
      int flag = height - map[idx][jdx];

      switch(flag)
      {
        case 0 :
          break;
        case 1 :
          for(int kdx = 0; kdx < L; kdx++)
          {
            if(jdx + kdx >= N)
            {
              stop = true;
              break;
            }

            if(chk[idx][jdx + kdx] == 1)
            {
              stop = true;
              break;
            }

            if(map[idx][jdx] != map[idx][jdx + kdx])
            {
              stop = true;
              break;
            }
          }

          if(!stop)
          {
            for(int kdx = 0; kdx < L; kdx++)
            {
              chk[idx][jdx + kdx] = 1;
            }
          }

          break;
        case -1 :
          for(int kdx = 0; kdx < L; kdx++)
          {
            if(jdx - kdx - 1 < 0)
            {
              stop = true;
              break;
            }

            if(chk[idx][jdx - kdx - 1] == 1)
            {
              stop = true;
              break;
            }

            if(height != map[idx][jdx - kdx - 1])
            {
              stop = true;
              break;
            }
          }

          if(!stop)
          {
            for(int kdx = 0; kdx < L; kdx++)
            {
              chk[idx][jdx - kdx - 1] = 1;
            }
          }

          break;
        default :
          stop = true;
      }

      height = map[idx][jdx];
    }

    if(!stop) path_cnt++;
  }

  memset(chk, 0, sizeof(chk));

  for(int idx = 0; idx < N; idx++)
  {
    int height = map[0][idx];
    bool stop = false;
    for(int jdx = 0; jdx < N; jdx++)
    {
      int flag = height - map[jdx][idx];

      switch(flag)
      {
        case 0 :
          break;
        case 1 :
          for(int kdx = 0; kdx < L; kdx++)
          {
            if(jdx + kdx >= N)
            {
              stop = true;
              break;
            }

            if(chk[jdx + kdx][idx] == 1)
            {
              stop = true;
              break;
            }

            if(map[jdx][idx] != map[jdx + kdx][idx])
            {
              stop = true;
              break;
            }
          }

          if(!stop)
          {
            for(int kdx = 0; kdx < L; kdx++)
            {
              chk[jdx + kdx][idx] = 1;
            }
          }

          break;
        case -1 :
          for(int kdx = 0; kdx < L; kdx++)
          {
            if(jdx - kdx - 1 < 0)
            {
              stop = true;
              break;
            }

            if(chk[jdx - kdx - 1][idx] == 1)
            {
              stop = true;
              break;
            }

            if(height != map[jdx - kdx - 1][idx])
            {
              stop = true;
              break;
            }
          }

          if(!stop)
          {
            for(int kdx = 0; kdx < L; kdx++)
            {
              chk[jdx - kdx - 1][idx] = 1;
            }
          }

          break;

        default :
          stop = true;
      }

      height = map[jdx][idx];
    }

    if(!stop) path_cnt++;
  }

  cout << path_cnt;
}
