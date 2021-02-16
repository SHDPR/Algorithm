#include <iostream>
#include <memory.h>

using namespace std;

int search(int **mapping, int **route, int M, int N, int x, int y)
{
  int vect_x[4] = {1, 0, -1, 0};
  int vect_y[4] = {0, 1, 0, -1};

  if(x == M - 1 && y == N - 1)
    return 1;

  if(route[x][y] != -1)
    return route[x][y];
  else
    route[x][y] = 0;

  for(int idx = 0; idx < 4; idx++)
  {
    int nextX = x + vect_x[idx];
    int nextY = y + vect_y[idx];

    if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && mapping[nextX][nextY] < mapping[x][y])
    {
      route[x][y] += search(mapping, route, M, N, nextX, nextY);
    }
  }
  return route[x][y];
}

int main()
{
  int M, N;
  cin >> M >> N;

  int **mapping = (int**)malloc(sizeof(int*) * M);
  int **route = (int**)malloc(sizeof(int*) * M);

  for(int idx = 0; idx < M; idx++)
  {
    mapping[idx] = (int*)malloc(sizeof(int) * N);
    route[idx] = (int*)malloc(sizeof(int) * N);
    for(int jdx = 0; jdx < N; jdx++)
    {
      cin >> mapping[idx][jdx];
      route[idx][jdx] = -1;
    }
  }

  cout << search(mapping, route, M, N, 0, 0);

}
