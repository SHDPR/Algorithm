#include <iostream>
#include <queue>

using namespace std;
#define MAX_ELEMENT 100000


class Maxheap
{
  private :
    int *heap;
    int heap_size;
  public :
    Maxheap()
    {
      heap = (int*)malloc(sizeof(int) * MAX_ELEMENT);
      heap_size = 0;
    }
    Maxheap(int n)
    {
      heap = (int*)malloc(sizeof(int) * n);
      heap_size = 0;
    }
    void insert(int x)
    {
      int idx = heap_size++;

      while((idx != 0) && (x > heap[(idx - 1) / 2]))
      {
          heap[idx] = heap[(idx - 1) / 2];
          idx = (idx - 1) / 2;
      }

      heap[idx] = x;
    }
    int remove(void)
    {
      if(heap_size == 0)
        return 0;

      int removed = heap[0];
      int temp = heap[(heap_size--) - 1];
      int parent = 0;
      int child = 1;

      while(child < heap_size)
      {
        if((child < heap_size - 1) && heap[child] < heap[child + 1])
          child++;

        if(temp >= heap[child])
          break;

        heap[parent] = heap[child];
        parent = child;
        child = child * 2 + 1;
      }
      heap[parent] = temp;
      return removed;
    }
};


int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int op_count = 0;
  int op = 0;
  cin >> op_count;

  priority_queue<int> max_heap;
  //Maxheap heap(op_count);


  for(int idx = 0; idx < op_count; idx++)
  {
      cin >> op;
      if(op == 0)
      {
        //cout << heap.remove() << '\n';
        if(max_heap.size() == 0)
          cout << 0 << '\n';
        else
        {
          cout << max_heap.top() << '\n';
          max_heap.pop();  
        }
      }
        else
        {
          //heap.insert(op);
          max_heap.push(op);
        }
    }
}
