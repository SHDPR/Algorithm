#include <iostream>
#include <algorithm>

using namespace std;

int find_ubidx(int seq[], int start, int end, int input, int pos){
	int mid = (start + end) / 2;
	if(input >= seq[mid]){
		pos = mid;
		if(start >= end)
			return pos;
		return find_ubidx(seq, mid + 1, end, input, pos);
	}

	else{
		if(start >= end)
			return pos;
		return find_ubidx(seq, start, mid-1, input, pos);
	}
}


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
	int N;
	cin >> N;
	int seq[N];

	for(int idx = 0; idx < N; idx++)
		cin >> seq[idx];

	for(int idx = 0; idx < N; idx++){
		int input;
		cin >> input;
		cout << find_lbidx(seq, 0, N-1, input, 0);
	}


}
