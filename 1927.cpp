#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int op_count = 0;
  int op = 0;
  cin >> op_count;

  priority_queue<int, vector<int>, greater<int>> min_heap;

  for(int idx = 0; idx < op_count; idx++)
  {
      cin >> op;
      if(op == 0)
      {
        if(min_heap.size() == 0)
          cout << 0 << '\n';
        else
        {
          cout << min_heap.top() << '\n';
          min_heap.pop();
        }
      }
        else
        {
          min_heap.push(op);
        }
    }
}
