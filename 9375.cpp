#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  int n = 0;
  cin >> n;

  for(int idx = 0; idx < n; idx++){
    map<string, int> m;
    int types = 0;
    int cases = 1;
    cin >> types;
    for(int jdx = 0; jdx < types; jdx++){
      string inputa, inputb;
      cin >> inputa >> inputb;
      if(m.find(inputb) == m.end())
        m[inputb] = 1;
      else
        m[inputb]++;
    }
    for(map<string, int>::iterator iter = m.begin(); iter!= m.end(); iter++){
      cases *= (iter->second + 1);
    }
    cout << cases-1 << '\n';
  }
}
