#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


int compare(char a, char b){
  return (int)a > (int)b;
}


int main(){
  char input[11];

  cin >> input;

  sort(input, input + strlen(input), compare);
  cout << input;
}
