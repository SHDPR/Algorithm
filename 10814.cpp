#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

struct person{
  int age;
  char name[101];
};

int compare(person a, person b){
  return a.age < b.age;
}

int main(){
  int N = 0;
  int input_age;
  char input_name[101];
  cin >> N;


  struct person *arr = (struct person*)malloc(sizeof(struct person) * N);


  for(int idx = 0; idx < N; idx++){
    cin >> input_age >> input_name;
    struct person a;
    a.age = input_age;
    strcpy(a.name, input_name);
    // 구조체 선언시, 배열은 strcpy로 복사해주어야
    arr[idx] = a;
  }

  stable_sort(arr, arr + N, compare);

  for(int idx = 0; idx < N; idx++){
    cout << arr[idx].age << " " << arr[idx].name << '\n';
  }

  free(arr);

}
