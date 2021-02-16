#include <iostream>
#include <algorithm>

using namespace std;

void apart_search(int **apt, int **visit, int N, int x, int y, int *cnt)
{
  (*cnt)++;
  visit[x][y] = 1;
  
  int move_y[4] = {1, 0, -1, 0};
  int move_x[4] = {0, 1, 0, -1};

  for(int idx = 0; idx < 4; idx++)
  {
    int next_x = move_x[idx] + x;
    int next_y = move_y[idx] + y;

    if(next_x == N || next_x == -1)
    continue;

    if(next_y == N || next_y == -1)
    continue;

    if(visit[next_x][next_y] == 0 && apt[next_x][next_y] == 1)
    apart_search(apt, visit, N, next_x, next_y, cnt);
  }
}



int main()
{
  int N;
  int **visit;
  int **apt;

  cin >> N;

  apt = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    char input[N];
    apt[idx] = (int*)malloc(sizeof(int) * N);
    cin >> input;
    for(int jdx = 0; jdx < N; jdx++)
    apt[idx][jdx] = (int)(input[jdx] - '0');
  }

  visit = (int**)malloc(sizeof(int*) * N);
  for(int idx = 0; idx < N; idx++)
  {
    visit[idx] = (int*)malloc(sizeof(int) * N);
    for(int jdx = 0; jdx < N; jdx++)
    visit[idx][jdx] = 0;
  }

  int case_cnt = 0;
  int *cnt;
  cnt = (int*)malloc(sizeof(int) * N * N);

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      if(visit[idx][jdx] == 0 && apt[idx][jdx] == 1)
      {
        int tmp = 0;
        apart_search(apt, visit, N, idx, jdx, &tmp);
        cnt[case_cnt++] = tmp;
      }
    }
  }

  sort(cnt, cnt + case_cnt);

  cout << case_cnt << '\n';
  for(int idx = 0; idx < case_cnt; idx++)
  cout << cnt[idx] << '\n';

  free(visit);
  free(apt);
  free(cnt);
}
