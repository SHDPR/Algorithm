#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int op_count = 0, operation = 0;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int, vector<int>, less<int>> max_heap;
  cin >> op_count;

  for(int idx = 0; idx < op_count; idx++)
  {
    cin >> operation;
    if(max_heap.size() > min_heap.size())
      min_heap.push(operation);
    else
      max_heap.push(operation);

    if(!max_heap.empty() && !min_heap.empty())
    {
      int max_top = max_heap.top();
      int min_top = min_heap.top();

      if(max_top > min_top)
      {
        max_heap.pop();
        min_heap.pop();
        max_heap.push(min_top);
        min_heap.push(max_top);
      }

    }

    cout << max_heap.top() << '\n';
  }

}
