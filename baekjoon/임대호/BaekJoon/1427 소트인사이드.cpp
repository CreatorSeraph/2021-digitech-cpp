#include <iostream>
#include <algorithm>

using namespace std;
int 소트인사이드()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	sort(s.begin(), s.end(), [&](int a, int b)->bool {return a > b; });

	cout << s;

	return 0;
}