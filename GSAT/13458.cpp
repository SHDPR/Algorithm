#include <iostream>
using namespace std;

int N;
int *applicant;
int B,C;

int main()
{
  cin >> N;
  applicant = (int*)malloc(sizeof(int) * N);
  long long cnt = N;

  for(int idx = 0; idx < N; idx++)
  {
    cin >> applicant[idx];
  }

  cin >> B >> C;

  for(int idx = 0; idx < N; idx++)
  {
    applicant[idx] -= B;

    if(applicant[idx] > 0)
    {
      cnt += (applicant[idx] - 1) / C + 1;
    }

  }

  cout << cnt;

}
