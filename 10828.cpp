#include <iostream>
#include <string>
#include <string.h>

using namespace std;
#define MAXSIZE 10000;

class Stack{
  private :
    int *storage;
    int ssize;
    int stop;
  public :
    Stack(){
      storage = (int*)malloc(sizeof(int) * 10000);
      ssize = 0;
      stop = -1;
    }
    Stack(int n){
      storage = (int*)malloc(sizeof(int) * n);
      ssize = 0;
      stop = -1;
    }
    void push(int X){
      storage[++stop] = X;
      ssize++;
    }
    void pop(){
      if(stop == -1)
        cout << -1 << '\n';
      else{
        cout << storage[stop] << '\n';
        stop--;
        ssize--;
      }
    }
    void size(){
      cout << ssize << '\n';
    }
    void empty(){
      if(stop == -1)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    void top(){
      if(stop == -1)
        cout << -1 << '\n';
      else{
        cout << storage[stop] << '\n';
      }
    }
};


int main(){
  int cmd_n = 0;
  int loop = 0;
  char cmd[10];
  int argument = 0;
  cin >> cmd_n;

  Stack st;

  while(loop++ < cmd_n){
    cin >> cmd;
    if(strcmp(cmd, "push") == 0){
      cin >> argument;
      st.push(argument);
    }
    else if(strcmp(cmd, "pop") == 0){
      st.pop();
    }
    else if(strcmp(cmd, "size") == 0){
      st.size();
    }
    else if(strcmp(cmd, "empty") == 0){
      st.empty();
    }
    else if(strcmp(cmd, "top") == 0){
      st.top();
    }
    else
      throw out_of_range("Inappropriate index");
  }
}
