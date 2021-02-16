#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void map_search(int **map, int **visit, int **count, int N, int M)
{
  queue<pair<int, int>> waitlist;

  pair<int, int> start = {0, 0};
  waitlist.push(start);
  visit[0][0] = 1;

  int step_x[4] = {0, 1, 0, -1};
  int step_y[4] = {1, 0, -1, 0};

  while(!waitlist.empty())
  {
    int x = waitlist.front().first;
    int y = waitlist.front().second;

    waitlist.pop();

    for(int idx = 0; idx < 4; idx++)
    {
      int next_x = x + step_x[idx];
      int next_y = y + step_y[idx];

      if(next_x == N || next_x == -1)
        continue;

      if(next_y == M || next_y == -1)
        continue;

      if(visit[next_x][next_y] == 0 && map[next_x][next_y] == 1)
      {
        count[next_x][next_y] = count[x][y] + 1;
        waitlist.push({next_x, next_y});
        visit[next_x][next_y] = 1;
      }
    }
  }
}



int main()
{
  int N, M;
  int **visit;
  int **map;
  int **count;

  cin >> N >> M;

  map = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    char input[M];
    map[idx] = (int*)malloc(sizeof(int) * M);
    cin >> input;
    for(int jdx = 0; jdx < M; jdx++)
      map[idx][jdx] = (int)(input[jdx] - '0');
  }

  visit = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    visit[idx] = (int*)malloc(sizeof(int) * M);
    for(int jdx = 0; jdx < M; jdx++)
      visit[idx][jdx] = 0;
  }

  count = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    count[idx] = (int*)malloc(sizeof(int) * M);
    for(int jdx = 0; jdx < M; jdx++)
      count[idx][jdx] = 0;
  }


  int min = N * M;

  map_search(map, visit, count, N, M);

  cout << count[N-1][M-1] + 1;

  free(visit);
  free(map);
  free(count);
}
