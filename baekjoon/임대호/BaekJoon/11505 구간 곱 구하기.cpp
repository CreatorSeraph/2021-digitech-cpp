#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll fill(vector<ll>& vec_fill, vector<ll>& vec, int index, int start, int end) {
	if (start >= end) {
		vec_fill[index] = vec[start];
		return vec_fill[index];
	}

	auto mid = (start + end) / 2;
	vec_fill[index] = fill(vec_fill, vec, index * 2, start, mid)
		+ fill(vec_fill, vec, index * 2 + 1, mid + 1, end);

	return vec_fill[index];
}

ll replace(vector<ll>& vec_fill, vector<ll>& vec, int index, int start, int end, int replace_index, ll replace_value) {
	if (start == replace_index && end == replace_index) {
		vec[start] = replace_value;
		vec_fill[index] = vec[start];
		return vec_fill[index];
	}

	if (end < replace_index || start > replace_index) {
		return vec_fill[index];
	}

	if (start >= end) {
		return vec_fill[index];
	}

	auto mid = (start + end) / 2;
	vec_fill[index] = replace(vec_fill, vec, index * 2, start, mid, replace_index, replace_value)
		+ replace(vec_fill, vec, index * 2 + 1, mid + 1, end, replace_index, replace_value);

	return vec_fill[index];
}

ll find(vector<ll>& vec_fill, int index, int start, int end, int find_start, int find_end) {
	if (end < find_start || start > find_end) {
		return 0;
	}

	if (start >= find_start && end <= find_end) {
		return vec_fill[index];
	}

	auto mid = (start + end) / 2;
	return find(vec_fill, index * 2, start, mid, find_start, find_end)
		+ find(vec_fill, index * 2 + 1, mid + 1, end, find_start, find_end);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, k;

	cin >> n >> m >> k;

	vector<ll> vec(n);
	vector<ll> vec_fill(n * 4, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int a, b;
	ll c;
	auto filled = false;

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			if (!filled)
				vec[b - 1] = c;
			else
				replace(vec_fill, vec, 1, 0, n - 1, b - 1, c);
		} else if (a == 2) {
			if (!filled) {
				fill(vec_fill, vec, 1, 0, n - 1);
				filled = true;
			}
			cout << find(vec_fill, 1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}
