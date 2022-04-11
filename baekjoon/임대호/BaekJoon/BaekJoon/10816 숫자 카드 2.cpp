#include <iostream>
#include <vector>

using namespace std;

int 숫자카드2()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> vec(20000000, 0);

	int n1, n2, temp;

	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> temp;
		vec[temp + 10000000] ++;
	}

	cin >> n2;

	for (int i = 0; i < n2; i++)
	{
		cin >> temp;
		cout << vec[temp + 10000000] << ' ';
	}

	return 0;
}