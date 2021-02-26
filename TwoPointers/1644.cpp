#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> eratos(N+1, 1);
  eratos[1] = 0;

  for(int idx = 2; idx <= sqrt(N); idx++)
  {
    if(eratos[idx] == 0)
      continue;
    for(int jdx = 2; jdx * idx <= N; jdx++)
      eratos[idx * jdx] = 0;
  }

  vector<int> prime;

  for(int idx = 1; idx < N+1; idx++)
  {
    if(eratos[idx] == 1)
      prime.push_back(idx);
  }

  int len = prime.size();

  if(len == 0)
  {
    cout << 0;
    return 0;
  }


  int start = 0;
  int end = 0;
  int sum = prime[0];
  int count = 0;

  while(start < len)
  {
    if(sum == N)
      count++;

    if(sum >= N || end == len-1)
      sum -= prime[start++];

    else
      sum += prime[++end];
  }

  cout << count;


}
