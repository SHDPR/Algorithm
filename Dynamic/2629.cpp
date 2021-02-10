#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

int plumb[30];
int knapsack[30][40001];

int main()
{
  memset(knapsack, 0, sizeof(knapsack));

  int plumb_cnt, id_cnt;
  cin >> plumb_cnt;

  for(int idx = 0; idx < plumb_cnt; idx++)
    cin >> plumb[idx];

  knapsack[0][0] = 1;
  knapsack[0][plumb[0]] = 1;

  for(int idx = 1; idx < plumb_cnt; idx++)
  {
    knapsack[idx][0] = 1;
    for(int jdx = 0; jdx < 40001; jdx++)
    {
      if(knapsack[idx-1][jdx] == 1)
      {
        knapsack[idx][jdx] = 1;
        knapsack[idx][jdx + plumb[idx]] = 1;
        knapsack[idx][abs(jdx - plumb[idx])] = 1;
      }
    }
  }

  cin >> id_cnt;
  for(int idx = 0; idx < id_cnt; idx++)
  {
    if(idx != 0)
      cout << " ";
    int weight;
    cin >> weight;
    if(knapsack[plumb_cnt-1][weight] == 1)
      cout << "Y";
    else
      cout << "N";
  }

}
