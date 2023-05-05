#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> path;
vector<vector<int>> cost;

void FloydWarshall() {
	int size = path.size();
	
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			for (int k = 1; k <= size; k++) {
				if (j == i || i == k)
					continue;
				
				if (cost[j][k] > cost[j][i] + cost[i][k]) {
					path[j][k] = path[i][k];

					cost[j][k] = cost[j][i] + cost[i][k];
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	int n, m, k;
	int a, b, c;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		path = vector<vector<int>>(n + 1, vector<int>(n + 1));
		cost = vector<vector<int>>(n + 1, vector<int>(n + 1, 1000));

		for (int j = 0; j < m; j++) {
			cin >> a >> b >> c;

			path[a][b] = a;
			path[b][a] = b;
			
			cost[a][b] = c;
			cost[b][a] = c;
		}

		FloydWarshall();

		cin >> k;
		int* arr = new int[k];
		for (int j = 0; j < k; j++)
			cin >> arr[j];

		int* sum = new int[n];
		int min = 2147483647;
		list<int> minList;

		for (int j = n; j >= 1; j--) {
			for (int l = 0; l < k; l++) {
				sum[j] += cost[arr[l]][j];
			}

			if (sum[j] < min) {
				min = sum[j];
				minList.clear();
				minList.push_back(j);
			} else if (sum[j] == min) {
				minList.push_back(j);
			}
		}

		int index = 2147483647;
		for (const auto j : minList)
			if (j < index)
				index = j;
		
		cout << index << '\n';
	}

	return 0;
}