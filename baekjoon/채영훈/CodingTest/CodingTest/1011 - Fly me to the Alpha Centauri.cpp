#include <iostream>
#include <cmath>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	async_with_stdio;

	int T, x, y;
	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		cin >> x >> y;
		int dis = y - x;
		int center = floor(sqrt(dis));
		int move = center * 2 - 1;
		int sub = dis - center * center;
		if (sub != 0)
			if (sub <= center) move++;
			else move += 2;
		cout << move << nl;
	}

	return 0;
}