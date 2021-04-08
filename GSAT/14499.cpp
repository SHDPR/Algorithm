#include <iostream>
using namespace std;

int N, M;
int dice[6] = {0, 0, 0, 0, 0, 0};
int map[20][20];

void move_one()
{
  int a = dice[0];
  int b = dice[1];

  dice[0] = dice[5];
  dice[1] = dice[4];

  dice[4] = a;
  dice[5] = b;
}

void move_two()
{
  int a = dice[0];
  int b = dice[1];

  dice[0] = dice[4];
  dice[1] = dice[5];

  dice[4] = b;
  dice[5] = a;
}

void move_three()
{
  int a = dice[0];
  int b = dice[1];

  dice[0] = dice[3];
  dice[1] = dice[2];

  dice[2] = a;
  dice[3] = b;
}

void move_four()
{
  int a = dice[0];
  int b = dice[1];

  dice[0] = dice[2];
  dice[1] = dice[3];

  dice[2] = b;
  dice[3] = a;
}

bool check_pos(int x, int y)
{
  if(x < 0 || y < 0 || x >= N || y >= M)
    return false;
  return true;
}



int main()
{
  int x, y, cmd_n;
  cin >> N >> M >> x >> y >> cmd_n;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      cin >> map[idx][jdx];
    }
  }

  for(int idx = 0; idx < cmd_n; idx++)
  {
    int direction;
    cin >> direction;

    switch(direction)
    {
      case 1 :
        y += 1;
        if(!check_pos(x,y))
        {
          y -= 1;
        }
        else
        {
          move_one();
          if(map[x][y] == 0)
          {
            map[x][y] = dice[1];
          }
          else
          {
            dice[1] = map[x][y];
            map[x][y] = 0;
          }
          cout << dice[0] << '\n';
        }
        break;
      case 2 :
        y -= 1;
        if(!check_pos(x,y))
        {
          y += 1;
        }
        else
        {
          move_two();
          if(map[x][y] == 0)
          {
            map[x][y] = dice[1];
          }
          else
          {
            dice[1] = map[x][y];
            map[x][y] = 0;
          }
          cout << dice[0] << '\n';
        }
        break;
      case 3 :
        x -=  1;
        if(!check_pos(x,y))
        {
          x += 1;
        }
        else
        {
          move_three();
          if(map[x][y] == 0)
          {
            map[x][y] = dice[1];
          }
          else
          {
            dice[1] = map[x][y];
            map[x][y] = 0;
          }
          cout << dice[0] << '\n';
        }
        break;
      case 4 :
        x += 1;
        if(!check_pos(x,y))
        {
          x -= 1;
        }
        else
        {
          move_four();
          if(map[x][y] == 0)
          {
            map[x][y] = dice[1];
          }
          else
          {
            dice[1] = map[x][y];
            map[x][y] = 0;
          }
          cout << dice[0] << '\n';
        }
        break;
    }
  }
}
