#include <iostream>
#include <stack>

using namespace std;

int Á¦·Î()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	stack<int> s;

	int n, temp, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp != 0)
		{
			s.push(temp);
		}
		else
		{
			s.pop();
		}
	}

	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}