#include <iostream>
using namespace std;

int main(){
    int num = 0;
    double input = 0;
    double max = 0;
    double sum = 0;

    cin >> num;
    double *arr = (double *)malloc(sizeof(double) * num);

    for(int i = 0; i < num; i++){
        cin >> input;
        arr[i] = input;
        max = (input > max)? input : max;
    }

    for(int i = 0; i < num; i++){
        arr[i] = (arr[i] / max) * 100;
        sum += arr[i];
    }

    cout << sum/(double)num << endl;

    free(arr);

}
