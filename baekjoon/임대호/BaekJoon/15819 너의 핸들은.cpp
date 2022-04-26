#include <iostream>
#include <vector>
using namespace std;
vector<string> v;
vector<string> _v;

void Mer______ge(int start, int mid, int end);
void Merge______Sort(int start, int end);

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, i;
	cin >> n >> i;

	v.resize(n);
	_v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	Merge______Sort(0, n - 1);

	cout << v[i];

	return 0;
}

void Mer______ge(int start, int mid, int end)
{
	int index = start;
	int left = start;
	int right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (v[left] < v[right])
			_v[index] = v[left++];
		else
			_v[index] = v[right++];

		index++;
	}

	if (left > mid)
		while (right <= end)
			_v[index++] = v[right++];

	else
		while (left <= mid)
			_v[index++] = v[left++];

	for (int i = start; i <= end; i++)
		v[i] = _v[i];
 }

void Merge______Sort(int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;

	Merge______Sort(start, mid);
	Merge______Sort(mid + 1, end);
	Mer______ge(start, mid, end);
}