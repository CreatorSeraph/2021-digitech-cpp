#include <iostream>
#include <stack>
using namespace std;
int °ýÈ£()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string str;

	for (int i = 0; i < n; i++)
	{
		stack<int> left_s;

		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
				left_s.push(1);
			else
			{
				if (left_s.size() == 0)
				{
					cout << "NO" << '\n';
					break;
				}
				else
				{
					left_s.pop();
				}
			}

			if (j == str.size() - 1)
			{
				if (left_s.size() == 0)
					cout << "YES" << '\n';
				else
					cout << "NO" << '\n';
			}
		}
	}

	return 0;
}