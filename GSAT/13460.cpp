#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> xy;
typedef pair<xy, xy> rb;

/* global variables */
int N, M;
int board[10][10];
xy hole;


rb move(xy red, xy blue, int dir)
{
  int red_y;
  int blue_y;
  int red_x;
  int blue_x;
  int idx;

  switch(dir)
  {
    case 0 :
      red_y = red.second;
      blue_y = blue.second;

      for(idx = red_y; idx > 0; idx--)
      {
        if(board[red.first][idx-1] == '#' || board[red.first][idx] == 'O')
          break;
      }
      red_y = idx;

      for(idx = blue_y; idx > 0; idx--)
      {
        if(board[blue.first][idx-1] == '#' || board[blue.first][idx] == 'O')
          break;
      }
      blue_y = idx;

      if(red.first == blue.first && red_y == blue_y && !(red.first == hole.first && red_y == hole.second))
      {
        if(red.second < blue.second)
          blue_y++;
        else
          red_y++;
      }

      red.second = red_y;
      blue.second = blue_y;

      return {red, blue};

    case 1 :
      red_y = red.second;
      blue_y = blue.second;

      for(idx = red_y; idx < M-1; idx++)
      {
        if(board[red.first][idx+1] == '#' || board[red.first][idx] == 'O')
          break;
      }
      red_y = idx;

      for(idx = blue_y; idx < M-1; idx++)
      {
        if(board[blue.first][idx+1] == '#' || board[blue.first][idx] == 'O')
          break;
      }
      blue_y = idx;

      if(red.first == blue.first && red_y == blue_y && !(red.first == hole.first && red_y == hole.second))
      {
        if(red.second < blue.second)
          red_y--;
        else
          blue_y--;
      }

      red.second = red_y;
      blue.second = blue_y;

      return {red, blue};

    case 2 :
      red_x = red.first;
      blue_x = blue.first;

      for(idx = red_x; idx > 0; idx--)
      {
        if(board[idx-1][red.second] == '#' || board[idx][red.second] == 'O')
          break;
      }
      red_x = idx;

      for(idx = blue_x; idx > 0; idx--)
      {
        if(board[idx-1][blue.second] == '#' || board[idx][blue.second] == 'O')
          break;
      }
      blue_x = idx;

      if(red_x == blue_x && red.second == blue.second && !(red_x == hole.first && red.second == hole.second))
      {
        if(red.first < blue.first)
          blue_x++;
        else
          red_x++;
      }

      red.first = red_x;
      blue.first = blue_x;

      return {red, blue};

    case 3 :
      red_x = red.first;
      blue_x = blue.first;

      for(idx = red_x; idx < N-1; idx++)
      {
        if(board[idx+1][red.second] == '#' || board[idx][red.second] == 'O')
          break;
      }
      red_x = idx;

      for(idx = blue_x; idx < N-1; idx++)
      {
        if(board[idx+1][blue.second] == '#' || board[idx][blue.second] == 'O')
          break;
      }
      blue_x = idx;

      if(red_x == blue_x && red.second == blue.second && !(red_x == hole.first && red.second == hole.second))
      {
        if(red.first < blue.first)
          red_x--;
        else
          blue_x--;
      }

      red.first = red_x;
      blue.first = blue_x;
      return {red, blue};
  }
}


int bfs_helper(xy red, xy blue)
{
  int cnt = 0;
  queue<pair<int, rb>> bfs;

  pair<int, rb> start = {0, {red, blue}};

  bfs.push(start);

  while(true)
  {
    if(bfs.empty())
    {
      return -1;
    }
    pair<int, rb> top = bfs.front();

    if(top.first >= 10)
      return -1;

    xy top_red = top.second.first;
    xy top_blue = top.second.second;
    bfs.pop();


    for(int idx = 0; idx < 4; idx++)
    {
      rb moved = move(top_red, top_blue, idx);
      xy red_moved = moved.first;
      xy blue_moved = moved.second;

      if(red_moved.first == top_red.first && red_moved.second == top_red.second && blue_moved.first == top_blue.first && blue_moved.second == top_blue.second)
      {
        continue;
      }

      if(blue_moved.first == hole.first && blue_moved.second == hole.second)
        continue;

      if(red_moved.first == hole.first && red_moved.second == hole.second)
        return top.first + 1;

      pair<int, rb> push_elem = {top.first+1, moved};
      bfs.push(push_elem);
    }
  }
  return -1;
}







int main()
{
  cin >> N >> M;
  xy red;
  xy blue;
  char input[M];

  for(int idx = 0; idx < N; idx++)
  {
    cin >> input;
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(input[jdx] == 'R')
      {
        board[idx][jdx] = '.';
        red = {idx, jdx};
      }
      else if(input[jdx] == 'B')
      {
        board[idx][jdx] = '.';
        blue = {idx, jdx};
      }
      else if(input[jdx] == 'O')
      {
        board[idx][jdx] = 'O';
        hole = {idx, jdx};
      }
      else
      {
        board[idx][jdx] = input[jdx];
      }
    }
  }

  cout << bfs_helper(red, blue);
}
