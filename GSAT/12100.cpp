#include <iostream>
#include <deque>
using namespace std;

int N;
int K;
int L;

// r_l = 1 : right, r_l = -1 : left
pair<int, int> direction[100];

pair<int, int> moveto[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int state;

bool snake[100][100] = {false, };
bool apple[100][100] = {false, };

int main()
{
  cin >> N;
  cin >> K;

  for(int idx = 0; idx < K; idx++)
  {
    int x, y;
    cin >> x >> y;
    apple[x-1][y-1] = true;
  }

  cin >> L;
  for(int idx = 0; idx < L; idx++)
  {
    int sec;
    int r_l;
    char dir;
    cin >> sec >> dir;

    if(dir == 'D') r_l = 1;
    else  r_l = -1;

    direction[idx] = {sec, r_l};
  }



  state = 0;
  snake[0][0] = true;

  deque<pair<int, int>> baam;

  baam.push_front({0,0});


  for(int idx = 1; ;idx++)
  {
    pair<int, int> head = baam.front();

    pair<int, int> plus = moveto[state];

    if(head.first + plus.first >= N || head.second + plus.second >= N || head.first + plus.first < 0 || head.second + plus.second < 0)
    {
      cout << idx;
      return 0;
    }

    if(snake[head.first + plus.first][head.second + plus.second] == true)
    {
      cout << idx;
      return 0;
    }

    snake[head.first + plus.first][head.second + plus.second] = true;
    baam.push_front({head.first + plus.first, head.second + plus.second});

    if(apple[head.first + plus.first][head.second + plus.second] == true)
    {
      apple[head.first + plus.first][head.second + plus.second] = false;
    }
    else
    {
      pair<int, int> tail = baam.back();
      baam.pop_back();
      snake[tail.first][tail.second] = false;
    }

    for(int jdx = 0; jdx < L; jdx++)
    {
      if(idx < direction[jdx].first)
        break;
      if(idx == direction[jdx].first)
      {
        if(direction[jdx].second == 1)
        {
          state += 1;
          if(state == 4)
            state = 0;
        }
        else
        {
          state -= 1;
          if(state == -1)
            state = 3;
        }
      }
    }

  }
}
