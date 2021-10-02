#include <iostream>
#include <string>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';

int main()
{
	string S, P;
	int T, R;

	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		cin >> R >> S;

		for (auto&& iter : S)
		{
			for (size_t i = 0; i < R; ++i)
			{
				P += iter;
			}
		}

		cout << P << nl;
		P = "";
	}

	return 0;
}