#include <iostream>
using namespace std;


int count_han(int num){
    if(num < 100) return num;
    if(num == 1000) return count_han(num - 1);

    int a = num / 100;        //100th
    int b = (num % 100) / 10; //10th
    int c = (num % 10);       //1th

    int d = (a - 1) * 5;
    int e = b - ((a - 1) / 2 + 1);
    int f = 0;

    if(e < 0) e = 0;
    else if(e > 5) e = 5;
    else{
      f = (c >= (a % 2 + e * 2))? 1 : 0;
    }

    return 99 + d + e + f;
}

int main(){
  int N = -1;
  cin >> N;

  if(N > 1000 || N < 1){
    throw out_of_range("N value out of range");
  }

  cout << count_han(N) << endl;

}
