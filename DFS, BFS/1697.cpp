#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 100001

using namespace std;



int main()
{
  int N, K;
  cin >> N >> K;

  int visit[MAX];

  memset(visit, 0, sizeof(visit));

  queue<int> search;

  search.push(N);
  visit[N] = 1;

  while(!search.empty())
  {
    int x = search.front();
    search.pop();

    int move[2] = {1, -1};

    for(int idx = 0; idx < 2; idx++)
    {
      int next_x = x + move[idx];

      if(next_x == MAX || next_x == -1)
        continue;

      if(visit[next_x] == 0)
      {
        search.push(next_x);
        visit[next_x] = visit[x] + 1;
      }
    }

    int next_x = x * 2;

    if(next_x < MAX && visit[next_x] == 0)
    {
      search.push(next_x);
      visit[next_x] = visit[x] + 1;
    }
  }

  cout << visit[K] - 1;

}
