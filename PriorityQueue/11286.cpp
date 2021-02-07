#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Abs_compare
{
  public :
    bool operator()(int x, int y)
    {
      if(abs(x) == abs(y))
      {
        return x > y;
      }
      else
      {
        return abs(x) > abs(y);
      }
    }
};

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int op_count = 0, operation = 0;

  cin >> op_count;
  priority_queue<int, vector<int>, Abs_compare> abs_heap;

  for(int idx = 0; idx < op_count; idx++)
  {
    cin >> operation;
    if(operation == 0)
    {
      if(abs_heap.size() == 0)
      {
        cout << 0 << '\n';
      }
      else
      {
        cout << abs_heap.top() << '\n';
        abs_heap.pop();
      }
    }
    else
    {
      abs_heap.push(operation);
    }
  }


}
