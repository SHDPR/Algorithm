#include <iostream>
#include <string>

using namespace std;

int main(){
    int num, input;
    cin >> num;

    int max = -1e6;
    int min = 1e6;

    for(int idx = 0; idx < num; idx++)
        cin >> input;
        max = (max > input)? max : input;
        min = (min < input)? min : input;
    }
    cout << min << ' ' << max << endl;
}
