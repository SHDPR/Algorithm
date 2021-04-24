#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> cod;

int nutri[10][10];
int add[10][10];

int N, M, K;
vector<int> treelist[10][10];
cod dir[8] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void ss()
{
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			int size = treelist[idx][jdx].size();

			if (size != 0)
			{
				sort(treelist[idx][jdx].begin(), treelist[idx][jdx].end());
				int nutri_add = 0;

				for (int kdx = 0; kdx < size; kdx++)
				{
					int age = treelist[idx][jdx][kdx];

					if (age <= nutri[idx][jdx])
					{
						nutri[idx][jdx] -= age;
						treelist[idx][jdx][kdx]++;
					}
					else
					{
						for (int mdx = kdx; mdx < size; mdx++)
						{
							nutri_add += (treelist[idx][jdx][mdx] / 2);
						}

						treelist[idx][jdx].erase(treelist[idx][jdx].begin() + kdx, treelist[idx][jdx].end());
						break;
					}

				}
				nutri[idx][jdx] += nutri_add;
			}
		}
	}
}


void fw()
{
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			int size = treelist[idx][jdx].size();

			if (size != 0)
			{
				for (int kdx = 0; kdx < size; kdx++)
				{
					int age = treelist[idx][jdx][kdx];

					if (age % 5 == 0)
					{
						for (int mdx = 0; mdx < 8; mdx++)
						{
							int new_idx = idx + dir[mdx].first;
							int new_jdx = jdx + dir[mdx].second;

							if (new_idx >= N || new_jdx >= N || new_idx < 0 || new_jdx < 0)
								continue;

							treelist[new_idx][new_jdx].push_back(1);
						}
					}
				}
			}

			nutri[idx][jdx] += add[idx][jdx];
		}
	}
}


int countree()
{
	int ret = 0;
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			ret += treelist[idx][jdx].size();
		}
	}

	return ret;

}



int main()
{


	cin >> N >> M >> K;

	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			treelist[idx][jdx] = vector<int>();
			cin >> add[idx][jdx];
			nutri[idx][jdx] = 5;
		}
	}

	for (int idx = 0; idx < M; idx++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		treelist[x-1][y-1].push_back(age);
	}


	for (int idx = 0; idx < K; idx++)
	{
		ss();
		fw();
	}

	cout << countree();
}
