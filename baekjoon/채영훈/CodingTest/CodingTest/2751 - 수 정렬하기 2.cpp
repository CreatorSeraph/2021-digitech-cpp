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

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (size_t i = 0; i < N; i++)
		cin >> v[i];

	stable_sort(v.begin(), v.end());

	for (auto& iter : v)
		cout << iter << "\n";

	return 0;
}