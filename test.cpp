#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

struct person{
  int age;
  char name;
};

int compare(person a, person b){
  return a.age < b.age;
}

int main(){
  int N = 0;
  int input_age;
  char input_name;
  cin >> N;


  struct person *arr = (struct person*)malloc(sizeof(struct person) * N);


  for(int idx = 0; idx < N; idx++){
    cin >> input_age >> input_name;
    arr[idx] = person{input_age, input_name};
  }

  stable_sort(arr, arr + N, compare);

  for(int idx = 0; idx < N; idx++){
    cout << arr[idx].age << " " << arr[idx].name << '\n';
  }

  free(arr);

}
