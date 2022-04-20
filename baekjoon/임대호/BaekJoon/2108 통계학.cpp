#include <iostream>
#include <vector>

using namespace std;

void Mer____ge(int start, int mid, int end);
void Mege____Sort(int start, int end);

vector<int> v;
vector<int> _v;

int Åë°èÇĞ()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	v.resize(n);
	_v.resize(n);

	int sum = 0, average, min, max;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	average = round((sum / n * 10)) / 10;

	Mege____Sort(0, n - 1);
	min = v[0];
	max = v[v.size() - 1];

	cout << average << '\n';
	cout << v[(int)(n / 2)] << '\n';
	cout << 0 << '\n';
	cout << max - min;

	return 0;
}

void Mer____ge(int start, int mid, int end)
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

	else if (right > end)
		while (left <= mid)
			_v[index++] = v[left++];

	for (int i = start; i <= end; i++)
		v[i] = _v[i];
}

void Mege____Sort(int start, int end)
{
	if (start >= end) return;

	int mid = (start + end) / 2;

	Mege____Sort(start, mid);
	Mege____Sort(mid + 1, end);
	Mer____ge(start, mid, end);
}