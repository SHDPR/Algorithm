#include <iostream>
#include <algorithm>

using namespace std;

int find_lbidx(int seq[], int start, int end, int input, int pos){
	int mid = (start + end) / 2;
	if(input > seq[mid]){
		if(start >= end)
			return pos;
		return find_lbidx(seq, mid + 1, end, input, pos);
	}

	else{
		pos = mid;
		if(start >= end)
			return pos;
		return find_lbidx(seq, start, mid-1, input, pos);
	}
}


int main(){
	int N;										// N-> Size of sequence A
	int *seq;
	cin >> N;

	seq = (int*)malloc(sizeof(int) * N);

	int idx = 0, input = 0;
	seq[0] = 1000000;					// Temporary value for seq[0]

	for(int cnt = 0; cnt < N; cnt++){
		cin >> input;
		if(input > seq[idx])
			seq[++idx] = input;
		else{
			seq[find_lbidx(seq, 0, idx, input, 0)] = input;
		}
	}

	cout << idx + 1;
}
