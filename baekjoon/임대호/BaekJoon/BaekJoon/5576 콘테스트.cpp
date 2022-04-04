#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int 콘테스트()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> vec_1(10);
	vector<int> vec_2(10);

	for (int i = 0; i < 10; i++)
	{
		cin >> vec_1[i];
	}

	for (int i = 0; i < 10; i++)
	{
		cin >> vec_2[i];
	}

	sort(vec_1.begin(), vec_1.end());
	sort(vec_2.begin(), vec_2.end());

	cout << vec_1[7] + vec_1[8] + vec_1[9] << ' ';
	cout << vec_2[7] + vec_2[8] + vec_2[9];
	
	return 0;
}