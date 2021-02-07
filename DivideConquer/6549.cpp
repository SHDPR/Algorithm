#include <iostream>
using namespace std;

typedef long long ll;

int min(const int& a, const int& b, int height[]){
  if(a == -1)
    return b;
  if(b == -1)
    return a;
  return (height[a] > height[b])? b : a;
}

ll max(const ll& a, const ll& b){
  return (a > b)? a : b;
}

ll max(const ll& a, const ll& b, const ll& c){
  return max(max(a, b), c);
}


int init_tree(int height[], int segmnt[], int start, int end, int node){
  // If we met leaf node
  if(start == end)
    return segmnt[node] = start;

  int mid = (start + end) / 2;
  return segmnt[node] = min(init_tree(height, segmnt, start, mid, node * 2 + 1),
                            init_tree(height, segmnt, mid + 1, end, node * 2 + 2), height);
}

// start, end -> range info of current node
// S, E       -> range info that we want to know
int sum_tree(int segmnt[], int height[], int start, int end, int node, int S, int E){
  if(S > end || E < start)
    return -1;

  if(S <= start && end <= E)
    return segmnt[node];

  int mid = (start + end) / 2;
  return min(sum_tree(segmnt, height, start, mid, node * 2 + 1, S, E),
             sum_tree(segmnt, height, mid + 1, end, node * 2 + 2, S, E), height);
}


ll search(int segmnt[], int height[], int start, int end, const int &N){
  int temp = sum_tree(segmnt, height, 0, N-1, 0, start, end);

  ll area = height[temp] * (end - start + 1);

  if(start == end)
    return height[start];

  if(temp == start)
    return max(area, search(segmnt, height, start + 1, end, N));

  if(temp == end)
    return max(area, search(segmnt, height, start, end - 1, N));

  return max(area, search(segmnt, height, start, temp - 1, N),
                   search(segmnt, height, temp + 1, end, N));
}



int main(){
  int N = -1;
  while(1){
    cin >> N;
    int *height = (int*)malloc(sizeof(int) * N);
    int *segmnt = (int*)malloc(sizeof(int) * N * 4);

    if(N == 0) return 0;

    for(int idx = 0; idx < N; idx++)
      cin >> height[idx];

    init_tree(height, segmnt, 0, N-1, 0);


    cout << search(segmnt, height, 0, N-1, N) << '\n';

    free(height);
    free(segmnt);
  }
}
