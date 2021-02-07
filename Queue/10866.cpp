#include <iostream>
#include <string.h>
using namespace std;

class Deque{
  private :
    int *storage;
    int start;
    int end;
    int qsize;
    int dsize;

  public :
    Deque(int cmd_n){
      storage = (int*)malloc(sizeof(int) * cmd_n);
      start = 0;
      end = 0;
      qsize = cmd_n;
      dsize = 0;
    }
    void push_front(int X){
      int idx = (start + qsize - 1) % qsize;
      storage[idx] = X;
      start = idx;
      dsize++;
    }
    void push_back(int X){
      storage[end] = X;
      end = (end + 1) % qsize;
      dsize++;
    }
    void pop_front(){
      if(dsize == 0)
        cout << -1 << '\n';
      else{
        cout << storage[start] << '\n';
        start = (start + 1) % qsize;
        dsize--;
      }
    }
    void pop_back(){
      if(dsize == 0)
        cout << -1 << '\n';
      else{
        int idx = (end + qsize -1) % qsize;
        cout << storage[idx] << '\n';
        end = idx;
        dsize--;
      }
    }
    void size(){
      cout << dsize << '\n';
    }
    void empty(){
      if(dsize == 0)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    void front(){
      if(dsize == 0)
        cout << -1 << '\n';
      else
        cout << storage[start] << '\n';
    }
    void back(){
      if(dsize == 0)
        cout << -1 << '\n';
      else{
        int idx = (end + qsize - 1) % qsize;
        cout << storage[idx] << '\n';
      }
    }
};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cmd_n = 0;
	int loop = 0;
	char cmd[15];
	int argument = 0;
	cin >> cmd_n;

	Deque deque(cmd_n);

	while(loop++ < cmd_n){
    cin >> cmd;

    if(strcmp(cmd, "push_front") == 0){
      cin >> argument;
      deque.push_front(argument);
    }
    else if(strcmp(cmd, "push_back") == 0){
      cin >> argument;
      deque.push_back(argument);
    }
    else if(strcmp(cmd, "pop_front") == 0){
      deque.pop_front();
    }
    else if(strcmp(cmd, "pop_back") == 0){
      deque.pop_back();
    }
    else if(strcmp(cmd, "size") == 0){
      deque.size();
    }
    else if(strcmp(cmd, "empty") == 0){
      deque.empty();
    }
    else if(strcmp(cmd, "front") == 0){
      deque.front();
    }
    else if(strcmp(cmd, "back") == 0){
      deque.back();
    }
    else
      throw out_of_range("Inappropriate index");
  }
}
