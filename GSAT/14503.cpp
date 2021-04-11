#include <iostream>

using namespace std;
typedef pair<int, int> coord;

int N, M;
int r, c, d;
int map[50][50];

coord dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool robotmove()
{
  int cnt = 0;
  int idx = (d + 3) % 4;

  for(; cnt < 4; idx = (idx + 3) % 4)
  {
    cnt++;
    int new_r = r + dir[idx].first;
    int new_c = c + dir[idx].second;

    if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M)
      continue;

    if(map[new_r][new_c] == 1 || map[new_r][new_c] == 2)
      continue;

    if(map[new_r][new_c] == 0)
    {
      r = new_r;
      c = new_c;
      d = idx;
      return true;
    }
  }
  int rear = (d + 2) % 4;
  int val = map[r + dir[rear].first][c + dir[rear].second];

  if(val == 1)
    return false;

  else
  {
    r = r + dir[rear].first;
    c = c + dir[rear].second;
    return true;
  }
}


int main()
{
  cin >> N >> M;

  cin >> r >> c >> d;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
      cin >> map[idx][jdx];
  }



  while(true)
  {
    map[r][c] = 2;

    if(!robotmove())
      break;
  }

  int cnt = 0;

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < M; jdx++)
    {
      if(map[idx][jdx] == 2)
        cnt++;
    }
  }

  cout << cnt;

}
