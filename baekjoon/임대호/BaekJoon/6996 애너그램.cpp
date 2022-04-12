#include <iostream>
#include <vector>

using namespace std;
int 애너그램()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int sum_1 = 0;
	int sum_2 = 0;
	cin >> n;

	vector<string*> vec(n);

	for (int i = 0; i < n; i++)
	{
		vec[i] = new string[2];

		for (int j = 0; j < 2; j++)
		{
			cin >> vec[i][j];
		}

		for (int j = 0; j < vec[i][0].size(); j++)
			sum_1 += (int)(vec[i][0][j]);
		for (int j = 0; j < vec[i][1].size(); j++)
			sum_2 += (int)(vec[i][1][j]);

		if (sum_1 == sum_2)
			cout << vec[i][0] << " & " << vec[i][1] << " are anagrams.\n";
		else
			cout << vec[i][0] << " & " << vec[i][1] << " are NOT anagrams.\n";

		sum_1 = sum_2 = 0;
	}

	return 0;
}
