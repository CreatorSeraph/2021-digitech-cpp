#include <iostream>
#include <vector>

using namespace std;

int fill(vector<int>& vec_fill, vector<int>& vec, int index, int start, int end) {
	if (start >= end) {
		vec_fill[index] = vec[start];
		return vec_fill[index];
	}

	auto mid = (start + end) / 2;
	vec_fill[index] = min(fill(vec_fill, vec, index * 2, start, mid)
		,fill(vec_fill, vec, index * 2 + 1, mid + 1, end));

	return vec_fill[index];
}

int find(vector<int>& vec_fill, int index, int start, int end, int find_start, int find_end) {
	if (end < find_start || start > find_end) {
		return __INT_MAX__;
	}

	if (start >= find_start && end <= find_end) {
		return vec_fill[index];
	}

	auto mid = (start + end) / 2;
	return min(find(vec_fill, index * 2, start, mid, find_start, find_end)
	, find(vec_fill, index * 2 + 1, mid + 1, end, find_start, find_end));
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector<int> vec(n);
	vector vec_fill(n * 4, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	fill(vec_fill, vec, 1, 0, n - 1);

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << find(vec_fill, 1, 0, n - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}
