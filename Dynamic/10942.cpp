#include <iostream>
using namespace std;


int dp_search(int **pelin, int *seq, int start, int end)
{
  if(pelin[start][end] != -1)
    return pelin[start][end];

  if(start == end)
  {
    pelin[start][end] = 1;
    return pelin[start][end];
  }
  if(start + 1 == end)
  {
    pelin[start][end] = (seq[start] == seq[end])? 1 : 0;
    return pelin[start][end];
  }

  pelin[start][end] = (dp_search(pelin, seq, start + 1, end - 1) == 1 && seq[start] == seq[end])? 1 : 0;
  return pelin[start][end];
}

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;
  int *sequence;
  int **pelin;

  cin >> N;
  sequence = (int*)malloc(sizeof(int) * N);
  pelin = (int**)malloc(sizeof(int*) * N);

  for(int idx = 0; idx < N; idx++)
  {
    pelin[idx] = (int*)malloc(sizeof(int) * N);
    for(int jdx = 0; jdx < N; jdx++)
      pelin[idx][jdx] = -1;
  }

  for(int idx = 0; idx < N; idx++)
    cin >> sequence[idx];

  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = N-1; jdx >= idx; jdx--)
      dp_search(pelin, sequence, idx, jdx);
  }

  cin >> M;


  for(int idx = 0; idx < M; idx++)
  {
    int start, end;
    cin >> start >> end;
    cout << pelin[start-1][end-1] << '\n';
  }


  free(pelin);
  free(sequence);
}
