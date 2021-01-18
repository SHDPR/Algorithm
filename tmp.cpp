#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Queue{
	private :
		int *storage;
		int stidx;
		int edidx;
		int qsize;
	public :
		// Constructor
		Queue(int cmd_n){
			storage = (int*)malloc(sizeof(int) * cmd_n * 2);
			stidx = 0;
			edidx = 0;
			qsize = 0;
		}
		void push(int X){
			storage[edidx++] = X;
			qsize++;
		}
		void pop(){
			if(qsize == 0)
				cout << -1 << '\n';
			else{
				cout << storage[stidx] << '\n';
				stidx++;
				qsize--;
			}
		}
		void size(){
			cout << qsize << '\n';
		}
		void empty(){
			if(qsize == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		void front(){
			if(qsize == 0)
				cout << -1 << '\n';
			else
				cout << storage[stidx] << '\n';
		}
		void back(){
			if(qsize == 0)
				cout << -1 << '\n';
			else
				cout << storage[edidx-1] << '\n';
		}
};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cmd_n = 0;
	int loop = 0;
	char cmd[10];
	int argument = 0;
	cin >> cmd_n;

	Queue queue(cmd_n);

	while(loop++ < cmd_n){
    cin >> cmd;

    if(strcmp(cmd, "push") == 0){
      cin >> argument;
      queue.push(argument);
    }
    else if(strcmp(cmd, "pop") == 0){
      queue.pop();
    }
    else if(strcmp(cmd, "size") == 0){
      queue.size();
    }
    else if(strcmp(cmd, "empty") == 0){
      queue.empty();
    }
    else if(strcmp(cmd, "front") == 0){
      queue.front();
    }
    else if(strcmp(cmd, "back") == 0){
      queue.back();
    }
    else
      throw out_of_range("Inappropriate index");
  }
}
