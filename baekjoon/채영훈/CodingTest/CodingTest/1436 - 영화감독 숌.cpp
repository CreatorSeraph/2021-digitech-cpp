#include <iostream>
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

using namespace std;

#define async_with_stdio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr auto nl = '\n';
constexpr auto sp = ' ';
constexpr auto tab = '\t';

bool Nums(int num, int target, int count)
{
	int combo = 0;
	while (num != 0)
	{
		if (target == num % 10)
			++combo;
		else
			combo = 0;
		if (combo == count)
			return true;
		num /= 10;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;

	// 3 -> 13 -> 23 -> 30 -> 31 ~ 39 -> 43 -> 53

	// 33 -> ╬ф юл ╬╬ bal ╡ц╧ч╟т гоющ╬ф

	int count = 0, i = 0;
	for (i = 0; i < 10000000; i++)
	{
		if (Nums(i, 6, 3)) ++count;
		if (count == N) break;
	}

	cout << i << "\n";

	return 0;
}