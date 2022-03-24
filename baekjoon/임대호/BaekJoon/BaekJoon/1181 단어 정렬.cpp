#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> vec;

void Sort(int start, int end)
{
	if (start > end) return;

	string temp;

	int pivot = start;
	int left = start;
	int right = end;

	while (left < right)
	{
		while ((vec[left].size() <= vec[pivot].size() &&
			(vec[left].size() != vec[pivot].size() && (vec[left] <= vec[pivot]))) && left < end) left++;
		while ((vec[right].size() >= vec[pivot].size() &&
			(vec[right].size() != vec[pivot].size() && (vec[right] <= vec[pivot]))) && right > start) right--;

		if (left < right)
		{
			temp = vec[left];
			vec[left] = vec[right];
			vec[right] = temp;
		}
	}

	temp = vec[right];
	vec[right] = vec[pivot];
	vec[pivot] = temp;

	Sort(start, pivot - 1);
	Sort(pivot + 1, end);
}

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

	Sort(0, vec.size() - 1);

	cout << '\n';

	for (auto iter : vec)
	{
		cout << iter << '\n';
	}

	return 0;
}