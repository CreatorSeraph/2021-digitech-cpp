#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> v(3, pair<int, int>(0, 0));
	int count = 0, val = 0;

	//for (int i = -1; i < 2; i++)
	//{
	//	temp = N;
	//	count = 0;
	//	for (int j = 0; j < 4; j++)
	//	{
	//		val = sqrt(temp) + i;
	//		cout << i << tab << val << tab << "Before : " << temp << tab;
	//		temp -= pow(val, 2);
	//		cout << "After : " << temp << nl;
	//		count++;
	//		if (temp < 0)
	//		{
	//			count = 0;
	//			break;
	//		}
	//	}
	//	if (temp > 0)
	//		count = 0;
	//	v[i + 1] = count;
	//}

	v[0].first = v[1].first = v[2].first = N;

	for (int i = 0; i < 4; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (v[j + 1].first <= 0) break;
			val = sqrt(v[j + 1].first) + j;
			v[j + 1].first -= pow(val, 2);
			v[j + 1].second++;
		}
	}

	cout << tab << v[0].second << tab << v[1].second << tab << v[2].second << nl;

	return 0;
}