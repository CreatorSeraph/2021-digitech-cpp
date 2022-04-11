#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> vec;

void M_Sort(int start, int end)
{
	vector<string> _vec(vec.size());
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	int index = start;

	while (left <= mid && right <= end)
	{
		if (vec[left].size() < vec[right].size())
			_vec[index] = vec[left++];
		else
		{
			if (vec[left].size() == vec[right].size())
			{
				if (vec[left] > vec[right]) _vec[index] = vec[right++];
				else _vec[index] = vec[left++];
			}
			else
			_vec[index] = vec[right++];
		}

		index++;
	}

	if (left > mid)
		while (right <= end)
			_vec[index++] = vec[right++];

	if (right > end)
		while (left <= mid)
			_vec[index++] = vec[left++];

	for (int i = start; i <= end; i++)
		vec[i] = _vec[i];
}

void MergeSort(int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;

	MergeSort(start, mid);
	MergeSort(mid + 1, end);
	M_Sort(start, end);
}

int 단어정렬()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	map<string, string> map;

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;

		if (map.find(s) == map.end())
		{
			vec.push_back(s);
			map.insert(make_pair(s, s));
		}
	}

	MergeSort(0, vec.size() - 1);

	for (auto iter : vec)
	{
		cout << iter << '\n';
	}

	return 0;
}