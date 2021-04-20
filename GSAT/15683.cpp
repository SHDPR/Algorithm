#include <iostream>

using namespace std;
typedef pair<int, int> cod;

int N, M;
int office[8][8];
cod cctv[8];
int cctv_cnt = 0;

int rot[6] = {0, 4, 2, 4, 4, 1};
int min_space = 64;


void mapcpy(int dst[8][8], int src[8][8])
{
  for(int idx = 0; idx < 8; idx++)
  {
    for(int jdx = 0; jdx < 8; jdx++)
      dst[idx][jdx] = src[idx][jdx];
  }
}

void detect(cod pos, int dir)
{
  int row = pos.first;
  int col = pos.second;

  dir = dir % 4;

  switch(dir)
  {
    case 0 :
      while(--row >= 0)
      {
        if(office[row][col] == 6)
          break;
        if(office[row][col] == 0)
          office[row][col] = -1;
      }
      break;
    case 2 :
      while(++row < N)
      {
        if(office[row][col] == 6)
          break;
        if(office[row][col] == 0)
          office[row][col] = -1;
      }
      break;
    case 1 :
      while(++col < M)
      {
        if(office[row][col] == 6)
          break;
        if(office[row][col] == 0)
          office[row][col] = -1;
      }
      break;
    case 3 :
      while(--col >= 0)
      {
        if(office[row][col] == 6)
          break;
        if(office[row][col] == 0)
          office[row][col] = -1;
      }
      break;
  }
}

void dfs_detect(int idx)
{
  if(idx == cctv_cnt)
  {
    int rect_cnt = 0;

    for(int idx = 0; idx < N; idx++)
    {
      for(int jdx = 0; jdx < M; jdx++)
      {
        if(office[idx][jdx] == 0)
          rect_cnt++;
      }
    }

    min_space = (min_space > rect_cnt)? rect_cnt : min_space;
    return;
  }

  int backup[8][8];

  cod pos = cctv[idx];
  int type = office[pos.first][pos.second];

  for(int dir = 0; dir < rot[type]; dir++)
  {
    mapcpy(backup, office);
    switch(type)
    {
      case 1 :
        detect(pos, dir);
        break;
      case 2 :
        detect(pos, dir);
        detect(pos, dir + 2);
        break;
      case 3 :
        detect(pos, dir);
        detect(pos, dir + 1);
        break;
      case 4 :
        detect(pos, dir);
        detect(pos, dir + 1);
        detect(pos, dir + 2);
        break;
      case 5 :
        detect(pos, dir);
        detect(pos, dir + 1);
        detect(pos, dir + 2);
        detect(pos, dir + 3);
        break;
    }
    dfs_detect(idx + 1);
    mapcpy(office, backup);
  }
}


int main()
{
  cin >> N >> M;
  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      cin >> office[idx][jdx];
      if(office[idx][jdx] != 0 && office[idx][jdx] != 6)
      {
        cctv[cctv_cnt++] = {idx, jdx};
      }
    }
  }
  dfs_detect(0);

  cout << min_space;

}
