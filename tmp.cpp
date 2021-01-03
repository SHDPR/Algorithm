//c++

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int first;
	int second;
}st;

int dp[102];
st line[102];

bool compare(st a, st b) {
	return a.first < b.first;
}

int main() {
	int n;
	int result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> line[i].first >> line[i].second;
	}
	sort(line, line + n + 1, compare);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		result = max(result, dp[i]);
	}
	cout << n - result;
}
