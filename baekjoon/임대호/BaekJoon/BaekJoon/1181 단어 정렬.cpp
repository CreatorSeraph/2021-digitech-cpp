#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> vec;

void M_Sort(vector<string> s_vec, int start, int end)
{
	if (s_vec.size() <= 1) return;

}

void Q_Sort(int start, int end)
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

	Q_Sort(0, vec.size() - 1);

	for (auto iter : vec)
	{
		cout << iter << '\n';
	}

	return 0;
}