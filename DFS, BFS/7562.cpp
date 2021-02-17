#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int testcase = 0;
  cin >> testcase;

  for(int idx = 0; idx < testcase; idx++)
  {
    int N;
    int **board;

    cin >> N;
    board = (int**)malloc(sizeof(int*) * N);

    for(int jdx = 0; jdx < N; jdx++)
    {
      board[jdx] = (int*)malloc(sizeof(int) * N);
      for(int kdx = 0; kdx < N; kdx++)
        board[jdx][kdx] = 0;
    }

    int start_x, start_y;
    int dest_x, dest_y;

    cin >> start_x >> start_y;
    cin >> dest_x >> dest_y;

    queue<pair<int, int>> knight;
    knight.push({start_x, start_y});
    board[start_x][start_y] = 1;

    while(!knight.empty())
    {
      int x = knight.front().first;
      int y = knight.front().second;

      if(x == dest_x && y == dest_y)
      {
        cout << board[dest_x][dest_y] - 1 << '\n';
        break;
      }

      knight.pop();

      int move_x[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
      int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

      for(int idx = 0; idx < 8; idx++)
      {
        int next_x = x + move_x[idx];
        int next_y = y + move_y[idx];

        if(next_x < 0 || next_x >= N)
          continue;

        if(next_y < 0 || next_y >= N)
          continue;

        if(board[next_x][next_y] == 0)
        {
          board[next_x][next_y] = board[x][y] + 1;
          knight.push({next_x, next_y});
        }
      }
    }
    free(board);
  }

}
