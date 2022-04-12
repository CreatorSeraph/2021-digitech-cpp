#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> str_vec;

int µèº¸Àâ¤»()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	string* arr1 = new string[N];
	string* arr2 = new string[M];

	map<string, string> _map;

	for (int i = 0; i < N; i++)
	{
		cin >> arr1[i];
		_map.insert(make_pair(arr1[i], arr1[i]));
	}
	for (int i = 0; i < M; i++)
	{
		cin >> arr2[i];

		if (_map.find(arr2[i]) != _map.end())
		{
			str_vec.push_back(arr2[i]);
		}
	}

	sort(str_vec.begin(), str_vec.end());

	cout << str_vec.size() << '\n';
	for (auto iter : str_vec)
	{
		cout << iter << '\n';
	}

	return 0;
}