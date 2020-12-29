#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

void formula(int cnt, int M, int *max_sum, int *min_sum, int result, int number[], int op[]){
	if(cnt == M){
		*max_sum = max(*max_sum, result);
		*min_sum = min(*min_sum, result);
		return;
	}

	for(int idx = 0; idx < 4; idx++){
		if(op[idx] != 0){
			op[idx]--;
			switch(idx){
				case 0 :
					formula(cnt+1, M, max_sum, min_sum, result + number[cnt+1], number, op);
					break;
				case 1 :
					formula(cnt+1, M, max_sum, min_sum, result - number[cnt+1], number, op);
					break;
				case 2 :
					formula(cnt+1, M, max_sum, min_sum, result * number[cnt+1], number, op);
					break;
				case 3 :
					formula(cnt+1, M, max_sum, min_sum, result / number[cnt+1], number, op);
					break;
				default :
					break;
			}

			op[idx]++;
		}
	}

}

int main(){
  int N;
  cin >> N;

	int number[N];
  for(int idx = 0; idx < N; idx++){
    cin >> number[idx];
  }

	int op[4];
  for(int idx = 0; idx < 4; idx++){
    cin >> op[idx];
  }

	int max_sum = INT_MIN;
	int min_sum = INT_MAX;

  formula(0, N-1, &max_sum, &min_sum, number[0], number, op);

  cout << max_sum << '\n' << min_sum;

}
