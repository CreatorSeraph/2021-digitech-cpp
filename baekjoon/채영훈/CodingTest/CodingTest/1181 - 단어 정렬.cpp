#include "stdafx.h"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<string> str(N);

	for (size_t i = 0; i < N; i++)
		cin >> str[i];

	stable_sort(str.begin(), str.end(), [](string op1, string op2)
		{
			return op1.size() < op2.size();
		});

	str.erase(unique(str.begin(), str.end()), str.end());

	string target;
	for (size_t i = 0; i < str.size(); i++)
	{
		target = str[i];
		int j = i - 1;

		for (; j >= 0 && target.size() == str[j].size(); j--)
		{
			for (size_t k = 0; k < target.size(); k++)
			{
				if (str[j][k] > target[k])
				{
					str[j + 1] = str[j];
					break;
				}
				else if (str[j][k] < target[k])
					goto EXIT;
			}
		}

		EXIT:

		str[j + 1] = target;
	}

	str.erase(unique(str.begin(), str.end()), str.end());

	for (size_t i = 0; i < str.size(); i++)
		cout << str[i] << "\n";

	return 0;
}