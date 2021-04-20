#include <iostream>
using namespace std;

typedef pair<int, int> pos;

int map[101][101] = {0, };

pos dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

pos dragoncurve(int x, int y, int d, int g)
{
  if(g == 0)
  {
    pos start = {x, y};
    pos end = {x + dir[d].first, y + dir[d].second};
    map[start.first][start.second] = 1;
    map[end.first][end.second] = 1;
    return end;
  }

  pos start = {x, y};
  pos mid = dragoncurve(x, y, d, g-1);
  pos end = {mid.first - (mid.second - start.second), mid.second + (mid.first - start.first)};
  dragoncurve(end.first, end.second, (d + 3) % 4, g-1);
  return end;
}


int main()
{
  int cnt, x, y, d, g;
  int sqcnt = 0;

  cin >> cnt;

  for(int idx = 0; idx < cnt; idx++)
  {
    cin >> y >> x >> d >> g;
    dragoncurve(x, y, d, g);
  }

  for(int idx = 0; idx < 100; idx++)
  {
    for(int jdx = 0; jdx < 100; jdx++)
    {
      if(map[idx][jdx] & map[idx + 1][jdx] & map[idx][jdx + 1] & map[idx + 1][jdx + 1])
        sqcnt++;
    }
  }

  cout << sqcnt;
}
