#include <algorithm>
#include <iostream>

using namespace std;
int n, m;

long long bSearch_히히(int left, int right, const int* heights) {
	long long height = 0;
	int mid = right / 2;

	while(left <= right) {
		long long ret = 0;
		for (int j = 0; j < n; j++) {
			if (heights[j] - mid > 0)
				ret += heights[j] - mid;
		}

		if (ret >= m) {
			height = mid;
			
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}

	return height;
}

int 나무자르기() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int max_ = 0;
	long long sum = 0;
	cin >> n >> m;

	int* heights = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
		if (max_ < heights[i])
			max_ = heights[i];

		sum += heights[i];
	}

	if (sum == m) {
		cout << 0;
		return 0;
	}

	cout << bSearch(0, max_, heights);

	return 0;
}