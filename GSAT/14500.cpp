#include <iostream>
using namespace std;

int N, M;
int tetris[500][500];

bool check(int x, int y)
{
  if(x < 0 || y < 0 || x >= N || y >= M)
    return false;
  return true;
}

int one()
{
  int max = 0;
  int sum = 0;
  int which = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx+2, jdx))
      {
        which = 0;
        if(check(idx+3, jdx))
        {
          which = (which > tetris[idx+3][jdx])? which : tetris[idx+3][jdx];
        }
        if(check(idx, jdx-1))
        {
          which = (which > tetris[idx][jdx-1])? which : tetris[idx][jdx-1];
        }
        if(check(idx, jdx+1))
        {
          which = (which > tetris[idx][jdx+1])? which : tetris[idx][jdx+1];
        }
        if(check(idx+2, jdx-1))
        {
          which = (which > tetris[idx+2][jdx-1])? which : tetris[idx+2][jdx-1];
        }
        if(check(idx+2, jdx+1))
        {
          which = (which > tetris[idx+2][jdx+1])? which : tetris[idx+2][jdx+1];
        }
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx+2][jdx] + which;
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx, jdx+2))
      {
        which = 0;
        if(check(idx, jdx+3))
        {
          which = (which > tetris[idx][jdx+3])? which : tetris[idx][jdx+3];
        }
        if(check(idx-1, jdx))
        {
          which = (which > tetris[idx-1][jdx])? which : tetris[idx-1][jdx];
        }
        if(check(idx+1, jdx))
        {
          which = (which > tetris[idx+1][jdx])? which : tetris[idx+1][jdx];
        }
        if(check(idx-1, jdx+2))
        {
          which = (which > tetris[idx-1][jdx+2])? which : tetris[idx-1][jdx+2];
        }
        if(check(idx+1, jdx+2))
        {
          which = (which > tetris[idx+1][jdx+2])? which : tetris[idx+1][jdx+2];
        }
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx][jdx+2] + which;
        max = (max > sum)? max : sum;
      }
    }
  }
  return max;
}

int two()
{
  int max = 0;
  int sum = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx, jdx+1) && check(idx+1, jdx+1))
      {
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx][jdx+1] + tetris[idx+1][jdx+1];
        max = (max > sum)? max : sum;
      }
    }
  }
  return max;
}


int three()
{
  int max = 0;
  int sum = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx-1, jdx+1) && check(idx, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx-1][jdx+1] + tetris[idx][jdx+2];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx+1, jdx+1) && check(idx, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx+1][jdx+1] + tetris[idx][jdx+2];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx-1, jdx+1) && check(idx+1, jdx+1))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx-1][jdx+1] + tetris[idx+1][jdx+1];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx-1, jdx) && check(idx+1, jdx) && check(idx, jdx+1))
      {
        sum = tetris[idx][jdx] + tetris[idx-1][jdx] + tetris[idx+1][jdx] + tetris[idx][jdx+1];
        max = (max > sum)? max : sum;
      }
    }
  }
  return max;
}


int four()
{
  int max = 0;
  int sum = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx+1, jdx+1) && check(idx+2, jdx+1))
      {
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx+1][jdx+1] + tetris[idx+2][jdx+1];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx+1, jdx+1) && check(idx+1, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx+1][jdx+1] + tetris[idx+1][jdx+2];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx+1, jdx-1) && check(idx+2, jdx-1))
      {
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx+1][jdx-1] + tetris[idx+2][jdx-1];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx-1, jdx+1) && check(idx-1, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx-1][jdx+1] + tetris[idx-1][jdx+2];
        max = (max > sum)? max : sum;
      }
    }
  }
  return max;
}

int five()
{
  int max = 0;
  int sum = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx+1, jdx+1) && check(idx+2, jdx+1))
      {
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx+1][jdx+1] + tetris[idx+2][jdx+1];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx+1, jdx+1) && check(idx+1, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx+1][jdx+1] + tetris[idx+1][jdx+2];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx+1, jdx) && check(idx+1, jdx-1) && check(idx+2, jdx-1))
      {
        sum = tetris[idx][jdx] + tetris[idx+1][jdx] + tetris[idx+1][jdx-1] + tetris[idx+2][jdx-1];
        max = (max > sum)? max : sum;
      }
      if(check(idx, jdx) && check(idx, jdx+1) && check(idx-1, jdx+1) && check(idx-1, jdx+2))
      {
        sum = tetris[idx][jdx] + tetris[idx][jdx+1] + tetris[idx-1][jdx+1] + tetris[idx-1][jdx+2];
        max = (max > sum)? max : sum;
      }
    }
  }
  return max;
}









int main()
{
  cin >> N >> M;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      cin >> tetris[idx][jdx];
    }
  }

  int max = 0;

  int a = one();
  int b = two();
  int c = three();
  int d = four();

  max = (max > a)? max : a;
  max = (max > b)? max : b;
  max = (max > c)? max : c;
  max = (max > d)? max : d;


  cout << max;



}
