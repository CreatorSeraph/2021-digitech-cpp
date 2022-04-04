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

/* void Q_Sort(int start, int end)
{
	if (start >= end) return;

	int left = start;
	int right = end;
	int pivot = start;

	string temp;

	while (left < right)
	{
		while (left < right && vec[right].size() >= vec[left].size())
		{
			if (vec[right].size() == vec[left].size() && vec[right] < vec[left])
			{
				temp = vec[right];
				vec[right] = vec[left];
				vec[left] = temp;
			}
			else
				left++;
		}
		while (right > left && vec[left].size() <= vec[right].size())
		{
			if (vec[left].size() == vec[right].size() && vec[left] > vec[right])
			{
				temp = vec[left];
				vec[left] = vec[right];
				vec[right] = temp;
			}
			else
				right--;
		}

		if (left < right)
		{
			temp = vec[right];
			vec[right] = vec[left];
			vec[left] = temp;
		}
	}
	temp = vec[right];
	vec[right] = vec[left];
	vec[left] = temp;

	Q_Sort(start, right - 1);
	Q_Sort(right + 1, end);
}
*/

int main()
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