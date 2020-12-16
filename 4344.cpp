#include <iostream>
using namespace std;

int main(){
  cout << fixed;
  cout.precision(3);
  int num_testcase = 0;
  int num_score = 0;
  int num_overav = 0;
  double average = 0;
  cin >> num_testcase;

  for(int i = 0; i < num_testcase; i++){
    cin >> num_score;

    double scores[num_score];
    average = 0;
    num_overav = 0;

    for(int j = 0; j < num_score; j++){
      cin >> scores[j];
      average += scores[j];
    }

    average /= num_score;

    for(int j = 0; j < num_score; j++){
      if(scores[j] > average)
        num_overav++;
    }
    cout << ((double)num_overav / (double)num_score) * 100 << "%" << endl;
  }
}
