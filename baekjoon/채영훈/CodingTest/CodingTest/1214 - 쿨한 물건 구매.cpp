#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

using ll = long long;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

int main()
{
	async_with_stdio;

	int D, P, Q;

	cin >> D >> P >> Q;

	if ((P == 1 || Q == 1) || (D % P == 0 || D % Q == 0))
	{
		cout << D << nl;
		return 0;
	}

	int minV = 0;

	if (P - D % P > Q - D % Q) minV = Q * ceil(D / (Q * 1.0f));
	else minV = P * ceil(D / (P * 1.0f));

	// 여기서 P와 Q 둘다 활용해서 하는 경우가 나옴

	int N = ceil(D / (min(P, Q) * 1.0f));

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			int temp = P * i + Q * j;
			if (temp < minV && temp >= D)
			{
				minV = temp;
				continue;
			}
		}
	}

	cout << minV << nl;

	// 0,0 1,0 2,0 3,0 4,0
	//     1,1 2,1 3,1 4,1
	//         2,2 3,2 4,2
	//             3,3 4,3
	//                 4,4

	//  D P  Q
	// 37 9 17

	return 0;
}